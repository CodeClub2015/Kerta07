#include "App.h"

App::App(int width, int height) : window(sf::VideoMode(width, height), "SFML"),
								  running(false) {
	// dirty hax
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("Content\\kuha.jpg");
	
	player = new Player(texture);
}

void App::update(const sf::Time& elapsedTime) {
	sf::Event e;
	
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			exit();
		} else if (e.type == sf::Event::Resized) {
			const float w = static_cast<float>(e.size.width);
			const float h = static_cast<float>(e.size.height);

			sf::View view = sf::View(sf::FloatRect(0.0f, 0.0f, w, h));

			window.setView(view);
		}
	}

	player->update(elapsedTime);

	// TODO: päivitä tässä.
}

void App::draw() {
	window.clear();

	player->draw(window);

	window.display();
}

void App::run() {
	if (running) return;
	running = true;

	sf::Clock clock;
	while (window.isOpen() && isRunning()) {
		sf::Time elapsed = clock.restart();
	
		update(elapsed);
		draw();
	}
}
void App::exit() {
	if (!running) return;

	running = false;

	window.close();
}

bool App::isRunning() const {
	return running;
}

App::~App() {
	exit();
	delete player;
}
