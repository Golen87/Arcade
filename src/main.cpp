#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

void drawCircle(sf::RenderTarget& screen, sf::Color outColor, sf::Color inColor, sf::Vector2f position, float radius, float thickness) {
	sf::CircleShape circle(radius, 100.0f);
	circle.setFillColor(inColor);
	circle.setOutlineColor(outColor);
	circle.setOutlineThickness(thickness);
	circle.setPosition(position - sf::Vector2f(radius, radius));
	screen.draw(circle);
}

// Returns random float 0-1
float getRand() {
	return 0.5f + 2 * ((float)rand()/RAND_MAX);
}


int main() {
	srand(time(NULL));
	sf::Clock clock;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML", sf::Style::Default, settings);
	window.setFramerateLimit(50);


	while (window.isOpen()) {
		float e = clock.getElapsedTime().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sf::Vector2f center = sf::Vector2f(300, 300);
		drawCircle(window, sf::Color::Red, sf::Color::Transparent, center, 150, 30);

		window.display();
		window.clear();
	}

	return 0;
}
