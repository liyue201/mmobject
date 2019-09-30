#include "mmobject.h"

MMObject::MMObject(MMObject* parent)
	: m_parent(parent)
{
	if (m_parent != nullptr) {
		m_parent->addChild(this);
	}
}

MMObject::~MMObject()
{
	if (m_parent != nullptr) {
		m_parent->removeChild(this);
	}
	while (m_children.size() > 0) {
		auto iter = m_children.begin();
		MMObject* child = (*iter);
		m_children.erase(iter);
		child->m_parent = nullptr;
		delete child;
	}
}

void MMObject::setParent(MMObject* parent)
{
	if (m_parent == parent) {
		return;
	}
	if (m_parent != nullptr) {
		m_parent->removeChild(this);
	}
	m_parent = parent;
	if (m_parent != nullptr) {
		m_parent->addChild(this);
	}
}

void MMObject::addChild(MMObject* child)
{
	m_children.insert(child);
}

void MMObject::removeChild(MMObject* child)
{
	m_children.erase(child);
}