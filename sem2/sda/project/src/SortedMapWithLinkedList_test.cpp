#include <cassert>

#include <iostream>
#include <cstdio>
#include <string>

#include "SortedMapWithLinkedList.h"

using namespace std;

void test_SortedMapWithLinkedList() {
	SortedMapWithLinkedList<int, string> M;

	// check if sorted map is empty
	assert(M.empty());

	// initial insert to sorted map
	SortedMapWithLinkedList<int, string>::Iterator it1 = M.insert(1, "tree");
	assert(it1.valid());
	assert(!it1.next().valid());
	assert(it1.key() == 1);
	assert(it1.value() == "tree");
	assert(!M.empty());
	assert(M.size() == 1);
	assert(M.containsKey(1));
	assert(!M.containsKey(0));
	assert(!M.containsKey(-1));
	assert(!M.containsKey(2));

	// insert elements with the same keys, but accept only the first one
	auto it2 = M.insert(2, "list");
	auto it2bis = M.insert(2, "linked list");
	assert(M.size() == 2);
	assert(it2.valid());
	assert(it2 == it2bis);
	assert(it2.key() == 2);
	assert(it2.value() == "list");
	assert(M.containsKey(1));
	assert(M.containsKey(2));

	// insert elements in different order, but keep them sorted by key
	auto it4 = M.insert(4, "dictionary");
	auto it3 = M.insert(3, "heap");
	assert(M.size() == 4);
	assert(it3.valid());
	assert(it4.valid());
	assert(it3.key() == 3);
	assert(it3.value() == "heap");
	assert(M.containsKey(3));
	assert(it4.key() == 4);
	assert(it4.value() == "dictionary");
	assert(it3.next().getElement() == it4.getElement());
	assert(M.containsKey(4));

	// simple iteration through the sorted map
	M.insert(7, "treap");
	M.insert(5, "search tree");
	M.insert(6, "balanced search tree");
	assert(M.containsKey(5));
	assert(M.containsKey(6));
	assert(M.containsKey(7));
	assert(M.size() == 7);

	SortedMapWithLinkedList<int, string>::Iterator it;
	int key;
	for (it = M.begin(), key = 1; it.valid(); it = it.next(), key++)
		assert(it.key() == key);

	// removals
	M.erase(3);
	assert(M.size() == 6);
	assert(M.containsKey(1));
	assert(M.containsKey(2));
	assert(!M.containsKey(3));
	assert(M.containsKey(4));
	assert(M.containsKey(5));
	assert(M.containsKey(6));
	assert(M.containsKey(7));

	for (it = M.begin(), key = 1; it.valid(); it = it.next(), key++) {
		key == 3 && key++;
		assert(it.key() == key);
	}

	M.erase(it1);
	M.erase(5);
	M.erase(7);
	assert(M.size() == 3);
	assert(!M.containsKey(1));
	assert(M.containsKey(2));
	assert(!M.containsKey(3));
	assert(M.containsKey(4));
	assert(!M.containsKey(5));
	assert(M.containsKey(6));
	assert(!M.containsKey(7));

	for (it = M.begin(), key = 2; it.valid(); it = it.next(), key += 2)
		assert(it.key() == key);

	// set new values
	M.insert(1, "treeeeeeee");
	M.insert(3, "heafefep");
	M.insert(7, "treap");
	M.insert(5, "search tree");
	assert(M.size() == 7);
	assert(M.containsKey(1));
	assert(M.containsKey(2));
	assert(M.containsKey(3));
	assert(M.containsKey(4));
	assert(M.containsKey(5));
	assert(M.containsKey(6));
	assert(M.containsKey(7));
	it1 = M.setValue(1, "tree");
	assert(it1.value() == "tree");
	it3 = M.setValue(3, "heap");
	assert(it3.value() == "heap");

	// operator []
	M[1] = "treeee";
	M[3] = "heeeap";
	M[10] = "segment tree";
	assert(it1.value() == "treeee");
	assert(it3.value() == "heeeap");
	assert(M[10] == "segment tree");
	assert(M.size() == 8);
}
