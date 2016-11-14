#include "PlayerEvent.hpp"
#include "Entity.hpp"

PlayerEvent::PlayerEvent():HandleEvent(){}

PlayerEvent::~PlayerEvent(){}

void PlayerEvent::handleEvents(const sf::Event& event, Entity& ent){
	sf::Vector2f mov(0,0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		mov.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		mov.x = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		mov.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		mov.y = 1;
	}
	ent.setNextMov(mov);
}
