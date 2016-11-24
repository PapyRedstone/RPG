#include "Entity.hpp"
#include <iostream>

Entity::Entity(int speed, std::string path):
	sf::Sprite(),
	m_Speed{speed}{
	m_Texture.loadFromFile(path);
	setTexture(m_Texture);
	scale(0.5f,0.5f);
}

Entity::Entity(Entity&& ent):
	sf::Sprite(),
	m_Speed(std::move(ent.m_Speed)),
	m_NextMove(std::move(ent.m_NextMove)),
	m_Texture(std::move(ent.m_Texture)){
}

Entity& Entity::operator=(Entity&& ent){
	m_Speed = std::move(ent.m_Speed);
	m_NextMove = std::move(ent.m_NextMove);
	m_Texture = std::move(ent.m_Texture);
	return *this;
}

void Entity::setNextMove(const sf::Vector2f& mov){
	m_NextMove += mov;
}

void Entity::handleEvent(EventHandler& evhan, const sf::Time deltaTime){
	evhan.resolve(*this);
	m_NextMove.x *= deltaTime.asSeconds();
	m_NextMove.y *= deltaTime.asSeconds();
	m_NextMove.x *= m_Speed;
	m_NextMove.y *= m_Speed;
	move(m_NextMove);
	m_NextMove = sf::Vector2f(0,0);
}