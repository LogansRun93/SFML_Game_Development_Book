#include "Entity.hpp"

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
	Type mType;

};