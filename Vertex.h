/*
 *  Vertex.h
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#ifndef VERTEX_H
#define VERTEX_H

class Vertex { 
	// delaration of the type;
public: //everything below is publicly visiable; member functions;
	Vertex();  // default constructor;
	Vertex(short id, double value ); // constructor with arguments;

	Vertex(const Vertex& other); // copy constructor

	virtual ~Vertex(); // indicate any clean up before the deleting of the object memory space;

	Vertex& operator=(const Vertex &other);
	bool operator==(const Vertex& other);

	void setId(short value);
	short getId() const; //not changing any data member;
	void setValue(double value);
	double getValue() const;


private:  //seperating the data storage and data access;
	short id;  // unique id;
	double value;    // value;
};

#endif
