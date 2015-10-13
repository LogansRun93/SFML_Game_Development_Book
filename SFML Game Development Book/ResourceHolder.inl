template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	// Create and load resource
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to laod " + filename);
	}

	// If loading sucessful, insert resource to map
	insertResource(id, std::move(resource));

}