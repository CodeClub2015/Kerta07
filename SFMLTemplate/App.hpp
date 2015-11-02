#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

class App {
private:
	bool running;
	sf::RenderWindow window;
	Player player;

	void update(const sf::Time& elapsedTime);
	void draw();
public:
	App(int width, int height);
	
	void run();
	void exit();
	
	bool isRunning() const;

	~App();
};

