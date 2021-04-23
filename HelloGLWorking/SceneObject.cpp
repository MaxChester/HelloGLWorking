#pragma once
#include "SceneObject.h"
#include <iostream>
#include <fstream>

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture)
{
	//Used to let the cubes understand what mesh and texture they need to use.
	_mesh = mesh;
	_texture = texture;
}

void SceneObject::Update() {}

void SceneObject::Draw() {}

SceneObject::~SceneObject() {}