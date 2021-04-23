#pragma once
#include <Windows.h>//needed for opengl
#include <gl/GL.h>//opengl
#include <gl/GLU.h>//OpenGL utilities
#include "GL\freeglut.h" //freeglut
#include "MeshLoader.h"
#include <iostream>
#include <sstream>
#include "Structures.h"
#include "Cubes.h"
//#include "StaticObject.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16

class Pyramid;
class Cube;
class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void InitGL(int argc, char* argv[]);
	void InitObjects();
	void initLighting();
	void DrawString(const char* text, Vector3* position, Color* color);
private:
	float rotation;
	float BrightnessLevel;
	Camera* camera;
	SceneObject* objects[1000];
	Vector4* _lightPosition;
	Lighting* _lightData;
};

