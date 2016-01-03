#include <iostream>

namespace ChineseQuizz
{
    class Word
    {
    private:
	std::string	_english;
	std::string	_pinyins;
	std::string	_characters;

    public:
	Word();
	Word(std::string const & english,
	     std::string const & pinyins,
	     std::string const & characters);
	~Word();

	ChineseQuizz::Word & operator=(ChineseQuizz::Word & other);

	void		setEnglish(std::string const & english);
	std::string &	toEnglish();
	void		setPinyins(std::string const & pinyins);
	std::string &	toPinyins();
	void		setCharacters(std::string const & characters);
	std::string &	toCharacters();
    };
}
