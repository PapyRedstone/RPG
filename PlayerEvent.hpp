#ifndef PLAYER_EVENT_HPP
#define PLAYER_EVENT_HPP

#include "HandleEvent.hpp"

class PlayerEvent: public HandleEvent{
public:
	PlayerEvent();
	virtual ~PlayerEvent();
	virtual void handleEvents(const sf::Event& event, Entity& ent);
private:

};

#endif