#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template<typename TInfo>
struct LinkedList {

	public:

		struct Node {
				TInfo info;
				Node* next;

				Node(TInfo _info, Node* _next = nullptr) :
						info(_info), next(_next) {
				}
		};

		LinkedList();
		~LinkedList();

		Node* append(TInfo info);
		Node* insert(Node* node, TInfo info);
		Node* prepend(TInfo info);

		TInfo remove(Node* node);

		int size() const;

		Node* begin();
		Node* last();

	private:
		Node* begin_;
		Node* last_;
		int size_;
};

template<typename TInfo>
LinkedList<TInfo>::LinkedList() :
		begin_(nullptr), last_(nullptr), size_(0) {
}

template<typename TInfo>
LinkedList<TInfo>::~LinkedList() {
	while (begin_ != nullptr) {
		Node* next_node = begin_->next;
		delete begin_;
		begin_ = next_node;
	}
}

template<typename TInfo>
typename LinkedList<TInfo>::Node* LinkedList<TInfo>::append(TInfo info) {
	Node* new_node = new Node(info);

	if (begin_ == nullptr)
		begin_ = new_node;
	else
		last_->next = new_node;

	last_ = new_node;

	size_ += 1;

	return new_node;
}

template<typename TInfo>
typename LinkedList<TInfo>::Node* LinkedList<TInfo>::insert(LinkedList<TInfo>::Node* node, TInfo info) {
	Node* new_node = new Node(info);

	new_node->next = node->next;
	node->next = new_node;

	if (node == last_)
		last_ = new_node;

	size_ += 1;

	return new_node;
}

template<typename TInfo>
typename LinkedList<TInfo>::Node* LinkedList<TInfo>::prepend(TInfo info) {
	Node* new_node = new Node(info);

	new_node->next = begin_;
	begin_ = new_node;

	size_ += 1;

	return new_node;
}

template<typename TInfo>
TInfo LinkedList<TInfo>::remove(typename LinkedList<TInfo>::Node* node) {
	TInfo info = node->info;

	if (node != begin_) {
		Node* previous_node;
		for (previous_node = begin_; previous_node->next != node; previous_node = previous_node->next)
			;

		previous_node->next = node->next;

	} else {
		begin_ = node->next;
	}

	delete node;

	size_ -= 1;

	return info;
}

template<typename TInfo>
int LinkedList<TInfo>::size() const {
	return size_;
}

template<typename TInfo>
typename LinkedList<TInfo>::Node* LinkedList<TInfo>::begin() {
	return begin_;
}

template<typename TInfo>
typename LinkedList<TInfo>::Node* LinkedList<TInfo>::last() {
	return last_;
}

#endif /* LINKEDLIST_H_ */
