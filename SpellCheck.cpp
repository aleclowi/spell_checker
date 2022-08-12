#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
#include "SpellCheck.h"

SpellCheck::SpellCheck(const std::string& userFile) : userFile(userFile), dictionary()
{

}

void SpellCheck::read_dictionary(const std::string& dictionaryFile)
{
    //open the fileName (which is declared in the constructor) using ifstream, then initialize a string variable to be modified
    std::ifstream in;
    in.open(dictionaryFile);
    //word1 in, create the string
    std::string word;
    //create while loop for all of the words being entered into the set dictionary
    while (in >> word)
    {
        //Insert all of these words into the unordered_set dictionary . We must use insert for sets, correct syntax
        dictionary.insert(word);
    }
    //close stream
    in.close();
    return;
}

//USE THE COUNT FUNCTION FOR THIS
bool SpellCheck::is_valid(std::string word)
{
    //find words in the set
    auto result = dictionary.count(word);
    //If the result does not equal the next term, go to the next
    if (result == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//USE A NESTED WHILE LOOP FOR THE PRINTING THE WHITE SPACE, WHILE WHITESPACE ==TRUE PRINT " " if false, print word
void SpellCheck::process_file(const std::string& userFile)
{
    //open the users file entered
    std::ifstream in;
    in.open(userFile);
    //for each word in the stream
    std::string word;
    while (in >> word)
    {
        //initialize const char variables that will be added to the string word
        const char star = '*';
        //in.get() for the whitespace
        const char space = in.get();
        //if the word is correct without punctuation, then return the original word
        if (is_valid(depunctuate(word)) == true)
        {
            word = word;
        }
        //if the word is incorrect without punctuation, then return the original word with asterisks around it
        else if (is_valid(depunctuate(word)) == false)
        {
            word = star + word + star;
        }
        //pushback the space characters
        if (is_white_space(space))
        {
            word.push_back(space);
        }
        //output the words that have been modified, end the loop and close the file
        std::cout << word;
    }
    in.close();
    
}

/** ALL FUNCTIONS BELOW THIS LINE ARE NOT MEMBER FUNCTIONS OF THE CLASS*/

bool is_white_space(const char w)
{
    //for all possible space chars that the stream will read
    if (w == ' ' || w=='\n' || w == '\t')
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool final_punctuation(std::string word)
{
  //for all the possible punctuation chars that the stream may encounter on the words.
    std::set<char> punct = { '.', ',', '!', '?', ';', ':' };
    //find the punctuation mark at the end of the word
    auto find = punct.find(word[word.size() - 1]);
    //if there is one, remove it, return true, if not return false
    if (find != punct.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string depunctuate(std::string word)
{
    //Code for changing char to lower case only if upper case is detected
    if (('A' <= word[0]) && (word[0] <= 'Z')) //condition for the first char of the string A through Z
    {
        word[0] += ('a' - 'A'); //change to lower case
    }
    //if punctuation is found then delete it
    if (final_punctuation(word) == true)
    {
        word.pop_back();
    }
    return word;
}