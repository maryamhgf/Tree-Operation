#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <bits/stdc++.h> 
#include "Exceptions.hpp"

class Tree;
class Duplicate_Id_Exception ;
class Parent_Not_Exist ;
class Invalid_Parent ;
class Number_Of_Operands_Exception ;

using namespace std;

#define DUMMY_ROOT 0
#define FAIL 0

class Node {
public:
	Node(int _id, int _parent_id);
	virtual double eval() {return value;};
	virtual void update_value() {}
	void set_root(Node* root);
	friend class Tree;
protected:
	int id;
	int parent_id;
	double value;
	Node* root_node;
};

#endif