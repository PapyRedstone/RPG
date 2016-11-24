#include "HandleEvent.hpp"
#include "Entity.hpp"

EventHandler::EventHandler():
	m_Target{nullptr}
{}

EventHandler::~EventHandler(){}

void EventHandler::addAction(std::function<void(Entity&, std::shared_ptr<Entity>)> action){
	m_Actions.push_back(action);
}

void EventHandler::resolve(Entity& player){
	for(auto& action : m_Actions) {
		action(player, m_Target);
	}
}

void EventHandler::setTarget(std::shared_ptr<Entity> ent){
	m_Target = ent;
}