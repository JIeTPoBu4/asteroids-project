#include "GameplayState.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Game.h"



GameplayState::GameplayState(Game* _game) : 
GameState(_game),
gameRunning(true),
m_World(*window, font, _game) {
}

GameplayState::~GameplayState() {
}

void GameplayState::handleEvents() {
	if (m_World.getLives() <= 0) {
		game->changeState(Game::States::GAME_OVER, m_World.getScore());

		return;
	}

	sf::Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed) {
			window->close();
		}
	}
}

void GameplayState::update(sf::Time dt) {	
	m_World.update(dt);
}

void GameplayState::render() {
	window->clear();
	m_World.draw();
	window->display();
}