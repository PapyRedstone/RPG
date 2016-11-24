#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "NoCopyable.hpp"
#include "HandleEvent.hpp"

class Entity: public sf::Sprite, private NoCopyable{
public:
	Entity(){}
	Entity(int speed, std::string path);
	~Entity(){}

	Entity(Entity&& ent);
	Entity& operator=(Entity&& ent);

	void setNextMove(const sf::Vector2f& mov);
	void handleEvent(EventHandler& evhan, const sf::Time deltaTime);
private:
	int m_Speed;
	sf::Vector2f m_NextMove;
	sf::Texture m_Texture;
};

#endif