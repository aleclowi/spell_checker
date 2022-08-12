#ifndef _SPELLCHECK_
#define _SPELLCHECK_

#include <iostream>
#include <string.h>
#include <unordered_set>

class SpellCheck
{

public:

	/**
	Constructor: accepts the name of a file name and initializes the string variable of fileName

	@param txt file inputted by the user
	*/
	SpellCheck(const std::string& userFile);

	/**
	This function accepts the file name and reads all the words from the file into its dictionary of words.

	@param dictionary file inputted to be read into the dictionary set
	@return nothing, reads file into dictionary of words
	*/

	void read_dictionary(const std::string& dictionaryFile);

	/**
	This function reads all of the words in from the file of the given name and checks to see if the word is
	spelled correct or incorrect

	@param a word from the input file
	@return true for correct spelling, false for incorrect spelling
	*/

	bool is_valid(std::string word);

	/**
	This function checks the entire file and adds asterisks around incorrect words

	@param the name of the file inputted by the user
	@return the file with corrected words and asterisks around them
	*/

	void process_file(const std::string& userFile);

private:
	//the following variables are used in the function definitions and are only modified once
	std::string dictionaryFile;
	std::unordered_set <std::string> dictionary;
	std::string userFile;
	
};

/**
This function accepts a char and returns true if it is white space (a space,
tab, or new line) and otherwise false;

@param a possible space character
@return type bool, true for whitespace, false otherwise.
*/

bool is_white_space(char w);

/**
This function accepts a word and returns a bool as to whether the final
character is a punctuation mark

@param a possible a word from the userFile
@return type bool, true for punctuation mark, false otherwise.
*/

bool final_punctuation(std::string word);

/**
This function mutates a std::string input, making its first
character lowercase and removing its final punctuation mark if there is one.

@param a word from the userFile
@return type void
*/

std::string depunctuate(std::string word);

#endif
