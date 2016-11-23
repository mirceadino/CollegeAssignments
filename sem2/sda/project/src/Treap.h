#ifndef TREAP_H_
#define TREAP_H_

#include <random>
#include <string>
#include <ctime>

template<typename TInfo>
struct Treap {

	public:

		struct Node {
				TInfo info;
				int priority;
				Node* father;
				Node* left_son;
				Node* right_son;

				Node(TInfo _info, int _priority, Node* _father = nullptr) :
						info(_info), priority(_priority), father(_father), left_son(nullptr), right_son(nullptr) {
				}
		};

		Treap();
		~Treap();

		int size() const;

		Node* find(TInfo info);
		Node* insert(TInfo info);
		void erase(Node* node);

		Node* root() {
			return root_;
		}

	private:
		Node* root_;
		int size_;
		std::random_device rand_;

		Node* find(Node* root, TInfo info);
		void insert(Node*& root, Node*& new_node);
		void erase(Node*& root, Node*& new_node);
		void balance(Node*& root);
		void rotate_left(Node*& root);
		void rotate_right(Node*& root);
};

template<typename TInfo>
Treap<TInfo>::Treap() :
		root_(nullptr), size_(0), rand_() {
}

template<typename TInfo>
Treap<TInfo>::~Treap() {
	while (root_)
		this->erase(root_);
}

template<typename TInfo>
int Treap<TInfo>::size() const {
	return size_;
}

template<typename TInfo>
typename Treap<TInfo>::Node* Treap<TInfo>::find(TInfo info) {
	return find(root_, info);
}

template<typename TInfo>
typename Treap<TInfo>::Node* Treap<TInfo>::find(typename Treap<TInfo>::Node* root, TInfo info) {
	if (root == nullptr)
		return root;

	if (root->info > info)
		return find(root->left_son, info);

	if (root->info < info)
		return find(root->right_son, info);

	return root;
}

template<typename TInfo>
typename Treap<TInfo>::Node* Treap<TInfo>::insert(TInfo info) {
	Node* new_node = new Node(info, rand_());

	if (root_ == nullptr) {
		root_ = new_node;
		size_ += 1;
		return new_node;
	}

	this->insert(root_, new_node);
	size_ += 1;

	return new_node;
}

template<typename TInfo>
void Treap<TInfo>::insert(typename Treap<TInfo>::Node*& root, typename Treap<TInfo>::Node*& new_node) {
	if (root->info > new_node->info) {
		if (root->left_son) {
			insert(root->left_son, new_node);
		} else {
			root->left_son = new_node;
			new_node->father = root;
		}

	} else if (root->info < new_node->info) {
		if (root->right_son) {
			insert(root->right_son, new_node);
		} else {
			root->right_son = new_node;
			new_node->father = root;
		}
	}

	balance(root);
}

template<typename TInfo>
void Treap<TInfo>::erase(typename Treap<TInfo>::Node* node) {
	if (node == nullptr)
		return;

	this->erase(root_, node);

	if (node->father) {
		if (node->father->left_son == node)
			node->father->left_son = nullptr;

		if (node->father->right_son == node)
			node->father->right_son = nullptr;
	}

	delete node;
	size_ -= 1;

	if (size_ == 0)
		root_ = nullptr;
}

template<typename TInfo>
void Treap<TInfo>::erase(typename Treap<TInfo>::Node*& root, typename Treap<TInfo>::Node*& removed_node) {
	if (root == nullptr)
		return;

	if (root->info > removed_node->info) {
		erase(root->left_son, removed_node);

	} else if (root->info < removed_node->info) {
		erase(root->right_son, removed_node);

	} else {
		if (root->left_son == nullptr && root->right_son == nullptr) {
			root = nullptr;
			return;
		}

		if (root->left_son == nullptr || (root->right_son && root->right_son < root->left_son)) {
			rotate_left(root);
			erase(root, removed_node);
			return;
		}

		if (root->right_son == nullptr || (root->left_son && root->left_son < root->right_son)) {
			rotate_right(root);
			erase(root, removed_node);
			return;
		}
	}

	balance(root);
}

template<typename TInfo>
void Treap<TInfo>::balance(typename Treap<TInfo>::Node*& root) {
	if (root->left_son && root->left_son->priority < root->priority)
		rotate_right(root);

	if (root->right_son && root->right_son->priority < root->priority)
		rotate_left(root);
}

template<typename TInfo>
void Treap<TInfo>::rotate_left(typename Treap<TInfo>::Node*& root) {
	Node* right_son = root->right_son;

	right_son->father = root->father;
	root->father = right_son;
	root->right_son = right_son->left_son;
	right_son->left_son = root;

	root = right_son;
}

template<typename TInfo>
void Treap<TInfo>::rotate_right(typename Treap<TInfo>::Node*& root) {
	Node* left_son = root->left_son;

	left_son->father = root->father;
	root->father = left_son;
	root->left_son = left_son->right_son;
	left_son->right_son = root;

	root = left_son;
}

#endif /* TREAP_H_ */
