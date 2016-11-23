#ifndef SORTEDMAPWITHLINKEDLIST_H_
#define SORTEDMAPWITHLINKEDLIST_H_

#include "LinkedList.h"
#include "Pair.h"

template<typename TKey, typename TValue>
class SortedMapWithLinkedList {

	public:

		typedef Pair<TKey, TValue> TPair;

		class Iterator {

				friend SortedMapWithLinkedList;

			public:
				Iterator(typename LinkedList<TPair>::Node * node = nullptr) :
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
					return Iterator(node_->next);
				}

				Iterator& operator++() {
					node_ = node_->next;
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
				typename LinkedList<TPair>::Node* node_;
		};

		static const Iterator nullit;
		static const TValue nullval;

		SortedMapWithLinkedList();
		SortedMapWithLinkedList(const SortedMapWithLinkedList<TKey, TValue>& that);
		SortedMapWithLinkedList<TKey, TValue>& operator=(const SortedMapWithLinkedList<TKey, TValue>& that);
		~SortedMapWithLinkedList();

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
		LinkedList<TPair>* elements_;
};

template<typename TKey, typename TValue>
const typename SortedMapWithLinkedList<TKey, TValue>::Iterator SortedMapWithLinkedList<TKey, TValue>::nullit = typename SortedMapWithLinkedList<TKey, TValue>::Iterator(nullptr);

template<typename TKey, typename TValue>
const TValue SortedMapWithLinkedList<TKey, TValue>::nullval = TValue();

template<typename TKey, typename TValue>
SortedMapWithLinkedList<TKey, TValue>::SortedMapWithLinkedList() {
	elements_ = new LinkedList<TPair>();
}

template<typename TKey, typename TValue>
SortedMapWithLinkedList<TKey, TValue>::SortedMapWithLinkedList(const SortedMapWithLinkedList<TKey, TValue>& that) {
	if (this == &that)
		return;

	elements_ = new LinkedList<TPair>();

	for (Iterator current = that.begin(); current.valid(); ++current)
		elements_->append(current.getElement());
}

template<typename TKey, typename TValue>
SortedMapWithLinkedList<TKey, TValue>& SortedMapWithLinkedList<TKey, TValue>::operator=(const SortedMapWithLinkedList<TKey, TValue>& that) {
	if (this == &that)
		return;

	delete elements_;
	elements_ = new LinkedList<TPair>();

	for (Iterator current = that.begin(); current.valid(); ++current)
		elements_->append(current.getElement());

	return *this;
}

template<typename TKey, typename TValue>
SortedMapWithLinkedList<TKey, TValue>::~SortedMapWithLinkedList() {
	delete elements_;
}

template<typename TKey, typename TValue>
bool SortedMapWithLinkedList<TKey, TValue>::empty() const {
	return elements_->size() == 0;
}

template<typename TKey, typename TValue>
int SortedMapWithLinkedList<TKey, TValue>::size() const {
	return elements_->size();
}

template<typename TKey, typename TValue>
void SortedMapWithLinkedList<TKey, TValue>::clear() {
	delete elements_;

	elements_ = new LinkedList<TPair>();
}

template<typename TKey, typename TValue>
typename SortedMapWithLinkedList<TKey, TValue>::Iterator SortedMapWithLinkedList<TKey, TValue>::begin() const {
	return Iterator(elements_->begin());
}

template<typename TKey, typename TValue>
bool SortedMapWithLinkedList<TKey, TValue>::containsKey(const TKey key) const {
	if (this->empty())
		return false;

	for (Iterator current = begin(); current.valid() && current.key() <= key; ++current)
		if (current.key() == key)
			return true;

	return false;
}

template<typename TKey, typename TValue>
TValue SortedMapWithLinkedList<TKey, TValue>::getValue(const TKey key) const {
	for (Iterator current = begin(); current.valid() && current.key() <= key; ++current)
		if (current.key() == key)
			return current.value();

	return nullval;
}

template<typename TKey, typename TValue>
typename SortedMapWithLinkedList<TKey, TValue>::Iterator SortedMapWithLinkedList<TKey, TValue>::setValue(const TKey key, const TValue value) {
	if (!this->containsKey(key))
		this->insert(key, nullval);

	for (Iterator current = begin(); current.valid() && current.key() <= key; ++current)
		if (current.key() == key) {
			current.value() = value;
			return current;
		}

	// Control will never reach the following line, it is written just to shut up compiler's complains.
	return nullit;
}

template<typename TKey, typename TValue>
TValue& SortedMapWithLinkedList<TKey, TValue>::operator[](const TKey key) {
	if (!this->containsKey(key))
		this->insert(key, nullval);

	for (Iterator current = begin(); current.valid() && current.key() <= key; ++current)
		if (current.key() == key)
			return current.value();

	// Control will never reach the following line, it is written just to shut up compiler's complains.
	return *(new TValue(nullval));
}

template<typename TKey, typename TValue>
TValue& SortedMapWithLinkedList<TKey, TValue>::at(const TKey key) {
	return this->operator[](key);
}

template<typename TKey, typename TValue>
typename SortedMapWithLinkedList<TKey, TValue>::Iterator SortedMapWithLinkedList<TKey, TValue>::insert(const TKey key, const TValue value) {
	if (this->empty()) {
		elements_->append(TPair(key, value));
		return this->begin();
	}

	if (this->begin().key() > key) {
		elements_->prepend(TPair(key, value));
		return this->begin();
	}

	Iterator current;
	for (current = begin(); current.next().valid() && current.next().key() <= key; ++current)
		;

	if (current.key() == key)
		return current;

	elements_->insert(current.node_, TPair(key, value));

	return current.next();
}

template<typename TKey, typename TValue>
void SortedMapWithLinkedList<TKey, TValue>::erase(const TKey key) {
	if (!this->containsKey(key))
		return;

	for (Iterator current = begin(); current.valid() && current.key() <= key; ++current)
		if (current.key() == key) {
			elements_->remove(current.node_);
			return;
		}
}

template<typename TKey, typename TValue>
inline void SortedMapWithLinkedList<TKey, TValue>::erase(SortedMapWithLinkedList<TKey, TValue>::Iterator& it) {
	if (!it.valid())
		return;

	elements_->remove(it.node_);
}

void test_SortedMapWithLinkedList();

#endif /* SORTEDMAPWITHLINKEDLIST_H_ */
