#pragma once
#include "PixelGameEngine.h"
#include <array>

struct Object
{
	int id = 0;
	olc::Pixel color = olc::BLACK;
};

class Simulation
{
	int screenWidth;
	int screenHeight;

	// Terrain size

	//std::vector<Object> createdObjects;

public:
	//unsigned char* world = nullptr;
	Object* world;

	Simulation() 
	{

	}


	//void DrawSimulation();
	void CreateObject(int x, int y, int objectType);
	void InitSimulation(int screen_w, int screen_h, int pixel_w = 1, int pixel_h = 1);
	void ProcessSimulation();
};

