#include <iostream>
#include <vector>
#include "Word.hpp"

namespace ChineseQuizz
{
    class WordManager
    {
    private:
	std::vector<ChineseQuizz::Word *> _words;

    public:
	WordManager();
	~WordManager();

	bool			buildListOfWords(std::string const & path);
	void			addWord(ChineseQuizz::Word *newWord);
	void			shuffleWords();
	ChineseQuizz::Word *	getNextWord();
	void			cleanup();
	void			printWords();

    private:
	void			addWordFromLine(std::string const & line, int lineNb);
    };
}
