#include "StaticObject.h"
#include "SceneObject.h"
/*Vertex* Pyramid::indexedVertices = nullptr;
Color* Pyramid::indexedColors = nullptr;
GLushort* Pyramid::indices = nullptr;
int Pyramid::numVertices = 0;
int Pyramid::numColors = 0;
int Pyramid::numIndices = 0;

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr) //constructor
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	
}

void Pyramid::Update()
{
	
}
/*void Pyramid::Draw()
{

	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glPushMatrix();
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		//glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

		glTranslatef(_position.x, _position.y, _position.z); //translatef comes before rotatef
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glPopMatrix();
	}
}

Pyramid::~Pyramid(void)
{
}*/