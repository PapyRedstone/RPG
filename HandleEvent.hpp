#ifndef HANDLE_EVENT_HPP
#define HANDLE_EVENT_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <memory>

class Entity;

class EventHandler{
public:
	EventHandler();
	virtual ~EventHandler();
	virtual void resolve(Entity *player);
	virtual void addAction(std::function<void(Entity*, std::shared_ptr<Entity>)> action);
	virtual void setTarget(std::shared_ptr<Entity> ent);

private:
	std::vector<std::function<void(Entity*, std::shared_ptr<Entity>)>> m_Actions;
	std::shared_ptr<Entity> m_Target;
};

#endif