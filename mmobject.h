#pragma once

#include<set>

class MMObject {
public:
	MMObject(MMObject* parent = nullptr);
	virtual ~MMObject();

	void setParent(MMObject* parent);

private:
	void addChild(MMObject* child);
	void removeChild(MMObject* child);

private:
	MMObject* m_parent;
	std::set<MMObject*> m_children;
};