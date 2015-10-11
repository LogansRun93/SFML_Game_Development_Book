#include "Game.hpp"
#include <SFML\Graphics.hpp>

const float Game::playerSpeed = 100.f;
const sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);

Game::Game() 
	: mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
	, mPlayer()
	, mTexture()
{
	// Set the intial properties of the player and window.

	if (!mTexture.loadFromFile("C:/Visual Studio 2013/Projects/SFML Game Development Book/SFML Game Development Book/SFML Game Development Book/Eagle.png"))
	{
		// Error loading file
	}

	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
}

void Game::run()
{
	// The method that contains the main game loop.
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{

		// While the window is open, process any events, update the game, and render the display
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		// While there are events to poll...
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				// Player pressed key. Handle the input
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				// Player released key. Handle the input
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				// Window was requested to be closed. Close it.
				mWindow.close();
				break;
		}


		//if (event.type == sf::Event::Closed)
		//{
		//	// Window was requested to be closed. Close it.
		//	mWindow.close();
		//}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	// Store the keyboard input from the user

	if (key == sf::Keyboard::W)
	{
		mIsMovingUp = isPressed;
	}
	else if (key == sf::Keyboard::S)
	{
		mIsMovingDown = isPressed;
	}
	else if (key == sf::Keyboard::A)
	{
		mIsMovingLeft = isPressed;
	}
	else if (key == sf::Keyboard::D)
	{
		mIsMovingRight = isPressed;
	}
}

void Game::update(sf::Time deltaTime)
{
	// Update the logic of the game at each frame

	// Move the player based on input
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
	{
		movement.y -= playerSpeed;
	}
	if (mIsMovingDown)
	{
		movement.y += playerSpeed;
	}
	if (mIsMovingLeft)
	{
		movement.x -= playerSpeed;
	}
	if (mIsMovingRight)
	{
		movement.x += playerSpeed;
	}

	mPlayer.move(movement * deltaTime.asSeconds());
	

}

void Game::render()
{
	// Render the current frame on screen (clear the screen of all objects, draw all objects, display the drawn objects)
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}


