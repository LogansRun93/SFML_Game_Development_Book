#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder
{

public:
	template<typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);

	void load(Identifier id, const std::string& filename);

	sf::Resource& get(Identifier id);
	const sf::Resource& get(Identifier id) const;


private:
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mResourceMap;
	
};

#include "ResourceHolder.inl"