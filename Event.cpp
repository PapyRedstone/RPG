#include "Event.hpp"

void goLeft(Entity* player, std::shared_ptr<Entity> target = nullptr) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		player->setNextMove(sf::Vector2f(-1,0));
	}
}

void goRight(Entity* player, std::shared_ptr<Entity> target = nullptr) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		player->setNextMove(sf::Vector2f(1,0));
	}
}

void goUp(Entity* player, std::shared_ptr<Entity> target = nullptr) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		player->setNextMove(sf::Vector2f(0,-1));
	}
}

void goDown(Entity* player, std::shared_ptr<Entity> target = nullptr) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		player->setNextMove(sf::Vector2f(0,1));
	}
}

void goToTarget(Entity* player, std::shared_ptr<Entity> target = nullptr){
	sf::Vector2f deltaPos = target->getPosition()-player->getPosition();
	sf::Vector2f move(0,0);
	if (deltaPos.x < 0){
		move.x--;
	}
	if (deltaPos.x >0){
		move.x++;
	}
	if (deltaPos.y < 0){
		move.y--;
	}
	if (deltaPos.y >0){
		move.y++;
	}
	player->setNextMove(move);
}

void attack(Entity* player, std::shared_ptr<Entity> target = nullptr){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		player->attack();
	}
}
