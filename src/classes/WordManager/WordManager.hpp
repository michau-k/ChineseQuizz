#include <iostream>
#include <stack>
#include "Word.hpp"

namespace ChineseQuizz
{
    class WordManager
    {
    private:
	std::stack<ChineseQuizz::Word *> _words;

    public:
	WordManager();
	~WordManager();

	bool			buildListOfWords(std::string const & file);
	void			shuffleWords();
	ChineseQuizz::Word *	getNextWord();
	void			cleanup();
    };
}
