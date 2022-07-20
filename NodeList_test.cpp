/*
 * NodeList_test.cpp
 *
 *  Created on: Jun. 29, 2022
 *      Author: liu
 */

#include "NodeList.h"
#include <iostream>

void testAddNode(){

	NodeList nList;
	for(int i=0;i<10;i++){
		Node d;
		nList.addNode(d);

	}

    int actual = nList.getNumItems();
    int expect = 10;
    if(actual == 10 ) // check the assertion
    	std::cout << "pass" << std::endl;
    else
    	std::cout << "fail" << std::endl;


}
