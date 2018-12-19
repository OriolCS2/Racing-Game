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
	p.color = White;
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
	
	Cube cube6(33, 7, 5); //darrera teu al entrar
	cube6.color = White;
	cube6.SetPos(0, 0, 20);
	App->physics->AddBody(cube6, 0.0f);
	bodies.PushBack(cube6);

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

	Cube cube7(5, 7, 30); //dreta3 al entrar
	cube7.color = White;
	cube7.SetPos(20, 0, 60);
	App->physics->AddBody(cube7, 0.0f);
	bodies.PushBack(cube7);

	Cube cube8(5, 7, 30); //esquerra3 al entrar
	cube8.color = White;
	cube8.SetPos(-20, 0, 60);
	App->physics->AddBody(cube8, 0.0f);
	bodies.PushBack(cube8);

	Cube cube9(5, 7, 30); //dreta4 al entrar
	cube9.color = White;
	cube9.SetPos(15, 0, 80);
	App->physics->AddBody(cube9, 0.0f);
	bodies.PushBack(cube9);

	Cube cube10(5, 7, 30); //esquerra4 al entrar
	cube10.color = White;
	cube10.SetPos(-15, 0, 80);
	App->physics->AddBody(cube10, 0.0f);
	bodies.PushBack(cube10);

	Cube cube11(5, 7, 30); //dreta5 al entrar
	cube11.color = White;
	cube11.SetPos(10, 0, 100);
	App->physics->AddBody(cube11, 0.0f);
	bodies.PushBack(cube11);

	Cube cube12(5, 7, 30); //esquerra5 al entrar
	cube12.color = White;
	cube12.SetPos(-10, 0, 100);
	App->physics->AddBody(cube12, 0.0f);
	bodies.PushBack(cube12);

	Cube cube13(5, 7, 30); //dreta6 al entrar
	cube13.color = White;
	cube13.SetPos(5, 0, 120);
	App->physics->AddBody(cube13, 0.0f);
	bodies.PushBack(cube13);

	Cube cube14(5, 7, 30); //esquerra6 al entrar
	cube14.color = White;
	cube14.SetPos(-5, 0, 120);
	App->physics->AddBody(cube14, 0.0f);
	bodies.PushBack(cube14);

	//COMENÇAMENT DE LA CURVA A LA DRETA 
	Cube cube15(5, 7, 50); 
	cube15.color = White;
	cube15.SetPos(5, 0, 140);
	App->physics->AddBody(cube15, 0.0f);
	bodies.PushBack(cube15);

	Cube cube16(5, 7, 100);
	cube16.color = White;
	cube16.SetPos(-42.5f, 0, 167.5f);
	cube16.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube16, 0.0f);
	bodies.PushBack(cube16);

	Cube cube17(5, 7, 80);
	cube17.color = White;
	cube17.SetPos(-42.5f, 0, 137.5f);
	cube17.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube17, 0.0f);
	bodies.PushBack(cube17);
	//FINAL RECTE 

	Cube cube18(3, 15, 3);
	cube18.color = White;
	cube18.SetPos(-42.5f, 0, 152.5f);
	cube18.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube18, 0.0f);
	bodies.PushBack(cube18);




	/*
	Cube c(49, 5, 49);
	c.SetPos(125, 55, -500);
	PhysBody3D* body = App->physics->AddBody(c, 1000);
	
	Cube cube18(5, 7, 50);
	cube18.color = White;
	cube18.SetPos(5, 0, 140);
	PhysBody3D* body2 = App->physics->AddBody(cube18, 0.0f);
	

	btVector3 pivotStart(0, 0, 0);
	btVector3 pivotA(22.5, 0, 0);
	App->physics->AddConstraintHinge(*body, *body2, App->camera->TransformToVec3(pivotStart), App->camera->TransformToVec3(pivotA), { 0,0,1 }, { 0,0,1 });
	*/
}

