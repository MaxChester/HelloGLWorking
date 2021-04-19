#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "gl\freeglut.h"
struct Vector3 {
	float x, y, z;
};
struct Vector4 {
	float x, y, z, w;
};
struct Lighting {
	Vector4 Ambient, Diffuse, Specular;
};
struct Material {
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};
struct Camera {
	Vector3 eye;
	Vector3 centre;
	Vector3 up;
};
struct Color {
	GLfloat r, g, b;
};
struct Vertex {
	GLfloat x, y, z;
};
struct TexCoord {
	GLfloat u, v;
};
struct Mesh {
	Vertex* Vertices;
	TexCoord* TexCoords;
	Vector3* Normal;
	GLushort* Indices;
	GLint VertexCount, NormalCount, TexCoordCount, IndexCount;
};
