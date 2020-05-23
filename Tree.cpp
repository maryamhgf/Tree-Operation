#include "Tree.hpp"

using namespace std;

#define DUMMY_ROOT 0
#define FAIL 0
#define NOT_FOUND -1
#define NEW 0
#define DUPLICATE 1
#define ADD '+'
#define MULTIPLY '*'
#define MEDIAN 'M'
#define NOT '-'

void Tree::delete_heap() {
	for(int i = 0; i<nodes.size(); i++)
		delete nodes[i];
}

void node_update_value(Node* node) {
	if(Binary_Node* binary_node = dynamic_cast <Binary_Node*> (node) ){
		if(Add_Operator* add_node = dynamic_cast <Add_Operator*> (binary_node)) {
			add_node -> update_value();
		}
		if(Mult_Operator* mult_Node = dynamic_cast <Mult_Operator*> (binary_node)) {
			mult_Node -> update_value();
		}
	}
	else if(Negative_Operator* negative_node = dynamic_cast <Negative_Operator*> (node)) {
		negative_node -> update_value();
	}
	else if(Median_Operator* median_node = dynamic_cast <Median_Operator*> (median_node)) {
	}
}

int Tree::find_index_of_node(int id) {
	if(id == NOT_FOUND) {
		throw Parent_Not_Exist();
	}
	for(int i = 0; i< nodes.size(); i++) {
		if( id == nodes[i]->id ){
			return i;
		}
	}
	return NOT_FOUND;
}

bool Tree::check_duplicate_id(int id) {
	for(int i = 0; i < nodes.size() ; i++) {
		if(id == nodes[i]->id) {
			return DUPLICATE;
		}
	}
	return NEW;
}

void Tree::relate_int_node_to_root(int index_of_root_node, Integer_Node* int_node) {
	if(Binary_Node* root_operator_node = dynamic_cast <Binary_Node*>(nodes[index_of_root_node])) {
		if(root_operator_node->right == NULL){
			root_operator_node->right = int_node;
		}
		else if(root_operator_node->left == NULL)
			root_operator_node->left = int_node;
		else
			throw Number_Of_Operands_Exception();
	}
	else if(Negative_Operator* root_operator_node = dynamic_cast <Negative_Operator*> (nodes[index_of_root_node])) {
		if(root_operator_node -> positive_node != NULL)
			throw Number_Of_Operands_Exception();
		root_operator_node -> positive_node = int_node;
	}
	else if(Median_Operator* root_operator_node = dynamic_cast <Median_Operator*> (nodes[index_of_root_node])) {
		root_operator_node -> nodes_connected.push_back(int_node);
	}
	else if(Integer_Node* root_operator_node = dynamic_cast <Integer_Node*> (nodes[index_of_root_node])) {
		throw Invalid_Parent();
	}
}

void Tree::add_operand_node(const int id, const int parent_id, const double value) {
	try {
		int id_to_creat;
		int parent_id_to_creat;
		if(check_duplicate_id(id))
			id_to_creat = NOT_FOUND;
		else
			id_to_creat = id;
		if(find_index_of_node(parent_id) == NOT_FOUND)
			parent_id_to_creat = NOT_FOUND;
		else
			parent_id_to_creat = parent_id;
		Integer_Node* int_node = new Integer_Node(value, parent_id_to_creat, id_to_creat);
		int index_of_root_node = find_index_of_node(parent_id_to_creat);
		int_node->set_root(nodes[index_of_root_node]);
		int_node->update_value();
		relate_int_node_to_root(index_of_root_node, int_node);
		node_update_value(nodes[index_of_root_node]);
		nodes.push_back(int_node);
		} catch(exception& new_exception) {
			cout<< new_exception.what()<<endl;
			delete_heap();
			exit(FAIL);
			return;
	}
}

void Tree::relate_nodes(Node* child_node, int parent_id){
	int index_of_root_node = find_index_of_node(parent_id);
	if(parent_id != DUMMY_ROOT) {
		if(index_of_root_node == NOT_FOUND)
			throw Parent_Not_Exist();
		if(Integer_Node* root_operator_node = dynamic_cast <Integer_Node*> (nodes[index_of_root_node])) 
			throw Invalid_Parent();
	}
	child_node -> set_root(nodes[index_of_root_node]);	
	if(Binary_Node* root_operator_node = dynamic_cast <Binary_Node*>(nodes[index_of_root_node])) {
		if(root_operator_node -> right == NULL) {
			root_operator_node -> right = child_node;
		}
		else if(root_operator_node -> left == NULL) {
			root_operator_node -> left = child_node;
		}
		else
			throw Number_Of_Operands_Exception();
		root_operator_node -> update_value();
	}
	else if(Negative_Operator* root_operator_node = dynamic_cast <Negative_Operator*> (nodes[index_of_root_node])) {
		if(root_operator_node -> positive_node != NULL) 
			throw Number_Of_Operands_Exception();
		root_operator_node -> positive_node = child_node;
		root_operator_node -> update_value();
	}
	else if(Median_Operator* root_operator_node = dynamic_cast <Median_Operator*> (nodes[index_of_root_node])) {
		root_operator_node -> nodes_connected.push_back(child_node);
		root_operator_node -> update_value();
	}
}

void Tree::add_operator_node(const int id, const int parent_id, const OperatorType type) {
	try {
		int id_to_creat;
		if(check_duplicate_id(id)) 
			id_to_creat = NOT_FOUND;
		else
			id_to_creat = id;
		char operType;
		int index_of_root_node = find_index_of_node(parent_id);
		if(type == Add) {
			operType = ADD;
			Add_Operator* add_node = new Add_Operator(operType, id_to_creat, parent_id);
			if(parent_id == DUMMY_ROOT)
				add_node -> set_root(NULL);
			if(parent_id != DUMMY_ROOT)
				relate_nodes(add_node, parent_id);
			add_node -> update_value();
			nodes.push_back(add_node);
		}
		
		
		else if(type == Multiply) {
			operType = Multiply;
			Mult_Operator* mult_node = new Mult_Operator(operType, id_to_creat, parent_id);
			if(parent_id == DUMMY_ROOT) {
				mult_node -> set_root(NULL);
			}
			if(parent_id != DUMMY_ROOT) 
				relate_nodes(mult_node, parent_id);
			mult_node -> update_value();
			nodes.push_back(mult_node);
			
		}
		
		else if(type == Not) {
			operType = NOT;
			Negative_Operator* negative_node = new Negative_Operator(operType, id_to_creat, parent_id);
			if(parent_id == DUMMY_ROOT) {
				negative_node -> set_root(NULL);
			}
			if(parent_id != DUMMY_ROOT) {
				relate_nodes(negative_node, parent_id);
			}
			negative_node -> update_value();
			nodes.push_back(negative_node);
		}
		
		else if(type == Median) {
			operType = MEDIAN;
			Median_Operator* median_node = new Median_Operator(operType, id_to_creat, parent_id);
			if(parent_id == DUMMY_ROOT) {
				median_node -> set_root(NULL);
			}
			if(parent_id != DUMMY_ROOT) 
				relate_nodes(median_node, parent_id);
			median_node -> update_value();
			nodes.push_back(median_node);
		}
	} catch(exception& new_exception) {
		cout<< new_exception.what()<<endl;
		delete_heap();
		exit(FAIL);
		return;
	}
}

int Tree::evaluate_tree() {
	for(int i = 0; i < nodes.size(); i++) {
		nodes[i] -> update_value();
	}
	for(int i = 0; i<nodes.size(); i++) {
		if(nodes[i] -> root_node == NULL){
			return nodes[i] -> value;
		}
	}
}
