#ifndef __Tree_HPP__
#define __Tree_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <bits/stdc++.h> 
#include "Node.hpp"
#include "Exceptions.hpp"
#include "Operator_Node.hpp"
#include "Integer_Node.hpp"

using namespace std;

#define DUMMY_ROOT 0
#define FAIL 0

class Duplicate_Id_Exception;
class Parent_Not_Exist;
class Invalid_Parent ;
class Number_Of_Operands_Exception;
class Node;
class Operator_Node;
class Add_Operator;
class Mult_Operator;
class Negative_Operator;
class Median_Operator;
class Integer_Node;

class Tree{
public:
	void add_operand_node(const int id, const int parent_id, const double value);
	void add_operator_node(const int id, const int parent_id, const OperatorType type);
	int find_index_of_node(int id);
	int evaluate_tree();
	bool check_duplicate_id(int id);
	void relate_nodes(Node* child_node, int parent_id);
	void relate_int_node_to_root(int index_of_root_node, Integer_Node* int_node);
	void delete_heap();
private:
	vector<Node*> nodes;
};

#endif