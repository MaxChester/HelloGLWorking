#include "Cubes.h"
Vertex* Cube::indexedVertices = nullptr;
//Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;
int Cube::numVertices = 0;
//int Cube::numColors = 0;
int Cube::numIndices = 0;
Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	//Code allowing the cube to understand the position it needs to load, rotation speed, speed it fly's across the screen and texture it uses.
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 1.0f;
	_FlySpeed = (rand() % 2 + 1);
	_texture = texture;
}
void Cube::Update() {
	_rotation += (rand() % 7);
	if (_rotation == 360)
		_rotation = 0;
	_position.z += _FlySpeed;
	if (_position.z == 3)
		_position.z = -100;
}
void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normal);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		_material = new Material();
		_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05; _material->Ambient.w = 1.0;
		_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05; _material->Diffuse.w = 1.0;
		_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0; _material->Specular.w = 1.0;
		_material->Shininess = 100.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);
		glPushMatrix();
			glTranslatef(_position.x, _position.y, _position.z); //translate before rotate
			glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();
		glDisable(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

/*bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}
	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		//TODO Use inFile to populate the indexedVertices array
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}
	inFile >> numColors;
	indexedColors = new Color[numColors];
	for (int i = 0; i < numColors; i++)
	{
		//TODO: Load Color information
		inFile >> indexedColors[i].r;
		inFile >> indexedColors[i].b;
		inFile >> indexedColors[i].g;
	}
	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		//TODO: Load Indices information
		inFile >> indices[i];
	}

	inFile.close();

	return true;
}*/
Cube::~Cube() //destructor
{}