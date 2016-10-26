#ifndef SORTEDMAPWITHBALANCEDTREE_H_
#define SORTEDMAPWITHBALANCEDTREE_H_

#include "Treap.h"
#include "Pair.h"

template<typename TKey, typename TValue>
class SortedMapWithBalancedTree {

	public:

		typedef Pair<TKey, TValue> TPair;

		class Iterator {

				friend SortedMapWithBalancedTree;

			public:
				Iterator(typename Treap<TPair>::Node * node = nullptr) :
						node_(node) {
				}

				Iterator(const Iterator& that) {
					node_ = that.node_;
				}

				Iterator& operator=(const Iterator& that) {
					node_ = that.node_;
					return *this;
				}

				~Iterator() {
				}

				bool operator==(const Iterator& that) {
					return node_ == that.node_;
				}

				bool valid() const {
					return node_ != nullptr;
				}

				Iterator next() const {
					typename Treap<TPair>::Node * current = node_;

					if (current->right_son) {
						current = current->right_son;
						while (current->left_son)
							current = current->left_son;
					} else {
						while (current->father && current == current->father->right_son)
							current = current->father;
						if (current->father)
							current = current->father;
						else
							current = nullptr;
					}

					return Iterator(current);
				}

				Iterator& operator++() {
					node_ = next().node_;
					return *this;
				}

				TKey key() const {
					return node_->info.first;
				}

				TValue& value() {
					return node_->info.second;
				}

				TPair getElement() const {
					return node_->info;
				}

			private:
				typename Treap<TPair>::Node* node_;
		};

		static const Iterator nullit;
		static const TValue nullval;

		SortedMapWithBalancedTree();
		SortedMapWithBalancedTree(const SortedMapWithBalancedTree<TKey, TValue>& that);
		SortedMapWithBalancedTree<TKey, TValue>& operator=(const SortedMapWithBalancedTree<TKey, TValue>& that);
		~SortedMapWithBalancedTree();

		bool empty() const;
		int size() const;
		void clear();

		Iterator begin() const;

		bool containsKey(const TKey key) const;
		TValue getValue(const TKey key) const;
		Iterator setValue(const TKey key, const TValue value);
		TValue& operator[](const TKey key);
		TValue& at(const TKey key);
		Iterator insert(const TKey key, const TValue value);
		void erase(const TKey key);
		void erase(Iterator& it);

	private:
		Treap<TPair>* elements_;
};

template<typename TKey, typename TValue>
const typename SortedMapWithBalancedTree<TKey, TValue>::Iterator SortedMapWithBalancedTree<TKey, TValue>::nullit = typename SortedMapWithBalancedTree<TKey, TValue>::Iterator(nullptr);

template<typename TKey, typename TValue>
const TValue SortedMapWithBalancedTree<TKey, TValue>::nullval = TValue();

template<typename TKey, typename TValue>
SortedMapWithBalancedTree<TKey, TValue>::SortedMapWithBalancedTree() {
	elements_ = new Treap<TPair>();
}

template<typename TKey, typename TValue>
SortedMapWithBalancedTree<TKey, TValue>::SortedMapWithBalancedTree(const SortedMapWithBalancedTree<TKey, TValue>& that) {
	if (this == &that)
		return;

	elements_ = new Treap<TPair>();

	for (Iterator current = that.begin(); current.valid(); ++current)
		elements_->insert(current.getElement());
}

template<typename TKey, typename TValue>
SortedMapWithBalancedTree<TKey, TValue>& SortedMapWithBalancedTree<TKey, TValue>::operator=(const SortedMapWithBalancedTree<TKey, TValue>& that) {
	if (this == &that)
		return;

	delete elements_;
	elements_ = new Treap<TPair>();

	for (Iterator current = that.begin(); current.valid(); ++current)
		elements_->insert(current.getElement());

	return *this;
}

template<typename TKey, typename TValue>
SortedMapWithBalancedTree<TKey, TValue>::~SortedMapWithBalancedTree() {
	delete elements_;
}

template<typename TKey, typename TValue>
bool SortedMapWithBalancedTree<TKey, TValue>::empty() const {
	return elements_->size() == 0;
}

template<typename TKey, typename TValue>
int SortedMapWithBalancedTree<TKey, TValue>::size() const {
	return elements_->size();
}

template<typename TKey, typename TValue>
void SortedMapWithBalancedTree<TKey, TValue>::clear() {
	delete elements_;

	elements_ = new Treap<TPair>();
}

template<typename TKey, typename TValue>
typename SortedMapWithBalancedTree<TKey, TValue>::Iterator SortedMapWithBalancedTree<TKey, TValue>::begin() const {
	typename Treap<TPair>::Node* current = elements_->root();

	while (current->left_son)
		current = current->left_son;

	return Iterator(current);
}

template<typename TKey, typename TValue>
bool SortedMapWithBalancedTree<TKey, TValue>::containsKey(const TKey key) const {
	return (elements_->find(TPair(key, nullval)) != nullptr);
}

template<typename TKey, typename TValue>
TValue SortedMapWithBalancedTree<TKey, TValue>::getValue(const TKey key) const {
	typename Treap<TPair>::Node* current = elements_->find(TPair(key, nullval));
	Iterator iterator(current);
	return iterator.value();
}

template<typename TKey, typename TValue>
typename SortedMapWithBalancedTree<TKey, TValue>::Iterator SortedMapWithBalancedTree<TKey, TValue>::setValue(const TKey key, const TValue value) {
	if (!this->containsKey(key))
		this->insert(key, nullval);

	typename Treap<TPair>::Node* current = elements_->find(TPair(key, nullval));
	Iterator iterator(current);
	iterator.value() = value;
	return iterator;
}

template<typename TKey, typename TValue>
TValue& SortedMapWithBalancedTree<TKey, TValue>::operator[](const TKey key) {
	if (!this->containsKey(key))
		this->insert(key, nullval);

	typename Treap<TPair>::Node* current = elements_->find(TPair(key, nullval));
	Iterator iterator(current);
	return iterator.value();
}

template<typename TKey, typename TValue>
TValue& SortedMapWithBalancedTree<TKey, TValue>::at(const TKey key) {
	return this->operator[](key);
}

template<typename TKey, typename TValue>
typename SortedMapWithBalancedTree<TKey, TValue>::Iterator SortedMapWithBalancedTree<TKey, TValue>::insert(const TKey key, const TValue value) {
	if (this->containsKey(key)) {
		typename Treap<TPair>::Node* current = elements_->find(TPair(key, nullval));
		Iterator iterator(current);
		return iterator;
	}

	return Iterator(elements_->insert(TPair(key, value)));
}

template<typename TKey, typename TValue>
void SortedMapWithBalancedTree<TKey, TValue>::erase(const TKey key) {
	if (!this->containsKey(key))
		return;

	elements_->erase(elements_->find(TPair(key, nullval)));
}

template<typename TKey, typename TValue>
inline void SortedMapWithBalancedTree<TKey, TValue>::erase(SortedMapWithBalancedTree<TKey, TValue>::Iterator& it) {
	if (!it.valid())
		return;

	elements_->erase(it.node_);
}

void test_SortedMapWithBalancedTree();

#endif /* SORTEDMAPWITHBALANCEDTREE_H_ */
