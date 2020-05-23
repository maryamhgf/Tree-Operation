#ifndef __OPERATOR_NODE_HPP__
#define __OPERATOR_NODE_HPP__

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

class Operator_Node : public Node {
public:
	 Operator_Node(char type, int operator_id, int parent_id_of_operator);
	 friend class Tree;
protected:
	char operatorType;
};

class Binary_Node : public Operator_Node {
public:
	Binary_Node(char type, int operator_id, int parent_id_of_operator);
	friend class Tree;
protected:
	Node* left;
	Node* right;
};



class Add_Operator : public Binary_Node {
public:
	Add_Operator(char type, int operator_id, int parent_id_of_operator);
	double eval();
	void update_value();
	friend class Tree;
};

class Mult_Operator : public Binary_Node {
public:
	Mult_Operator(char type, int operator_id, int parent_id_of_operator);
	double eval();
	void update_value();
	friend class Tree;
};

class Negative_Operator : public Operator_Node {
public:
	Negative_Operator(char type, int operator_id, int parent_id_of_operator);
	double eval();
	void update_value();
	friend class Tree;
private:
	Node* positive_node;
};

class Median_Operator : public Operator_Node {
public:
	Median_Operator(char type, int operator_id, int parent_id_of_operator);
	double eval();
	void update_value();
	friend class Tree;
private:
	vector<Node*> nodes_connected;
};

#endif