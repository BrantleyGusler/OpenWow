﻿#pragma once

#ifdef USE_M2_MODELS

struct ADT_MDXDef
{
	uint32 nameIndex;
	uint32 uniqueId;
	vec3 position;
	vec3 rotation;
	uint16 scale;
    struct
    {
        uint16 Flag_Biodome : 1;
        uint16 Flag_Shrubbery : 1;
        uint16 : 14;
    } flags;
};

class CMapM2Instance 
	: public CM2_Base_Instance
{
public:
	CMapM2Instance(std::string _m2Name);
	virtual ~CMapM2Instance();

	void Initialize() override;

    void Initialize(const ADT_MDXDef& _placementInfo);

	// ISceneNode
	bool Accept(IVisitor* visitor) override;

	void OnUpdate(UpdateEventArgs& e) override;

public: 
	uint32				m_UniqueId;

public:	// Static
	static void reset();
private:
	static std::set<uint32> m_AlreadyDraw;
};

#endif