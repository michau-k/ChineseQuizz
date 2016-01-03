#include "Word.hpp"

/*
 * Word class Constructor 1
 */
ChineseQuizz::Word::Word() : _english(""), _pinyins(""), _characters("")
{
}

/*
 * Word class Constructor 2
 */
ChineseQuizz::Word::Word(std::string const & english,
			 std::string const & pinyins,
			 std::string const & characters) : _english(english),
							   _pinyins(pinyins),
							   _characters(characters)
{
}

/*
 * Word class Destructor
 */
ChineseQuizz::Word::~Word()
{
}

/*
 * Word class overload operator on =
 */
ChineseQuizz::Word & ChineseQuizz::Word::operator=(ChineseQuizz::Word & other)
{
    _english = other.toEnglish();
    _pinyins = other.toPinyins();
    _characters = other.toCharacters();
}

/*
 * public : setter on english translation
 */
void ChineseQuizz::Word::setEnglish(std::string const & english)
{
    _english = english;
}

/*
 * public : get english translation
 */
std::string & ChineseQuizz::Word::toEnglish()
{
    return _english;
}

/*
 * public : setter on pinyins translation
 */
void ChineseQuizz::Word::setPinyins(std::string const & pinyins)
{
    _pinyins = pinyins;
}

/*
 * public : get pinyins translation
 */
std::string & ChineseQuizz::Word::toPinyins()
{
    return _pinyins;
}

/*
 * public : setter on characters translation
 */
void ChineseQuizz::Word::setCharacters(std::string const & characters)
{
    _characters = characters;
}

/*
 * public : get characters translation
 */
std::string & ChineseQuizz::Word::toCharacters()
{
    return _characters;
}
