#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sstream>
#include "WordManager.hpp"

/*
 * WordManager class Constructor
 */
ChineseQuizz::WordManager::WordManager()
{
    srand(time(NULL));
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
bool ChineseQuizz::WordManager::buildListOfWords(std::string const & path)
{
    std::ifstream file(path.c_str());
    std::string line;
    int i = 0;

    if (!file.good())
	{
	    file.close();
	    return false;
	}
    while (std::getline(file, line))
	addWordFromLine(line, i++);

    return true;
}

/*
 * public : add a new Word to the list
 */
void ChineseQuizz::WordManager::addWord(ChineseQuizz::Word *newWord)
{
    if (newWord)
	_words.insert(_words.begin(), newWord);
    else
	std::cerr << "Warning: trying to add a NULL word to the list" << std::endl;
}

/*
 * public : shuffle the list of words
 */
void ChineseQuizz::WordManager::shuffleWords()
{
    std::random_shuffle (_words.begin(), _words.end());
}

/*
 * public : get the next word of the list
 */
ChineseQuizz::Word * ChineseQuizz::WordManager::getNextWord()
{
    ChineseQuizz::Word * nextWord = _words.back();
    _words.pop_back();
    return nextWord;
}

/*
 * public : clean all the allocated memory 
 */
void ChineseQuizz::WordManager::cleanup()
{
    ChineseQuizz::Word * word = NULL;

    while (_words.size() != 0)
	{
	    word = _words.back();
	    _words.pop_back();
	    delete word;
	    word = NULL;
	}
}

/*
 * public : print the current list of words
 */
void ChineseQuizz::WordManager::printWords()
{
    std::cout << "### Current list of words ###" << std::endl;
    for (std::vector<ChineseQuizz::Word *>::const_iterator i = _words.begin();
	 i != _words.end(); ++i)
	{
	    std::cout << (*i)->toEnglish() << " -- ";
	    std::cout << (*i)->toPinyins() << " -- ";
	    std::cout << (*i)->toCharacters() << std::endl;
	}
    std::cout << "###    End of the list    ###" << std::endl;
}

/*
 * private : add a word to the stack
 */
void ChineseQuizz::WordManager::addWordFromLine(std::string const & line, int lineNb)
{
    std::vector<std::string> trads;

    boost::split(trads, line, boost::is_any_of(";"));
    if (trads.size() != 3)
	{
	    std::cerr << "Warning: Line " << lineNb;
	    std::cerr << " \"" << line << "\"" << " was not added" << std::endl;
	}
    else
	addWord(new ChineseQuizz::Word(trads[0], trads[1], trads[2]));
}
