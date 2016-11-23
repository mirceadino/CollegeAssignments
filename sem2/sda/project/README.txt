PROJECT for DATA STRUCTURES AND ALGORITHMS by MIRCEA POPOVENIUC (group 911)

Consider the next general problem:
Find all words in a dictionary that can be formed with the letters of a given word.
E.g.: orchestra / carthorse
      steak/skate

2. Find all words in a dictionary that can be formed with the letters of a given word:
Use the same letters, all the letters, but letters can have different frequencies.

----------------------

To launch the program: 
	$ cd ./Debug
	$ ./SDA
	Type the name of the file with all the words.
	Words are being read from the provided file and the dictionary is built.
	Type a word from standard input.
	Required words are printed to the standard output.

Source file is ./src/main.cpp

----------------------

Solution: 
	Read all words and encode every word in the following way:
	For a certain word, use a 32-bit integer where each bit marks the presence of a certain letter in the word: the 0th bit is 1 if 'a' is present or 0 otherwise, the 1st bit is 1 if 'b' is present or 0 otherwise, ..., the 25th bit is 1 if 'z' is present or 0 otherwise.

	E.g.: word "roof": 'f' is present, corresponding to the 5th bit
					   'o' is present, corresponding to the 14th bit
					   'r' is present, corresponding to the 17th bit
		  So the corresponding code for "roof" is 2^5 + 2^14 + 2^17 = 147488
		  Note that the word "for" has the same encoding and respects the criteria that it uses the same letters and all of them (despite the different frequencies).

	The encoding is based on the fact that only lowercase letters are present in the words, so only 26 bits are required for the code.

	Use a sorted map to associate a code to a list of words.
		int -> vector<string>

	When a word is given, use the corresponding code to retrieve the list of words satisfying the required criteria and print it.
