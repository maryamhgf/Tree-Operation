#include "Node.hpp"

using namespace std;

#define DUMMY_ROOT 0
#define FAIL 0

Node::Node(int _id, int _parent_id) {
	if(_id == -1) {
		throw Duplicate_Id_Exception();
	}
	if(_parent_id == -1) {
		throw Parent_Not_Exist();
	}
	id = _id;
	parent_id = _parent_id;
	value = 0;
}

void Node::set_root(Node* root) {
	root_node = root;
}
