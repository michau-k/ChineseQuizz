#include <iostream>

namespace ChineseQuizz
{
    class App
    {
    private:
	int		_error;
	std::string	_endingMessage;
	std::string	_quizzFile;

    public:
	App();
	~App();

	int		launch(int ac, char **av);

	int		getError() const;
	void		setError(int error);
	std::string &	getEndingMessage();
	void		setEndingMessage(std::string const & message);
	std::string &	getQuizzFile();
	void		setQuizzFile(std::string const & file);

    private:
	void		checkArgs(int ac, char **av);
    };
}
