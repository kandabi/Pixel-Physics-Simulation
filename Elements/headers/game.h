#pragma once
#include "PixelGameEngine.h"
#include "simulation.h"
#include <stdlib.h>     /* srand, rand */


class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = "Elements";
	}

private:
	Simulation simulation;

	bool OnUserCreate() override
	{
		srand(time(NULL));
		simulation.InitSimulation(ScreenWidth(), ScreenHeight());

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);

		olc::HWButton leftClick = GetMouse(0);
		if (leftClick.bHeld)
		{
			//simulation.CreateObject(GetMouseX(), GetMouseY(), 1);
			simulation.CreateObject(GetMouseX() + std::rand() % 2, GetMouseY() - std::rand() % 14, 1);
			simulation.CreateObject(GetMouseX() + std::rand() % 4, GetMouseY() - std::rand() % 14, 1);
			simulation.CreateObject(GetMouseX() + std::rand() % 6, GetMouseY() - std::rand() % 14, 1);
			simulation.CreateObject(GetMouseX() - std::rand() % 6, GetMouseY() - std::rand() % 14, 1);
			simulation.CreateObject(GetMouseX() - std::rand() % 3, GetMouseY() - std::rand() % 14, 1);
			simulation.CreateObject(GetMouseX() - std::rand() % 2, GetMouseY() - std::rand() % 14, 1);
		}
		 
		olc::HWButton rightClick = GetMouse(1);
		if (rightClick.bHeld)
		{
			//simulation.CreateObject(GetMouseX(), GetMouseY(), 2);
			simulation.CreateObject(GetMouseX() + std::rand() % 2, GetMouseY() - std::rand() % 14, 2);
			simulation.CreateObject(GetMouseX() + std::rand() % 4, GetMouseY() - std::rand() % 14, 2);
			simulation.CreateObject(GetMouseX() + std::rand() % 6, GetMouseY() - std::rand() % 14, 2);
			simulation.CreateObject(GetMouseX() - std::rand() % 6, GetMouseY() - std::rand() % 14, 2);
			simulation.CreateObject(GetMouseX() - std::rand() % 3, GetMouseY() - std::rand() % 14, 2);
			simulation.CreateObject(GetMouseX() - std::rand() % 2, GetMouseY() - std::rand() % 14, 2);
		}



		simulation.ProcessSimulation();

		Object* world = simulation.world;
		//unsigned char* world = simulation.world;
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
			{
				switch (world[y * ScreenWidth() + x].id)
				{
					case 1:
					{
						olc::Pixel color = world[y * ScreenWidth() + x].color;
						Draw(x, y, color); // Sand
						break;
					}
					case 2:
						Draw(x, y, world[y * ScreenWidth() + x].color); // Water
						break;
				}
			}

		olc::HWButton escape = GetKey(olc::Key::ESCAPE);
		if (escape.bPressed)
			return false;
		else
			return true;
	}
};