#include "Game.hpp"
#include <memory>
#include <string>

Game::Game():
	m_Window(sf::VideoMode(800, 600), "My game")/*,
	m_Player(10,m_PlayerEvent,"perso.png")*/{
	m_Ennemies.emplace_back(Entity(5, m_EnnemiEvent , "monstre.png"));
}

void Game::run(){
	m_Player.setPosition(50,50);
	while (m_Window.isOpen()){
		handleEvents();
		draw();
	}
}

void Game::draw(){
	m_Window.clear();
	m_Window.draw(m_Player);
	m_Window.display();
}

void Game::handleEvents(){
	sf::Event event;
	while (m_Window.pollEvent(event)){
		m_Player.handleEvents(event);
		switch (event.type){
			case sf::Event::Closed:
				m_Window.close();
				break;				
			default:
				break;
		}
	}
}