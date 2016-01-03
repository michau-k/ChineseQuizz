CXX =		g++

RM =		rm -rf

NAME =		chinese-quizz

SRCS_DIR =	./src

CLASS_DIR =	$(SRCS_DIR)/classes

INC_DIR =	$(CLASS_DIR)/App/

SRCS =		$(SRCS_DIR)/main.cpp \
		$(CLASS_DIR)/App/App.cpp

OBJS =		$(SRCS:.cpp=.o)

CXXFLAGS =	-lboost_system -lboost_filesystem -I$(INC_DIR)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
