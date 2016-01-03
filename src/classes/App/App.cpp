#include <boost/filesystem.hpp>
#include "App.hpp"

/*
 * App class Constructor
 */
ChineseQuizz::App::App() : _error(0), _endingMessage("Goodbye"), _quizzFile("")
{
}

/*
 * App class Destructor
 */
ChineseQuizz::App::~App()
{
}

/*
 * public : entry point for the app
 * call it to start the game
 */
int ChineseQuizz::App::launch(int ac, char **av)
{
    checkArgs(ac, av);
    if (!_error)
	{
	    if (!_wordManager.buildListOfWords(_quizzFile))
		{
		    setError(-1);
		    setEndingMessage("Error: " + getQuizzFile() + " is corupted");
		}
	    else
		{
		    _wordManager.shuffleWords();
		}
	}
    std::cout << getEndingMessage() << std::endl;
    return _error;
}

/*
 * private : check if the arguments are as expected
 * here, we want one file as parameter with .cqz extension
 */
void ChineseQuizz::App::checkArgs(int ac, char **av)
{
    boost::filesystem::path file;
    std::string binName(av[0]);

    if (ac != 2)
	{
	    setError(-1);
	    setEndingMessage("Usage: " + binName + " file.cqz");
	    return ;
	}

    file = av[1];
    if (file.extension().compare(".cqz") != 0)
	{
	    setError(-1);
	    setEndingMessage("Error: Wrong file format");
	    return ;
	}
    setQuizzFile(av[1]);
}

/*
 * public : getter on error
 */
int ChineseQuizz::App::getError() const
{
    return _error;
}

/*
 * public : setter on error
 */
void ChineseQuizz::App::setError(int error)
{
    _error = error;
}

/*
 * public : getter on ending message
 */
std::string & ChineseQuizz::App::getEndingMessage()
{
    return _endingMessage;
}

/*
 * public : setter on ending message
 */
void ChineseQuizz::App::setEndingMessage(std::string const & message)
{
    _endingMessage = message;
}

/*
 * public : getter on quizz file
 */
std::string & ChineseQuizz::App::getQuizzFile()
{
    return _quizzFile;
}

/*
 * public : setter on quizz file
 */
void ChineseQuizz::App::setQuizzFile(std::string const & file)
{
    _quizzFile = file;
}

