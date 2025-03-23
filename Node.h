#ifndef NODE_H
#define NODE_H

class Node{
public:
	Node* ancestor;
	int data;
	Node* right;
	Node* left;
	Node* root;
	bool isRight;

	Node(){
		this->right = nullptr;
		this->left = nullptr;
		this->data = 0;
		this->ancestor = nullptr;
		this->root = nullptr;
		isRight = false;
	}

	Node(int data, Node* root, Node* ancestor = nullptr, bool isRight = false){
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
		this->ancestor = ancestor;
		this->root = root;
		this->isRight = isRight;
	}

	void rightRotate(){
		Node* temp = nullptr;
		if (this->right)
			temp = this->right;
		this->right = this->ancestor;
		if (temp)
			temp->ancestor = this->right;
		this->right->left = temp;
		this->ancestor = this->right->ancestor;
		this->right->ancestor = this;
		if (this->ancestor != nullptr)
			if (this->right->isRight)
				this->ancestor->right = this;
			else
				this->ancestor->left = this;
		else{
			this->right->root = this;
			this->root = nullptr;
			this->ancestor = nullptr;
		}
		this->right->isRight = true;
		if (this->root == nullptr)
			this->setRoot(this);
	}

	void leftRotate(){
		Node* temp = nullptr;
		if (this->left)
			temp = this->left;
		this->left = this->ancestor;
		if (temp)
			temp->ancestor = this->left;
		this->left->right = temp;
		this->ancestor = this->left->ancestor;
		this->left->ancestor = this;
		if (this->left != this->root)
			if (this->left->isRight)
				this->ancestor->right = this;
			else
				this->ancestor->left = this;
		else{
			this->right->root = this;
			this->root = nullptr;
			this->left->root = this;
			this->ancestor = nullptr;
		}
		this->left->isRight = false;
		if (this->root == nullptr)
			this->setRoot(this);
	}

	void autobalance(){
		if (this->balance() >= -1 && this->balance() <= 1)
			return;
		if (this->balance() == -2){
			if (this->right->balance() < 0){
				this->right->leftRotate();
				return;
			}
			if (this->right->balance() > 0){
				this->right->left->rightRotate();
				this->right->leftRotate();
				return;
			}
		}
		if (this->balance() == 2){
			if (this->left->balance() > 0){
				this->left->rightRotate();
				return;
			}
			if (this->left->balance() < 0){
				this->left->right->leftRotate();
				this->left->rightRotate();
				return;
			}
		}
	}

	int height(){
		if (this->left != nullptr && this->right != nullptr)
			return std::max(this->left->height(), this->right->height()) + 1;
		if (this->left != nullptr)
			return this->left->height() + 1;
		if (this->right != nullptr)
			return this->right->height() + 1;
		return 1;
	}

	int balance(){
		int leftHeight = 0;
		int rightHeight = 0;
		if (this->left != nullptr)
			leftHeight = this->left->height();
		if (this->right != nullptr)
			rightHeight = this->right->height();
		return leftHeight - rightHeight;
	}

	void insert(int data){
		if (this->data == data)
			return;
		if (this->data < data){
			if (this->right == nullptr)
				this->right = new Node(data, (this->root == nullptr? this: this->root), this, true);
			else
				this->right->insert(data);
		}
		else if (this->left == nullptr)
			this->left = new Node(data, (this->root == nullptr? this: this->root), this, false);
		else
			this->left->insert(data);
		this->autobalance();
	};

	void setRoot(Node* root){
		if (this->ancestor == nullptr)
			this->root = nullptr;
		else
			this->root = root;
		if (this->right != nullptr)
			this->right->setRoot(root);
		if (this->left != nullptr)
			this->left->setRoot(root);
	};

	bool destroy(int data){
		if (this->data == data) {
			if (this->right == nullptr && this->left == nullptr) {
				if (this->isRight)
					this->ancestor->right = nullptr;
				else
					this->ancestor->left = nullptr;
			} else if (this->right == nullptr){
				this->left->ancestor = this->ancestor;
				if (this->isRight)
					this->ancestor->right = this->left;
				else
					this->ancestor->left = this->left;
				this->left = nullptr;
				return 1;
			} else if (this->left == nullptr) {
				this->right->ancestor = this->ancestor;
				if (this->isRight)
					this->ancestor->right = this->right;
				else
					this->ancestor->left = this->right;
				this->right = nullptr;
				return 1;
			} else {
				this->data = this->right->data;
				this->right->destroy(this->right->data);
				return 1;
			}
		} else if (this->data < data) {
			if (this->right != nullptr)
				return this->right->destroy(data);
			return 0;
		} else {
			if (this->left != nullptr)
				return this->left->destroy(data);
			return 0;
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