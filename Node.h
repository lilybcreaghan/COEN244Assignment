/*
 * Node.h
 *
 *  Created on: Jun. 27, 2022
 *      Author: liu
 */

#ifndef NODE_H_
#define NODE_H_

class Node { // delaration of the type;
public: //everything below is publicly visiable; member functions;
	Node();  // default constructor;
	Node(short id, double value ); // constructor with arguments;

	Node(const Node& other); // copy constructor

	virtual ~Node(); // indicate any clean up before the deleting of the object memory space;

	Node& operator=(const Node &other);

	void setId(short value);
	short getId() const; //not changing any data member;

	void setWeight(double value);

	double getWeight() const;

	Node  clone (); // this should work somehow, but not the optimal form.

	static int getObjCount();
	// clone a node;


private:  //seperating the data storage and data access;
	 short id;  // unique id;
     double weight;    // value;
     static int objCount;

};

#endif /* NODE_H_ */
