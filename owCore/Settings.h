#pragma once

#define ADD_SETTING(_type, name, _default) \
public:\
 _type Get_##name##() const { \
return m_##name; \
}\
\
 void Set_##name##(_type _value)\
{\
m_##name = _value;\
}\
private:\
_type m_##name;\
\
const static _type Default_##name = _default;


class Settings
{
	CLASS_INSTANCE(Settings);

	Settings();

	inline void CalculateSquareDistances()
	{
		highresdistance2 = highresdistance * highresdistance;
		mapdrawdistance2 = mapdrawdistance * mapdrawdistance;
		modeldrawdistance2 = modeldrawdistance * modeldrawdistance;
		doodaddrawdistance2 = doodaddrawdistance * doodaddrawdistance;
		culldistance2 = culldistance * culldistance;
	}

	inline void CalculateAspectFactor()
	{
		aspectFactor = 1.0f;
		aspectRatio = windowSizeX / windowSizeY;
		if (aspectRatio >= 1.0f)
		{
			aspectFactor = aspectRatio;
		}
	}

	inline void SetWindowSize(uint32_t _x, uint32_t _y) { windowSizeX = _x; windowSizeY = _y; CalculateAspectFactor(); }
	inline vec2 GetWindowSize() const { return vec2(windowSizeX, windowSizeY); }

	//

public:
	// Render settings
	float windowSizeX;
	float windowSizeY;
	float aspectRatio, aspectFactor;

	// Distances
	float mapdrawdistance, modeldrawdistance, doodaddrawdistance, highresdistance, culldistance;
	float mapdrawdistance2, modeldrawdistance2, doodaddrawdistance2, highresdistance2, culldistance2;
	float fogdistance;

	// Drawing
	bool draw_map_chunk;
	bool draw_map_wmo;
	bool draw_map_wmo_doodads;
	bool draw_map_mdx;

	bool useOldMDXShader;
	
	bool lighting;

	bool loading;
	bool drawhighres;
	bool drawfog;
	bool drawColors;

	// Quality
	bool uselowlod;
	bool useshaders;


	bool enableMCCV;
	bool enableMCLV;



	// Perfomance
	bool disable_pipeline;
};

#define _Settings Settings::instance()