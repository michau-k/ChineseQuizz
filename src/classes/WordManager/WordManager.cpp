#include "WordManager.hpp"

/*
 * WordManager class Constructor
 */
ChineseQuizz::WordManager::WordManager()
{
}

/*
 * WordManager class Destructor
 */
ChineseQuizz::WordManager::~WordManager()
{
    cleanup();
}

/*
 * public : convert the file into a list of words
 */
bool ChineseQuizz::WordManager::buildListOfWords(std::string const & file)
{
    return true;
}

/*
 * public : shuffle the list of words
 */
void ChineseQuizz::WordManager::shuffleWords()
{
}

/*
 * public : get the next word of the list
 */
ChineseQuizz::Word * ChineseQuizz::WordManager::getNextWord()
{
    return NULL;
}

/*
 * clean all the allocated memory 
 */
void ChineseQuizz::WordManager::cleanup()
{
    ChineseQuizz::Word * word = NULL;

    while (_words.size() != 0)
	{
	    word = _words.top();
	    _words.pop();
	    delete word;
	    word = NULL;
	}
}
