#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "fstream"
#include "iostream"
#include "SceneObject.h"

class Cube : public SceneObject
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;
	GLfloat _rotation;
	Vector3 _position;
	GLfloat _FlySpeed;
	Material* _material;
public:
	Cube(Mesh* mesh, Texture2D* texture,  float x, float y, float z);
	//Pyramid(Mesh* mesh, float x, float y, float z);
	~Cube();
	void Draw();
	void Update();
};