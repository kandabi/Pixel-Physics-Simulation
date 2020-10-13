#include "game.h"

int main()
{
	Game game;
	if (game.Construct(240, 160, 3, 3, false, true))
		game.Start();

	return 0;
}
