#include "Game.hpp"
#include <string>
#include <iostream>

Game::Game():
	m_Window(sf::VideoMode(800, 600), "My game"),
	m_Player{std::make_shared<Entity>(100,"perso.png")},
	TimePerFrame{sf::seconds(1.f / 60.f)}{

	m_PlayerEventHandler.addAction(goUp);
	m_PlayerEventHandler.addAction(goDown);
	m_PlayerEventHandler.addAction(goLeft);
	m_PlayerEventHandler.addAction(goRight);

	m_EnnemiEventHandler.setTarget(m_Player);
	m_EnnemiEventHandler.addAction(goToTarget);

	m_Ennemies.emplace_back(std::make_shared<Entity>(50, "monstre.png"));
	m_Ennemies.emplace_back(std::make_shared<Entity>(50, "monstre.png"));

	m_Player->setPosition(50,50);
	m_Ennemies[0]->setPosition(500,100);
	m_Ennemies[1]->setPosition(100,500);
}

void Game::run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_Window.isOpen()){
		handleEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleEvents();
			update(TimePerFrame);
		}
		draw();
	}
}

void Game::draw(){
	m_Window.clear();
	for (auto& e : m_Ennemies){
		m_Window.draw(*e);
	}
	m_Window.draw(*m_Player);
	m_Window.display();
}

void Game::handleEvents(){
	sf::Event event;
	while (m_Window.pollEvent(event)){
		switch (event.type){
			case sf::Event::Closed:
				m_Window.close();
				break;				
			default:
				break;
		}
	}
}

void Game::update(sf::Time deltaTime){
	m_Player->handleEvent(m_PlayerEventHandler, deltaTime);
	for (auto& e : m_Ennemies){
		e->handleEvent(m_EnnemiEventHandler, deltaTime);	
	}
}