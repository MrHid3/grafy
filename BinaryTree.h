#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <algorithm>

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
		std::vector<Node*> stack;
		Node *curr = &this->root;

		while (curr != nullptr || stack.size() != 0) {
			while (curr != nullptr) {
				stack.push_back(curr);
				curr = curr->left;
			}
			curr = stack[stack.size() - 1];
			stack.pop_back();
			result.push_back(curr->data);
			curr = curr->right;
		}

		return result;
	}

	void print(){
		std::vector<Node> list = {this->root};
		bool cont = true;
		while(cont){
			std::vector<Node> curr = list;
			cont = false;
			list = {};
			for (int i = 0; i < curr.size(); i++){
				std::cout << curr[i].data << " ";
				if(curr[i].left != nullptr){
					list.push_back(*curr[i].left);
					cont = true;
				}
				if(curr[i].right != nullptr){
					list.push_back(*curr[i].right);
					cont = true;
				}
			}
			std::cout << "\n";
		}
	}
};


#endif //BINARYTREE_H