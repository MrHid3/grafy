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

	bool insert(int data){
		if (this->data == data){
			return 0;
		}else if (this->data > data){
			if (this->right == nullptr){
				this->right = new Node(data);
				return 1;
			}else{
				return this->right->insert(data);
			}
		}else{
			if (this->left == nullptr){
				this->left = new Node(data);
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

	void print() {

		if (this->left != nullptr) {
			// std:: cout << "lewo: ";
			this->left->print();
		}
		if (this->right != nullptr) {
			// std:: cout << "prawo: ";
			this->right->print();
		}
		std::cout << this-> data << "\n";
	}
};

#endif //NODE_H
