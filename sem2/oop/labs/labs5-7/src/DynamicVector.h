#ifndef DYNAMICVECTOR_H_
#define DYNAMICVECTOR_H_

template<typename T>
class DynamicVector {
	public:
		/* Default constructor. */
		DynamicVector();

		/* Constructor with fixed initial capacity. */
		DynamicVector(const int capacity);

		/* Copy constructor. */
		DynamicVector(const DynamicVector<T>& that);

		/* Assignment operator. */
		DynamicVector<T>& operator=(const DynamicVector<T>& that);

		/* Destructor. */
		~DynamicVector();

		/* Subscript operator to get the element from a certain position. */
		T& operator[](const int position) const;

		/* Appends an element at the end of the vector. */
		int append(const T elem);

		/* Insert an element at a certain position in the vector. */
		int insert(const int position, const T elem);

		/* Removes the element from a certain position in the vector. */
		int remove(const int position);

		/* Removes the first occurrence of an element in the vector, if it exists. */
		int erase(const T elem);

		/* Returns the number of elements of the vector. */
		int size() const;

		DynamicVector<T> operator+(const T elem);
		DynamicVector<T> operator-(const T elem);
		DynamicVector<T>& operator+=(const T elem);
		DynamicVector<T>& operator-=(const T elem);

	private:
		T* elements_;
		int capacity_;
		int size_;

		/* Expands vector's capacity. */
		int expand();
};

template<typename T>
DynamicVector<T> operator+(const DynamicVector<T>& that, const T elem);

void testDynamicVector();

#include "DynamicVector.cpp"

#endif /* DYNAMICVECTOR_H_ */
