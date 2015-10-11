#include <SFML\Graphics.hpp>

class Game : private sf::NonCopyable
{
public:
	   Game();
	   void run();
private:
	// Private methods
	void processEvents();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);

private:
	// Private properties
	static const float playerSpeed;
	static const sf::Time timePerFrame;

	sf::RenderWindow mWindow;
	//sf::CircleShape mPlayer;

	sf::Texture mTexture;
	sf::Sprite mPlayer;

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;


};

int main()
{
	// Create game object and run application
	Game game;
	game.run();
}