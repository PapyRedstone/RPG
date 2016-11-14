#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"
#include "PlayerEvent.hpp"
#include "EnnemiEvent.hpp"
#include "NoCopyable.hpp"

class Game: private NoCopyable{
public:

	Game();
	~Game(){}

	void run();

private:
	void draw();
	void handleEvents();
	sf::RenderWindow m_Window;
	Entity m_Player;
	std::vector<Entity> m_Ennemies;
	std::shared_ptr<HandleEvent> m_PlayerEvent = std::make_shared<PlayerEvent>();
	std::shared_ptr<HandleEvent> m_EnnemiEvent = std::make_shared<EnnemiEvent>();
};

#endif