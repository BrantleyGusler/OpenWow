#pragma once

#define COLOR_TEXTURE_UNIT              GL_TEXTURE0
#define COLOR_TEXTURE_UNIT_INDEX        0

#define SHADOW_TEXTURE_UNIT             GL_TEXTURE1
#define SHADOW_TEXTURE_UNIT_INDEX       1

#define NORMAL_TEXTURE_UNIT             GL_TEXTURE2
#define NORMAL_TEXTURE_UNIT_INDEX       2

#define RANDOM_TEXTURE_UNIT             GL_TEXTURE3
#define RANDOM_TEXTURE_UNIT_INDEX       3

#define DISPLACEMENT_TEXTURE_UNIT       GL_TEXTURE4
#define DISPLACEMENT_TEXTURE_UNIT_INDEX 4

#define SPECULAR_TEXTURE_UNIT           GL_TEXTURE5
#define SPECULAR_TEXTURE_UNIT_INDEX     5

class GBuffer
{
public:
	enum GBUFFER_TEXTURE_TYPE
	{
		GBUFFER_TEXTURE_TYPE_POSITION = 0,              // vec3
		GBUFFER_TEXTURE_TYPE_NORMAL = 1,                // vec3              
		GBUFFER_TEXTURE_TYPE_DIFFUSE = 2,
		GBUFFER_TEXTURE_TYPE_SPECULAR = 3,
	};

	bool Init();
	
	void Clear();
	void Clear2();
	void ClearFinalBuffer();

	void BindForGeomPass();
	void BindForGeomPass2();
	void BindForLightPass();

public:
	GLuint gBuffer;

	GLuint textures[4];
	GLuint depthTexture;

	uint32 rb;
	uint32 rb2;

	uint32 resultRB;
};