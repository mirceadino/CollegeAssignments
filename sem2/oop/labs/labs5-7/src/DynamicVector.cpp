#ifndef DYNAMICVECTOR_CPP_
#define DYNAMICVECTOR_CPP_

#include "DynamicVector.h"

template<typename T>
DynamicVector<T>::DynamicVector() :
		capacity_(1), size_(0) {
	this->elements_ = new T[this->capacity_];
}

template<typename T>
DynamicVector<T>::DynamicVector(const int capacity) :
		capacity_(capacity), size_(0) {
	this->elements_ = new T[this->capacity_];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& that) {
	this->capacity_ = int(that.capacity_);
	this->size_ = int(that.size_);
	this->elements_ = new T[this->capacity_];

	for (int i = 0; i < this->size_; i++)
		this->elements_[i] = T(that.elements_[i]);
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& that) {
	this->capacity_ = int(that.capacity_);
	this->size_ = int(that.size_);
	delete[] this->elements_;
	this->elements_ = new T[this->capacity_];

	for (int i = 0; i < this->size_; i++)
		this->elements_[i] = T(that.elements_[i]);

	return *this;
}

template<typename T>
DynamicVector<T>::~DynamicVector() {
	delete[] this->elements_;
}

template<typename T>
T& DynamicVector<T>::operator[](const int position) const {
	if (position < 0 || position >= this->size_)
		return *(new T);

	return this->elements_[position];
}

template<typename T>
int DynamicVector<T>::append(const T elem) {
	if (this->capacity_ == this->size_)
		this->expand();

	this->elements_[this->size_] = elem;
	this->size_++;

	return 1;
}

template<typename T>
inline int DynamicVector<T>::insert(const int position, const T elem) {
	if (position < 0 || position > this->size_)
		return 0;

	if (this->capacity_ == this->size_)
		this->expand();

	for (int i = this->size_; i > position; i--)
		this->elements_[i] = this->elements_[i - 1];

	this->elements_[position] = elem;
	this->size_++;

	return 1;
}

template<typename T>
int DynamicVector<T>::remove(const int position) {
	if (position < 0 || position >= this->size_)
		return 0;

	for (int i = position; i + 1 < this->size_; i++)
		this->elements_[i] = this->elements_[i + 1];

	this->size_--;
	this->elements_[this->size_] = T();

	return 1;
}

template<typename T>
int DynamicVector<T>::erase(const T elem) {
	for (int i = 0; i < this->size_; i++)
		if (this->elements_[i] == elem) {
			this->remove(i);
			return 1;
		}

	return 0;
}

template<typename T>
int DynamicVector<T>::size() const {
	return this->size_;
}

template<typename T>
DynamicVector<T> DynamicVector<T>::operator+(const T elem) {
	DynamicVector<T> copy(*this);
	copy.append(elem);
	return copy;
}

template<typename T>
DynamicVector<T> operator+(const T elem, const DynamicVector<T> that) {
	DynamicVector<T> copy(that);
	copy.insert(0, elem);
	return copy;
}

template<typename T>
DynamicVector<T> DynamicVector<T>::operator-(const T elem) {
	DynamicVector<T> copy(*this);
	copy.erase(elem);
	return copy;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator+=(const T elem) {
	this->append(elem);
	return *this;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator-=(const T elem) {
	this->erase(elem);
	return *this;
}

template<typename T>
int DynamicVector<T>::expand() {
	this->capacity_ *= 2;

	T* aux = new T[this->capacity_];

	for (int i = 0; i < this->size_; i++)
		aux[i] = this->elements_[i];

	delete[] this->elements_;
	this->elements_ = aux;

	return 1;
}

#endif
