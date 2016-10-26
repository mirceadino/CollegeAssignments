/* PROJECT for DATA STRUCTURES AND ALGORITHMS by MIRCEA POPOVENIUC (group 911)
 *
 * Consider the next general problem:
 * Find all words in a dictionary that can be formed with the letters of a given word.
 * E.g.: orchestra / carthorse
 *       steak / skate
 *
 * 2. Find all words in a dictionary that can be formed with the letters of a given word:
 * Use the same letters, all the letters, but letters can have different frequencies. */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>

#include "SortedMapWithLinkedList.h"
#include "SortedMapWithBalancedTree.h"
#include "STLMapWrapper.h"

using namespace std;

//typedef SortedMapWithLinkedList<int, vector<string>> SortedMap;
typedef SortedMapWithBalancedTree<int, vector<string>> SortedMap;
//typedef STLMapWrapper<int, vector<string>> SortedMap;

istream& getFile(int argc, char** argv);
vector<string>& readWords(istream& in);
SortedMap& buildDictionary(vector<string>& words);
int encodeWord(string& word);
string readWord(int argc, char** argv);
void printGoodWords(SortedMap& dictionary, string& word, ostream& out);

int main(int argc, char** argv) {
	test_SortedMapWithLinkedList();
	test_SortedMapWithBalancedTree();

	istream& in = getFile(argc, argv);
	vector<string>& allWords = readWords(in);
	string word = readWord(argc, argv);

	SortedMap& dictionary = buildDictionary(allWords);
	printGoodWords(dictionary, word, cout);

	delete &in;
	delete &allWords;
	delete &dictionary;

	return 0;
}

/* Returns a stream for reading from a file received as argument in the command line (or read from standard input
 * if the command line arguments are not valid). If the filename is not valid, it reads a new one until a file can
 * be opened. First argument in the command line must be the filename.
 * GETS: int argc - number of arguments from the command line
 * 			 char** argv - arguments from the command line
 * RETURNS: reference to a stream for reading from a file (must be destroyed by user to free memory) */
istream& getFile(int argc, char** argv) {
	string filename;
	ifstream* fin = new ifstream;

	if (argc > 1) {
		filename = string(argv[1]);
	} else {
		cout << "Please read filename: ";
		cin >> filename;
	}

	fin->open(filename.c_str());

	while (!fin->is_open()) {
		cout << "Could not open file. Please read filename: ";
		cin >> filename;

		fin->open(filename.c_str());
	}

	return *fin;
}

/* Returns a list of all words read from an input stream.
 * GETS: istream& in - reference to the istream
 * RETURNS: reference to a vector of words (must be destroyed by user to free memory) */
vector<string>& readWords(istream& in) {
	vector<string>* words = new vector<string>;
	string word;

	while (in >> word)
		words->push_back(word);

	return *words;
}

/* Builds a dictionary for rapid retrieval of the words satisfying a certain criteria.
 * GETS: vector<string>& words - reference to the list of words
 * RETURNS: reference to the dictionary (must be destroyed by user to free memory) */
SortedMap& buildDictionary(vector<string>& words) {
	double start_time = clock();

	SortedMap* dictionary = new SortedMap;

	for (auto &word : words) {
		int code = encodeWord(word);
		if (!dictionary->containsKey(code))
			dictionary->insert(code, vector<string>());

		dictionary->at(encodeWord(word)).push_back(word);
	}

	double end_time = clock();
	cout << "---\n";
	cout << fixed << setprecision(6);
	cout << "Dictionary built in: " << (end_time - start_time) / CLOCKS_PER_SEC << "s\n";
	cout << "---\n";

	return *dictionary;
}

/* Encodes a word in such way that two words having the same letters (possibly with different frequencies) will have
 * the same code.
 * GETS: string& word - reference to a word
 * RETURNS: 32-bit integer representing the code of the word */
int encodeWord(string& word) {
	int code = 0;

	for (auto &c : word) {
		int i = c - 'a';
		code |= (1 << i);
	}

	return code;
}

/* Reads a word from standard input or from the command line. Second argument in the command line must be the word.
 * GETS: int argc - number of arguments from the command line
 * 			 char** argv - arguments from the command line
 * RETURNS: read word as string */
string readWord(int argc, char** argv) {
	string word;

	if (argc > 2) {
		word = string(argv[2]);

	} else {
		cout << "Read word: ";
		cin >> word;
	}

	return word;
}

/* Prints to a output stream the words satisfying a certain criteria.
 * GETS: SortedMap& dictionary - reference to the dictionary
 *       string& word - reference to the word
 *       ostream& - output stream for printing the found words
 * EFFECT: words satisfying a certain criteria with respect to the given word are printed to the output stream */
void printGoodWords(SortedMap& dictionary, string& word, ostream& out) {
	double start_time = clock();

	int code = encodeWord(word);

	if (!dictionary.containsKey(code)) {
		out << "No word was found.\n";

	} else {
		int numberOfGoodWords = dictionary[code].size();
		out << numberOfGoodWords << " words found: \n";
		for (auto &goodWord : dictionary[code])
			out << goodWord << "\n";

	}

	double end_time = clock();
	cout << "---\n";
	cout << fixed << setprecision(6);
	cout << "Good words found in: " << (end_time - start_time) / CLOCKS_PER_SEC << "s\n";
	cout << "---\n";
}
