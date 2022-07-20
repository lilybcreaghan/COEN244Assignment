/*
 * NodeList.h
 *
 *  Created on: Jun. 29, 2022
 *      Author: liu
 */


#ifndef NODELIST_H_
#define NODELIST_H_

#include "Node.h"

class NodeList {
public:
	NodeList();
	virtual ~NodeList();
	NodeList(const NodeList &other);
	NodeList& operator=(const NodeList &other);

	void addNode(Node& n);
	void removeAll();
	bool remove(int pos); //return the operation state; // move backward the elements behind of the pos that has node objects in them.
	void printAll();

	int getNumItems() const;
	Node& getNode(int pos) const;

	bool searchByID() const;
	bool searchByValue() const;

private:

	void init(const NodeList& other);
	static const long LIST_SIZE = 500; // the maximum items in the list
	Node *items; // items will point to the dynamically allocated array
	long numItems; // the number of items currently in the list
};

#endif /* NODELIST_H_ */
