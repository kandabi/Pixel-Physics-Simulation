#include "simulation.h"


int randomRange(int min, int max) //range : [min, max)
{
	return min + rand() % ((max + 1) - min);
}

void Simulation::CreateObject(int x, int y, int objectType)
{
	//createdObjects.push_back({ x, y });
	if (x > 0 && x < screenWidth && y > 0 && y < screenHeight)
	{
		olc::Pixel color;

		if (objectType == 1)
		{
			switch (randomRange(0, 3))
			{
				case 0:
					color = olc::Pixel{ 237, 200, 85 };
					break;
				case 1:
					color = olc::Pixel{ 242, 209, 107 };
					break;
				case 2:
					color = olc::Pixel{ 230, 198, 101 };
					break;
				case 3:
					color = olc::Pixel{ 232, 194, 74 };
					break;
			}


		}
		else
		{
			switch (randomRange(0, 3))
			{
			case 0:
				color = olc::Pixel{ 0, 153, 255 };
				break;
			case 1:
				color = olc::Pixel{ 14, 143, 230 };
				break;
			case 2:
				color = olc::Pixel{ 28, 150, 232 };
				break;
			case 3:
				color = olc::Pixel{ 5, 144, 237 };
				break;
			}
		}


		
		world[y * screenWidth + x] = { objectType , color };
	}

}

void Simulation::InitSimulation(int screen_w, int screen_h, int pixel_w, int pixel_h)
{
	screenWidth = screen_w;
	screenHeight = screen_h;

	//world = new unsigned char[screenWidth * screenHeight];
	//memset(world, 0, screenWidth * screenHeight * sizeof(unsigned char));

	world = new Object[screenWidth * screenHeight];

	for (int x = 0; x < screenWidth; ++x)
	{
		for (int y = 0; y < screenHeight; ++y)
		{
			//world[y * screenWidth + x] = 0;
			world[y * screenWidth + x] = { 0 };
		}
	}
}




void Simulation::ProcessSimulation()
{
	for (int x = screenWidth - 1; x > 0 ; --x)
	{
		for (int y = screenHeight - 1; y > 0; --y)
		{

			switch (world[y * screenWidth + x].id)
			{ //*** Sand
				case 1:
				{
					int velocity = 2;
					do
					{
						int random = std::rand() % 2;
						if (y + velocity < screenHeight && x + velocity < screenWidth && x - velocity > 0)
						{
							if (world[(y + velocity) * screenWidth + x].id == 0)
							{
								world[(y + velocity) * screenWidth + x] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = {};
								break;
							}
							else if (world[(y + velocity) * screenWidth + (x + random)].id == 0)
							{
								world[(y + velocity) * screenWidth + (x + random)] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = {};
							}
							else if (world[(y + velocity) * screenWidth + (x - random)].id == 0)
							{
								world[(y + velocity) * screenWidth + (x - random)] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = {};
								break;
							}
						}
					} while (--velocity);
					break;
				}
				case 2:
				{ //*** Water
					int velocity = 2;
					do
					{
						int random = randomRange(-4, 3);
						if (y + velocity < screenHeight && x + velocity < screenWidth && x - velocity > 0)
						{
							if (world[(y + velocity) * screenWidth + x].id == 0)
							{
								world[(y + velocity) * screenWidth + x] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = {};
								break;
							}
							else if (world[(y + velocity) * screenWidth + (x + velocity)].id == 0)
							{
								world[(y + velocity) * screenWidth + (x + velocity)] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = {};
								break;
							}
							else if (world[(y + velocity) * screenWidth + (x - velocity)].id == 0)
							{
								world[(y + velocity) * screenWidth + (x - velocity)] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = {};
								break;
							}
							else if (world[y * screenWidth + (x + random)].id == 0)
							{
								world[y * screenWidth + (x + random)] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = {};
								break;
							}
							else if (random != 0 && world[(y + random ) * screenWidth + (x + random)].id == 2)
							{
								Object swap = world[(y + random) * screenWidth + (x + random)];
								world[(y + random) * screenWidth + (x + random)] = { world[y * screenWidth + x].id, world[y * screenWidth + x].color };
								world[y * screenWidth + x] = swap;
							}

						}
					} while (--velocity);
					break;
				}
			}
		}
	}
}
