#pragma once
#include "SceneObject.h"
#include <iostream>
#include <fstream>

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture)
{
	_mesh = mesh;
	_texture = texture;
}

void SceneObject::Update() {}

void SceneObject::Draw() {}

SceneObject::~SceneObject() {}