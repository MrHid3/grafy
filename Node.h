#ifndef NODE_H
#define NODE_H

class Node{
public:
	Node* right;
	Node* left;
	int data;
	Node(){
		right = nullptr;
		left = nullptr;
		data = 0;
	}
	explicit Node(int data){
		this->data = data;
		right = nullptr;
		left = nullptr;
	}
};

#endif //NODE_H
