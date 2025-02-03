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
			}else{
				this->right->insert(data);
			}
		}else{
			if (this->left == nullptr){
				this->left = new Node(data);
			}else{
				this->left->insert(data);
			}
		}
	}
};

#endif //NODE_H
