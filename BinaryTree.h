#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"

class BinaryTree{
public:
	Node root;
	BinaryTree(){
		root = Node();
	}
	BinaryTree(int data){
		root = Node(data);
	}
	BinaryTree(Node node){
		root = node;
	}
	BinaryTree(std::vector<int> data) {
		if (data.size() > 0) {
			this->root = Node(data[0]);
			for (int i = 1; i < data.size(); i++) {
				this->insert(data[i]);
			}
		} else {
			this->root = Node();
		}
	}
	bool insert(int data){
		return this->root.insert(data);
	}
	void print() {
		this->root.print();
	}
};


#endif //BINARYTREE_H
