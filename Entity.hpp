#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "HandleEvent.hpp"
#include "NoCopyable.hpp"

class Entity: public sf::Sprite, private NoCopyable{
public:
	Entity(){}
	Entity(int speed,std::shared_ptr<HandleEvent> eventHolder, std::string path);
	~Entity(){}

	Entity(Entity&& ent);
	Entity& operator=(Entity&& ent);

	void handleEvents(const sf::Event& event);
	void setNextMov(const sf::Vector2f& mov);
private:
	int m_Speed;
	std::shared_ptr<HandleEvent> m_EventHolder;
	sf::Vector2f m_NextMov;
	sf::Texture m_Texture;
};

#endif