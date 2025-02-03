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
	bool insert(int data, Node node = root){
		if (node.data == data){}
	}
};


#endif //BINARYTREE_H
