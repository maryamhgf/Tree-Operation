#include "Integer_Node.hpp"

using namespace std;

#define DUMMY_ROOT 0
#define FAIL 0

Integer_Node::Integer_Node(double integer_value, int parent_id_of_int_node, int integer_node_id) : Node(integer_node_id, parent_id_of_int_node) {
	value = integer_value;
}

void Integer_Node::update_value() {

}

double Integer_Node::eval() {
	return value;
}