#ifndef EVENT_HPP
#define EVENT_HPP

#include "Entity.hpp"

void goLeft(Entity&, std::shared_ptr<Entity>);
void goRight(Entity&, std::shared_ptr<Entity>);
void goUp(Entity&, std::shared_ptr<Entity>);
void goDown(Entity&, std::shared_ptr<Entity>);

void goToTarget(Entity&, std::shared_ptr<Entity>);

#endif