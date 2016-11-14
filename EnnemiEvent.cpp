#include "EnnemiEvent.hpp"
#include "Entity.hpp"

EnnemiEvent::EnnemiEvent():HandleEvent(){}

EnnemiEvent::~EnnemiEvent(){}

void EnnemiEvent::handleEvents(const sf::Event& event, Entity& ent){
	sf::Vector2f mov(0,0);
	
	ent.setNextMov(mov);
}
