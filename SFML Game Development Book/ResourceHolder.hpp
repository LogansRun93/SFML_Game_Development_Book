#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder
{

public:
	void load(Identifier id, const std::string& filename);
	sf::Resource& get(Identifier id);

private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mResourceMap;
	
};

#include "ResourceHolder.inl"