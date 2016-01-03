CC =		g++

RM =		rm -rf

NAME =		chinese-quizz

SRCS_DIR =	./src

CLASS_DIR =	$(SRCS_DIR)/classes

SRCS =		$(SRCS_DIR)/main.cpp \
		$(CLASS_DIR)/App/App.cpp

OBJS =		$(SRCS:.cpp=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
