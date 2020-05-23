#ifndef __INTEGER_NODE_HPP__
#define __INTEGER_NODE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <bits/stdc++.h> 
#include "Node.hpp"
#include "Tree.hpp"
#include "Exceptions.hpp"

using namespace std;

#define DUMMY_ROOT 0
#define FAIL 0

class Node;
class Tree;
class Duplicate_Id_Exception ;
class Parent_Not_Exist ;
class Invalid_Parent ;
class Number_Of_Operands_Exception ;

class Integer_Node : public Node {
public:
	Integer_Node(double integer_value, int parent_id_of_int_node, int integer_node_id);
	friend class Tree;
	void update_value();
	double eval();
};


#endif