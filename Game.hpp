#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "NoCopyable.hpp"
#include "Entity.hpp"
#include "HandleEvent.hpp"
#include "Event.hpp"

class Game: private NoCopyable{
public:

	Game();
	~Game(){}

	void run();

private:
	void draw();
	void handleEvents();
	void update(sf::Time deltaTime);

	sf::RenderWindow m_Window;
	std::vector<std::shared_ptr<Entity>> m_Ennemies;
	std::shared_ptr<Entity> m_Player;
	EventHandler m_PlayerEventHandler;
	EventHandler m_EnnemiEventHandler;
	const sf::Time TimePerFrame;
};

#endif