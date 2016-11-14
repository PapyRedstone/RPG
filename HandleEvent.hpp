#ifndef HANDLE_EVENT_HPP
#define HANDLE_EVENT_HPP

#include <SFML/Graphics.hpp>

class Entity;

class HandleEvent{
public:
	HandleEvent();
	virtual ~HandleEvent();
	virtual void handleEvents(const sf::Event& event, Entity& ent) =0;
private:
};

#endif