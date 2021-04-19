#pragma once
#include "Structures.h"
#include <iostream>
#include <fstream>
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;
public:
//	Mesh* _mesh;
	SceneObject(Mesh* mesh, Texture2D* texture);
	//SceneObject(Mesh* mesh);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

