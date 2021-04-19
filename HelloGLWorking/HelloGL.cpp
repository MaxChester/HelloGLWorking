
#include "HelloGL.h"
#include "GLUTCallbacks.h"
#include "MeshLoader.h"
//#include "Staticobject.h"
using namespace std;
HelloGL::HelloGL(int argc, char* argv[]) { // constructor 
	HelloGL::InitGL(argc, argv);
	HelloGL::InitObjects();
	HelloGL::initLighting();
	glutMainLoop(); //Make sure is always loaded last
}
void HelloGL::InitGL(int argc, char* argv[]) {
	BrightnessLevel = 0.2f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Window Title");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800); 	// Set the viewport to be the entire window
	gluPerspective(100, 1, 1, 1000);	// Set the correct perspective.
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glCullFace(GL_BACK);
}
void HelloGL::InitObjects() {
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	//Mesh* pyramidMesh = MeshLoader::Load((char*)"iamges/pyramid.txt");
	//Mesh* oldCubeMesh = MeshLoader::Load((char*)"images/oldCube.txt");
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Penguins.raw", 512, 512);
	camera = new Camera();
	for (int i = 0; i < 1000; i++)
	{
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	/*for (int i = 500; i < 1000; i++)
	{
		objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}*/
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->centre.x = 0.0f; camera->centre.y = 0.0f; camera->centre.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
}
void HelloGL::Display() {
	//glClear(GL_COLOR_BUFFER_BIT); //CLEARS THE SCENE
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
	}
	glFlush(); //Flushes the scene drawn to the graphics card
	glutSwapBuffers();
}
void HelloGL::Update() {
	glLoadIdentity();
	glutPostRedisplay();
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Update();
	}
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	initLighting();
}
void HelloGL::initLighting() {
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = BrightnessLevel; //default 0.2 //Red
	_lightData->Ambient.y = BrightnessLevel; //default 0.2 //Green
	_lightData->Ambient.z = BrightnessLevel; //default 0.2 //Blue
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}
void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd' || key == 'D') {
		rotation += 0.5;
	}
	if (key == 'a' || key == 'A') {
		rotation -= 0.5;
	}
	if (key == 'e' || key == 'E') {
		_Exit(0);
	}
	if (key == 'w' || key == 'W') {
		BrightnessLevel += 0.5;
		cout << BrightnessLevel << endl;
	}
	if (key == 's' || key == 'S') {
		BrightnessLevel -= 0.5;
		cout << BrightnessLevel << endl;
	}
}
HelloGL::~HelloGL(void) {
	delete camera;
}
