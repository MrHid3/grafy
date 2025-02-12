#ifndef NODE_H
#define NODE_H

class Node{
public:
	Node* ancestor;
	Node* right;
	Node* left;
	int data;
	Node(){
		right = nullptr;
		left = nullptr;
		data = 0;
	}
	Node(int data, Node* ancestor = nullptr){
		this->data = data;
		right = nullptr;
		left = nullptr;
	}

	bool insert(int data){
		if (this->data == data){
			return 0;
		}else if (this->data > data){
			if (this->right == nullptr){
				this->right = new Node(data, this);
				return 1;
			}else{
				return this->right->insert(data);
			}
		}else{
			if (this->left == nullptr){
				this->left = new Node(data, this);
				return 1;
			}else{
				return this->left->insert(data);
			}
		}
	};

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

	Node *succesor() {
		if(this->right != nullptr) {
			return this->right;
		}
		Node *curr = this;
		while(curr->ancestor->left != curr) {
			curr = curr->ancestor;
		}
		return curr->ancestor;
	}

	std::vector<int> preorder() {
		std::vector<int> result;
		result.push_back(this->data);
		if(this->left != nullptr) {
			result.insert(result.end, this->left->preorder().begin(), this->left->preorder().end());
		}
		if(this->right != nullptr) {
			result.insert(result.end, this->right->preorder().begin(), this->right->preorder().end());
		}
		return result;
	}

	std::vector<int> inorder() {
		std::vector<int> result;
		if(this->left != nullptr) {
			result.insert(result.end, this->left->preorder().begin(), this->left->preorder().end());
		}
		result.push_back(this->data);
		if(this->right != nullptr) {
			result.insert(result.end, this->right->preorder().begin(), this->right->preorder().end());
		}
		return result;
	}

	std::vector<int> postorder() {
		std::vector<int> result;
		if(this->left != nullptr) {
			result.insert(result.end, this->left->preorder().begin(), this->left->preorder().end());
		}
		if(this->right != nullptr) {
			result.insert(result.end, this->right->preorder().begin(), this->right->preorder().end());
		}
		result.push_back(this->data);
		return result;
	}
};

#endif //NODE_H
