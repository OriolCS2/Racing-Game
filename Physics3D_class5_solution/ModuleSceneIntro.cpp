#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "PhysBody3D.h"
#include "Primitive.h"
#include "ModuleCamera3D.h"
#include "ModuleAudio.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	CreateObjects();
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	
	for (int i = 0; i < bodies.Count(); ++i) {
		bodies[i].Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void ModuleSceneIntro::CreateObjects()
{
	Cube cube(100, 7, 50); //el que tens davant al entrar
	cube.SetPos(0, 0, -25);
	cube.color = White;
	App->physics->AddBody(cube, 0.0f);
	bodies.PushBack(cube);
	
	Cube cube2(5, 7, 30); //esquerra al entrar
	cube2.color = White;
	cube2.SetPos(-30, 0, 10);
	App->physics->AddBody(cube2, 0.0f);
	bodies.PushBack(cube2);

	Cube cube3(5, 7, 30); //dreta al entrar
	cube3.color = White;
	cube3.SetPos(30, 0, 10);
	App->physics->AddBody(cube3, 0.0f);
	bodies.PushBack(cube3);

	Cube cube4(5, 7, 30); //esquerra2 al entrar
	cube4.color = White;
	cube4.SetPos(-25, 0, 40);
	App->physics->AddBody(cube4, 0.0f);
	bodies.PushBack(cube4);

	Cube cube5(5, 7, 30); //dreta2 al entrar
	cube5.color = White;
	cube5.SetPos(25, 0, 40);
	App->physics->AddBody(cube5, 0.0f);
	bodies.PushBack(cube5);

	Cube cube6(33, 7, 5); //darrera teu al entrar
	cube6.color = White;
	cube6.SetPos(0, 0, 20);
	App->physics->AddBody(cube6, 0.0f);
	bodies.PushBack(cube6);
}

