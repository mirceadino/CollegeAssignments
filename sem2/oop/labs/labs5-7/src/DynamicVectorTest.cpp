#include <cassert>
#include "DynamicVector.h"

void testDynamicVector() {
	DynamicVector<int> A;

	// append, size, operator[]
	A.append(0);
	A.append(1);
	A.append(2);
	A.append(3);
	assert(A.size() == 4);
	assert(A[0] == 0);
	assert(A[1] == 1);
	assert(A[2] == 2);
	assert(A[3] == 3);

	// insert
	A.insert(1, 4);
	A.insert(2, 5);
	assert(A.size() == 6);
	assert(A[0] == 0);
	assert(A[1] == 4);
	assert(A[2] == 5);
	assert(A[3] == 1);
	assert(A[4] == 2);
	assert(A[5] == 3);

	// remove
	A.remove(1);
	A.remove(2);
	assert(A.size() == 4);
	assert(A[0] == 0);
	assert(A[1] == 5);
	assert(A[2] == 2);
	assert(A[3] == 3);

	// erase
	A.erase(2);
	A.erase(0);
	assert(A.size() == 2);
	assert(A[0] == 5);
	assert(A[1] == 3);

	// +, -, +=, -=
	DynamicVector<int> B;
	B += 0;
	B += 1;
	B = B + 2;
	B += 3;
	B = 4 + B;
	assert(B.size() == 5);
	assert(B[0] == 4);
	assert(B[1] == 0);
	assert(B[2] == 1);
	assert(B[3] == 2);
	assert(B[4] == 3);

	B = B - 2;
	B -= 0;
	assert(B.size() == 3);
	assert(B[0] == 4);
	assert(B[1] == 1);
	assert(B[2] == 3);
}
