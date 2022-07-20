/*
 * Node_test.cpp
 *
 *  Created on: Jun. 27, 2022
 *      Author: liu
 */

#include "Node.h"
#include <iostream>
using namespace std;


void testGetSetId(){
	 Node v;  // invoke on the function Node() default constructor;

	 v.setId(1);

	 short expected = 1;

	 if(v.getId () == expected  )
	   cout << "PASS " << endl;
}


void testGetSetWeight(){
   Node v;
   v.setWeight(5.0);
}


void testClone(){
  Node v; //default constructor of Node is invoked

  v.setId(5);
  short expected = 5;
  if (v.clone().getId() == expected)
	  cout << "clone test PASS " << endl;
   //destructor of v is invoked
}

void testConstructorWArgs(){
	Node v(5, 3.0);
}

void testCopyConstructor(){
	Node v1(5, 3.0);
	Node v2(v1);
}


void testObjCount(){

	Node v1(5, 3.0); //constructor with args of Node is invoked

	Node v2;
	v2 = v1.clone(); //default constructor of Node is invoked



	Node v3(v2); //default constructor of Node is invoked


	cout << Node::getObjCount() << " objects of Node is still live!" << endl;
	// no difference on the instance level, all the instance share the same function
	// static occurs at the class level;

    // v1. v2 destructors being invovked.

}

void testOpAssignment(){
	Node v1(35, 35.00);
	Node v2;
	v2 = v1;

	Node v3 = v2;

	cout << "Node id is " <<v2.getId() << endl;
	cout << Node::getObjCount() << " objects of Node is still live!" << endl;


}


int main(){
	//testGetSetId();
	//testGetSetWeight();
	//testClone();
	//testConstructorWArgs();
	//testCopyConstructor();
	//testObjCount();
	testOpAssignment();


}

