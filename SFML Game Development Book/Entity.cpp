#include "Entity.hpp"

void Entity::setVelocity(float vx, float vy)
{
	// Set the velocity of the entity using float values
	mVelocity.x = vx;
	mVelocity.y = vy;
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	// Set the velocity of the entity using a vector
	mVelocity = velocity;
}

sf::Vector2f Entity::getVelocity() const
{
	// Reutrn the current velocity of the entity.
	return mVelocity;
}

