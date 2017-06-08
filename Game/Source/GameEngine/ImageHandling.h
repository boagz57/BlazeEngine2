#pragma once
#include "GLTexture.h"

namespace Blz
{
	namespace OpenGL 
	{
		//Load image into GPU and return a handle to the texture
		GLTexture LoadImageToGPU(Blz::string& filePath);
	}
}