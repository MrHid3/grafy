#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>

class BinaryTree{
public:
	BinaryTree* ancestor;
	BinaryTree* right;
	BinaryTree* left;
	int data;
	BinaryTree(){
		right = nullptr;
		left = nullptr;
		data = 0;
		ancestor = nullptr;
	}
	BinaryTree(int data, BinaryTree *ancestor = nullptr){
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
		this->ancestor = ancestor;
	}
	BinaryTree(std::vector<int>data, BinaryTree *ancestor = nullptr) {
		this->right = nullptr;
		this->left = nullptr;
		this->ancestor = ancestor;
		if (data.size() > 0) {
			this->data = data[0];
			for (int i = 1; i < std::size(data); i++) {
				this->insert(data[i]);
			}
		} else {
			BinaryTree();
		}
	}
	bool insert(int data){
		if (this->data == data){
			return 0;
		}else if (this->data > data){
			if (this->right == nullptr){
				this->right = new BinaryTree(data, this);
				return 1;
			}else{
				return this->right->insert(data);
			}
		}else{
			if (this->left == nullptr){
				this->left = new BinaryTree(data, this);
				return 1;
			}else{
				return this->left->insert(data);
			}
		}
	}
	BinaryTree leftmost() {
		BinaryTree curr = *this;
		while(curr.left != nullptr) {
			curr = *curr.left;
		}
		return curr;
	}
	int rightmost() {
		BinaryTree curr = *this;
		while(curr.right != nullptr) {
			curr = *curr.right;
		}
		return curr.data;
	}
	bool find(int data) {
		BinaryTree curr = *this;
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
	BinaryTree *succesor() {
		if(this->right != nullptr) {
			return this->right;
		}
		BinaryTree *curr = this;
		while(curr->ancestor->left != curr) {
			curr = curr->ancestor;
		}
		return curr->ancestor;
	}
	std::vector<int> inorder() {
		std::vector<int> result;
		if(this->left != nullptr) {
			result.insert(result.end(), this->left->preorder().begin(), this->left->preorder().end());
		}
		result.push_back(this->data);
		if(this->right != nullptr) {
			result.insert(result.end(), this->right->preorder().begin(), this->right->preorder().end());
		}
		return result;
	}
	std::vector<int> & preorder(){
		std::vector<int> result;
		result.push_back(this->data);
		;
		if(this->left != nullptr) {
			std::vector<int> left = this->left->preorder();
			result.insert(result.end(), left.begin(), left.end());
		}
		if(this->right != nullptr) {
			std::vector<int> right = this->right->preorder();
			result.insert(result.end(), right.begin(), right.end());
		}
		return result;
	}
	std::vector<int> postorder() {
		std::vector<int> result;
		if(this->left != nullptr) {
			result.insert(result.end(), this->left->preorder().begin(), this->left->preorder().end());
		}
		if(this->right != nullptr) {
			result.insert(result.end(), this->right->preorder().begin(), this->right->preorder().end());
		}
		result.push_back(this->data);
		return result;
	}
	std::vector<int> inorderIterative() {
		std::vector<int> result;
		BinaryTree curr = this->leftmost();
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
	bool destroy(int data){
		if (this->data == data) {
			if (this->right == nullptr && this->left == nullptr) {
				delete this;
				return 1;
			} else if (this->right == nullptr){
				this->data = this->left->data;
				this->left = nullptr;
				return 1;
			} else if (this->left == nullptr) {
				this->data = this->right->data;
				this->right = nullptr;
				return 1;
			} else {
				this->data = this->right->data;
				this->right->destroy(this->right->data);
				return 1;
			}
		} else if (this->data < data) {
			if (this->right != nullptr) {
				return this->right->destroy(data);
			} else {
				return 0;
			}
		} else {
			if (this->left != nullptr) {
				return this->left->destroy(data);
			} else {
				return 0;
			}
		}
	};
};


#endif //BINARYTREE_H
