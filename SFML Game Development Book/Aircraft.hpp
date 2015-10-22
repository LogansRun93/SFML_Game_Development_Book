#include "Entity.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Aircraft : public Entity
{

public:

	// Enum used to define the type of Aircraft
	enum Type
	{
		Eagle, Raptor
	};

	explicit Aircraft(Type type);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};