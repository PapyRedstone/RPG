#include "Entity.hpp"
#include <iostream>

Entity::Entity(int speed, std::shared_ptr<HandleEvent> eventHolder, std::string path):
	sf::Sprite(),
	m_Speed{speed},
	m_EventHolder{eventHolder}{
	m_Texture.loadFromFile(path);
	setTexture(m_Texture);
}

Entity::Entity(Entity&& ent):
	sf::Sprite(),
	m_Speed(std::move(ent.m_Speed)),
	m_EventHolder(std::move(ent.m_EventHolder)),
	m_NextMov(std::move(ent.m_NextMov)),
	m_Texture(std::move(ent.m_Texture)){

}

Entity& Entity::operator=(Entity&& ent){
	m_Speed = std::move(ent.m_Speed);
	m_EventHolder = std::move(ent.m_EventHolder);
	m_NextMov = std::move(ent.m_NextMov);
	m_Texture = std::move(ent.m_Texture);
	return *this;
}

void Entity::handleEvents(const sf::Event& event){
	m_EventHolder->handleEvents(event,*this);
	move(m_NextMov);
	std::cout<<"x:"<<getPosition().x<<" y:"<<getPosition().y<<std::endl;
}

void Entity::setNextMov(const sf::Vector2f& mov){
	m_NextMov = sf::Vector2f(m_Speed*mov.x,m_Speed*mov.y);
}
