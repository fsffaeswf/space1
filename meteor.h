#pragma once
#include "settings.h"

class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f speed;
public:
	enum MeteorSize{Small, Average,Big};
	Meteor(std::string fileName, MeteorSize size, sf::Vector2f pos,sf::Vector2f fspeed) {
		texture.loadFromFile(fileName);
		if (size == Big) {
			sprite.setScale(0.5f, 0.5f);
		}
		else if (size == Average) {
			sprite.setScale(0.25f, 0.25f);
		}
		else if (size == Small) {
			sprite.setScale(0.125f, 0.125f);
		}
		sprite.setPosition(pos);
		sprite.setTexture(texture);
		speed = fspeed;
	}
	void update() {
		sprite.move(speed);
	}

	sf::Sprite getSprite() { return sprite; }
};
