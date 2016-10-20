#pragma once
#ifndef __HelloSDNCubeNative__main__
#define __HelloSDNCubeNative__main__

#include <stdio.h>
#ifdef __ANDROID__
#include <GLES/gl.h>
#elif __APPLE__
#include <OpenGLES/ES1/gl.h>
#endif

class SDNCube
{
public:
	void Cube_setupGL(double width, double height);
	void Cube_tearDownGL();
	void Cube_update();
	void Cube_prepare();
	void Cube_draw();

	SDNCube();
	~SDNCube();
};







#endif /* defined(__HelloSDNCubeNative__main__) */