#ifndef NODE_H
#define NODE_H

class Node{
public:
	Node* ancestor;
	int data;
	Node* right;
	Node* left;
	Node* root;

	Node(){
		this->right = nullptr;
		this->left = nullptr;
		this->data = 0;
		this->ancestor = nullptr;
		this->root = nullptr;
	}

	Node(int data, Node* ancestor = nullptr, Node* root = nullptr){
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
		this->ancestor = ancestor;
		this->root = nullptr;
	}

	void rightRotate(){
		// Node* temp = this->right;
		// this->right = this->ancestor;
		// this->ancestor = this->right->ancestor;
		// this->right->ancestor = this;
		// temp->ancestor = this->right;
		// this->right->left = temp;
		Node* temp = nullptr;
		if (this->right)
			temp = this->right;
		this->right = this->ancestor;
		if (this->right->ancestor != nullptr){
			this->ancestor = this->right->ancestor;
			this->ancestor->left = this;
		}
		if (temp){
			temp->ancestor = this->right;
			this->right->left = temp;
		}
		this->right->ancestor = this;
	}

	void leftRotate(){
		Node* temp = nullptr;
		if (this->left)
			temp = this->left;
		this->left = this->ancestor;
		if (this->left->ancestor != nullptr){
			this->ancestor = this->left->ancestor;
			this->ancestor->right = this;
		}
		if (temp){
			temp->ancestor = this->left;
			this->left->right = temp;
		}
		this->left->ancestor = this;
	}

	bool insert(int data){
		if (this->data == data)
			return 0;
		if (this->data < data){
			if (this->right == nullptr){
				this->right = new Node(data, this);
				return 1;
			}
			return this->right->insert(data);
		}
		if (this->left == nullptr){
			this->left = new Node(data, this);
			return 1;
		}
		return this->left->insert(data);
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
			std::vector<int> left = this->left->preorder();
			result.insert(result.end(), left.begin(), left.end());
		}
		if(this->right != nullptr) {
			std::vector<int> right = this->right->preorder();
			result.insert(result.end(), right.begin(), right.end());
		}
		return result;
	}

	std::vector<int> inorder() {
		std::vector<int> result;
		if(this->left != nullptr) {
			std::vector<int> left = this->left->inorder();
			result.insert(result.end(), left.begin(), left.end());
		}
		result.push_back(this->data);
		if(this->right != nullptr) {
			std::vector<int> right = this->right->inorder();
			result.insert(result.end(), right.begin(), right.end());
		}
		return result;
	}

	std::vector<int> postorder() {
		std::vector<int> result;
		if(this->left != nullptr) {
			std::vector<int> left = this->left->postorder();
			result.insert(result.end(), left.begin(), left.end());
		}
		if(this->right != nullptr) {
			std::vector<int> right = this->right->postorder();
			result.insert(result.end(), right.begin(), right.end());
		}
		result.push_back(this->data);
		return result;
	}
};

#endif //NODE_H