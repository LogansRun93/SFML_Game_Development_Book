#include "SceneNode.hpp"
#include <algorithm>
#include <cassert>

SceneNode::SceneNode() : mChildren(), mParent(nullptr)
{
	// Constructor. Set children container to empty and initialize parent pointer as null
}

void SceneNode::attachChild(Ptr child)
{
	// Set the child's parent pointer as this SceneNode and add it to this SceneNode's child container
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	// Check if the given node exists within the children of this node
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) -> bool {return p.get() == &node; });
	assert(found != mChildren.end());

	// Return a pointer to the removed SceneNode, set the removed node's parent to null, and remove the node from this node's children
	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Get the transform to apply and combine it with the current tranform to get the absolute transform
	states.transform *= getTransform();
	
	// Draw the transformed node
	drawCurrent(target, states);

	// Loop through the children of this node and redraw them since they will transform base on this node.
	drawChildren(target, states);
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const Ptr& child : mChildren) // C++ for each loop
	{
		// Dereference the current child pointer to get the child object. Then call the draw method of the object
		child->draw(target, states);
	}
}
