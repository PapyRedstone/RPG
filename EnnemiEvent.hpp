#ifndef ENNEMI_EVENT_HPP
#define ENNEMI_EVENT_HPP

#include "HandleEvent.hpp"

class EnnemiEvent: public HandleEvent{
public:
	EnnemiEvent();
	virtual ~EnnemiEvent();
	virtual void handleEvents(const sf::Event& event, Entity& ent);
private:

};

#endif