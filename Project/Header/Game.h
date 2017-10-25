#pragma once
#include <iostream>

class Game
{
public:
	Game();

	void init();
	void run();
	~Game();

private:
	void update();
	void render();
};

