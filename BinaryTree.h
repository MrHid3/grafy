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
	int leftmost() {
		Node curr = root;
		while(curr.left != nullptr) {
			curr = *curr.left;
		}
		return curr.data;
	}
	int rightmost() {
		Node curr = root;
		while(curr.right != nullptr) {
			curr = *curr.right;
		}
		return curr.data;
	}
	bool find(int data) {
		Node curr = root;
		while(true) {
			if(curr.data == data) {
				return 1;
			}
			if(curr.data < data) {
				if(curr.right != nullptr) {
					curr = *curr.right;
				}else return 0;
			}
			if (curr.data > data) {
				if(curr.left != nullptr) {
					curr = *curr.left;
				}else return 0;
			}
		};
	}
	std::vector<int> inorder() {
		return root.inorder();
	}
	std::vector<int> preorder() {
		return root.preorder();
	}
	std::vector<int> postorder() {
		return root.postorder();
	}
	std::vector<int> inorderIterative() {
		std::vector<int> result;
		Node curr = this->leftmost();
		while(true) {
			bool isThere = false;
			for(int i = 0; i < result.size(); i++) {
				if(curr.left->data == result[i]) {
					isThere = true;
					break;
				}
			}

			for(int i = 0; i < result.size(); i++) {
				if(curr.data == result[i]) {
					isThere = true;
					break;
				}
			}
			if(!isThere) {
				result.push_back(curr.data);
			}
		}
	}
};


#endif //BINARYTREE_H
