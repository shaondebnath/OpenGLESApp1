#include "Cube.h"

float _rotation;

/*static GLint vertices[][3] =
{
    { -0x10000, -0x10000, -0x10000 },
    { 0x10000, -0x10000, -0x10000 },
    { 0x10000,  0x10000, -0x10000 },
    { -0x10000,  0x10000, -0x10000 },
    { -0x10000, -0x10000,  0x10000 },
    { 0x10000, -0x10000,  0x10000 },
    { 0x10000,  0x10000,  0x10000 },
    { -0x10000,  0x10000,  0x10000 }
};*/
static GLint vertices[][3] =
{
	{ -65536, -65536, -65536 },
	{ 65536, -65536, -65536 },
	{ 65536,  65536, -65536 },
	{ -65536,  65536, -65536 },
	{ -65536, -65536,  65536 },
	{ 65536, -65536,  65536 },
	{ 65536,  65536,  65536 },
	{ -65536,  65536,  65536 }
};

/*static GLint colors[][4] =
{
    { 0x00000, 0x00000, 0x00000, 0x10000 },
    { 0x10000, 0x00000, 0x00000, 0x10000 },
    { 0x10000, 0x10000, 0x00000, 0x10000 },
    { 0x00000, 0x10000, 0x00000, 0x10000 },
    { 0x00000, 0x00000, 0x10000, 0x10000 },
    { 0x10000, 0x00000, 0x10000, 0x10000 },
    { 0x10000, 0x10000, 0x10000, 0x10000 },
    { 0x00000, 0x10000, 0x10000, 0x10000 }
};*/
static GLint colors[][4] =
{
	{ 0, 0, 0, 65536 },
	{ 65536, 0, 0, 65536 },
	{ 65536, 65536, 0, 65536 },
	{ 0, 65536, 0, 65536 },
	{ 0, 0, 65536, 65536 },
	{ 65536, 0, 65536, 65536 },
	{ 65536, 65536, 65536, 65536 },
	{ 0, 65536, 65536, 65536 }
};

GLubyte indices[] =
{
    0, 4, 5,    0, 5, 1,
    1, 5, 6,    1, 6, 2,
    2, 6, 7,    2, 7, 3,
    3, 7, 4,    3, 4, 0,
    4, 7, 6,    4, 6, 5,
    3, 0, 1,    3, 1, 2
};

void Cube_setupGL(double width, double height)
{
    // Initialize GL state.
    glDisable(GL_DITHER);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    glClearColor(1.0f, 0.41f, 0.71f, 1.0f);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, width, height);
    GLfloat ratio = (GLfloat)width / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustumf(-ratio, ratio, -1, 1, 1, 10);
}

void Cube_tearDownGL()
{
}

void Cube_update()
{
    _rotation += 1.f;

}
void Cube_prepare()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Cube_draw()
{
  /*  glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -3.0f);
    glRotatef(_rotation * 0.25f, 1, 0, 0);  // X
    glRotatef(_rotation, 0, 1, 0);          // Y

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glFrontFace(GL_CW);
    glVertexPointer(3, GL_FIXED, 0, vertices);
    glColorPointer(4, GL_FIXED, 0, colors);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -6.0f);
	glRotatef(_rotation * 0.25f, 1, 0, 0);  // X
	glRotatef(_rotation, 0, 1, 0);          // Y

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FIXED, 0, vertices);
	glColorPointer(4, GL_FIXED, 0, colors);
	glDrawArrays(GL_TRIANGLES, 0, 8); //GL_TRIANGLE_STRIP can be used for more trangles together... give just one extra point.. it will be connected
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
	
	glDisableClientState(GL_VERTEX_ARRAY);


}
