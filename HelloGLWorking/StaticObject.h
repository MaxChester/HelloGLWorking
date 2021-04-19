/*#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "fstream"
#include "iostream"
#include "SceneObject.h"
#include "MeshLoader.h"
class StaticObject : public SceneObject
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;
	Vector3 _position;
public:
	void Draw();
	void Update();
	Pyramid(Mesh* mesh, float x, float y, float z);
};*/
#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "fstream"
#include "iostream"
#include "SceneObject.h"

class Pyramid : public SceneObject
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;
	Vector3 _position;
	
public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();
	void Draw();
	void Update();
};

