#include "Operator_Node.hpp"


using namespace std;

#define DUMMY_ROOT 0
#define FAIL 0

Operator_Node::Operator_Node(char type, int operator_id, int parent_id_of_operator) : Node(operator_id, parent_id_of_operator) {
	operatorType = type;
}

Binary_Node:: Binary_Node(char type, int operator_id, int parent_id_of_operator) : Operator_Node(type, operator_id, parent_id_of_operator){
	value = 0;
	left = NULL;
	right = NULL;
}

Add_Operator::Add_Operator(char type, int operator_id, int parent_id_of_operator) : Binary_Node(type, operator_id, parent_id_of_operator){

}

double Add_Operator::eval() {
	if(left == NULL && right == NULL){
		value = 0;
		return value;
	}
	if(left == NULL) {
		value = right->eval();
		return value;
	}
	if(right == NULL) {
		value = left->eval();
		return value;
	}
	value = left->eval() + right->eval();
	return value;
}

void Add_Operator::update_value() {
	if(left == NULL && right == NULL){
		value = 0;
	}
	else if(left == NULL) {
		value = right->eval();
	}
	else if(right == NULL) {
		value = left->eval();
	}
	else
		value = left->eval() + right->eval();
}


Mult_Operator::Mult_Operator(char type, int operator_id, int parent_id_of_operator) : Binary_Node(type, operator_id, parent_id_of_operator) {

}

double Mult_Operator::eval() {
	if(left == NULL && right == NULL){
		value = 0;
	}
	else if(left == NULL) {
		value = right->eval();
	}
	else if(right == NULL) {
		value = left->eval();
	}
	else
		value = left->eval() * right->eval();
	return value;
}

void Mult_Operator::update_value() {
	if(left == NULL && right == NULL)
		value = 0;
	else if(left == NULL) 
		value = right->eval();
	else if(right == NULL) 
		value = left->eval();
	else
		value = left->eval() * right->eval();		
}


Negative_Operator::Negative_Operator(char type, int operator_id, int parent_id_of_operator) : Operator_Node(type, operator_id, parent_id_of_operator) {
	positive_node = NULL;
}

double Negative_Operator::eval() {
	if(positive_node == NULL) {
		value = 0;
	}
	else
		value = -1 * positive_node->eval();
	return value;
}

void Negative_Operator::update_value() {
	if(positive_node == NULL) {
		value = 0;
		return;
	}
	value = -1 * positive_node->eval();
	return;
}

double find_median(int a[], int n) {  
    sort(a, a+n); 
    if (n % 2 != 0) 
       return (double)a[n/2]; 
      
    return (double)(a[(n-1)/2] + a[n/2])/2.0; 
} 

Median_Operator::Median_Operator(char type, int operator_id, int parent_id_of_operator) : Operator_Node(type, operator_id, parent_id_of_operator) {

}

double Median_Operator::eval() {
	int size = nodes_connected.size();
	int value_array[size];
	for(int i = 0; i < size; i++) 
		value_array[i] = nodes_connected[i]->eval();
	value = find_median(value_array, size);	
	return value;
}

void Median_Operator::update_value() {
	int size = nodes_connected.size();
	int value_array[size];
	for(int i = 0; i < size; i++) 
		value_array[i] = nodes_connected[i]->eval();
	value = find_median(value_array, size);	
}

