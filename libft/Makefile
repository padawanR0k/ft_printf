CFLAGS =	-Wall -Wextra -Werror
SRCS =	\
	ft_strlen.c \
	ft_strchr.c \
	ft_isdigit.c \

NAME =	libft.a

OBJS =	$(SRCS:.c=.o)

OBJECTS = $(OBJS)

all :	$(NAME)

%.o :	%.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJECTS)
	ar -cr $@ $^

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY:	all clean fclean re