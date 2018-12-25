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
	
	//body2->GetTransform(&cube19.transform);
	body->GetTransform(&cube18.transform);
	cube18.Render();
	body4->GetTransform(&cube19.transform);
	cube19.Render();
	body6->GetTransform(&cube20.transform);
	cube20.Render();
	
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
	cube16.SetPos(-82.5f, 0, 167.5f);
	cube16.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube16, 0.0f);
	bodies.PushBack(cube16);

	Cube cube17(5, 7, 80);
	cube17.color = White;
	cube17.SetPos(-82.5f, 0, 137.5f);
	cube17.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube17, 0.0f);
	bodies.PushBack(cube17);
	//FINAL RECTE 

	Cube cube30(5, 7, 100);
	cube30.color = White;
	cube30.SetPos(-42.5f, 0, 167.5f);
	cube30.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube30, 0.0f);
	bodies.PushBack(cube30);

	Cube cube31(5, 7, 80);
	cube31.color = White;
	cube31.SetPos(-42.5f, 0, 137.5f);
	cube31.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube31, 0.0f);
	bodies.PushBack(cube31);

	Cube cube32(5, 7, 80);
	cube32.color = White;
	cube32.SetPos(-120.5f, 0, 167.5f);
	cube32.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube32, 0.0f);
	bodies.PushBack(cube32);

	Cube cube33(5, 7, 160);
	cube33.color = White;
	cube33.SetPos(-163, 0, 90);
	App->physics->AddBody(cube33, 0.0f);
	bodies.PushBack(cube33);

	Cube cube34(5, 7, 140);
	cube34.color = White;
	cube34.SetPos(-120, 0, 67.5f);
	App->physics->AddBody(cube34, 0.0f);
	bodies.PushBack(cube34);

	Cube cube35(5, 7, 100);
	cube35.color = White;
	cube35.SetPos(-167.5f, 0, -5);
	cube35.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube35, 0.0f);
	bodies.PushBack(cube35);

	Cube cube36(5, 7, 80);
	cube36.color = White;
	cube36.SetPos(-200.5f, 0, 7.5f);
	cube36.SetRotation(90, { 0,1,0 });
	App->physics->AddBody(cube36, 0.0f);
	bodies.PushBack(cube36);


	//CONSTRAINTS

	//PRIMERA
	cube18.color = Red;
	cube18.SetPos(-42.5f, 3, 152.5f);
	cube18.SetRotation(90, vec3(0, 0, 1));
	body = App->physics->AddBody(cube18, 10000.0f);
	body->GetBody()->setLinearFactor(btVector3(0, 0, 0));
	
	Cylinder cyl(0.1f, 3);
	cyl.SetPos(-33.5f, 20, 152.5f);
	cyl.SetRotation(90, vec3(0, 0, 1));
	body2 = App->physics->AddBody(cyl, 10000.0f);
	body2->GetBody()->setLinearFactor(btVector3(0, 0, 0));
	
	App->physics->AddConstraintHinge(*body2, *body, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0),true, true);

	//SEGONA
	cube19.color = Red;
	cube19.SetPos(-92.5f, 10, 160.5f);
	cube19.SetRotation(90, vec3(0, 1, 0));
	body4 = App->physics->AddBody(cube19, 10000.0f);
	body4->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	Cylinder cyl2(0.1f, 3);
	cyl2.SetPos(-83.5f, 10, 160.5f);
	cyl2.SetRotation(90, vec3(0, 1, 0));
	body3 = App->physics->AddBody(cyl2, 10000.0f);
	body3->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	App->physics->AddConstraintHinge(*body3, *body4, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);

	//TERCERA
	cube20.color = Red;
	cube20.SetPos(-92.5f, 10, 144.5f);
	cube20.SetRotation(90, vec3(0, 1, 0));
	body6 = App->physics->AddBody(cube20, 10000.0f);
	body6->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	Cylinder cyl3(0.1f, 3);
	cyl3.SetPos(-83.5f, 10, 144.5f);
	cyl3.SetRotation(90, vec3(0, 1, 0));
	body5 = App->physics->AddBody(cyl3, 10000.0f);
	body5->GetBody()->setLinearFactor(btVector3(0, 0, 0));

	App->physics->AddConstraintHinge(*body5, *body6, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);

}

