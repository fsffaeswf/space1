#pragma once
#include "settings.h"
#include "cmath"


class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float angle;
	float speedx, speedy;
	float speed;
public:
	Player() {
		texture.loadFromFile(player_file_name);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(window_width/2, window_height/2);
		angle = 0;
		speedx = 0.f;
		speedy = 0.f;
		speed = 0.f;
	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			angle -= 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle += 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			speed += 1;
			if (speed >= 15)speed = 15;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			speed -=0.25f;
			if (speed <= 0)speed = 0;
		}
		speedx = sin((angle * pi) / 180) * speed;
		speedy = -cos((angle * pi) / 180) * speed;

		sprite.setRotation(angle);
		sprite.move(speedx, speedy);
	}
	sf::Sprite getSprite() { return sprite; }
};

