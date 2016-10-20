#pragma once
#ifndef __HelloCircleNative__main__
#define __HelloCircleNative__main__

#include <stdio.h>
#ifdef __ANDROID__
#include <GLES/gl.h>
#elif __APPLE__
#include <OpenGLES/ES1/gl.h>
#endif


class Circle
{
public:
	Circle();
	~Circle();
	void circle_setupGL(double width, double height);
	void circle_tearDownGL();
	void circle_update();
	void circle_prepare();
	void circle_draw();
};


#endif /* defined(__HelloCicleNative__main__) */
