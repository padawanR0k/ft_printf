CFLAGS =	-Wall -Wextra -Werror
SRCS =	\
	ft_printf.c \
	counter.c \
	process.c \
	process2.c \
	util_option.c \
	util_print.c \
	util_print_blank.c \
	util_print_zero.c \
	./util/ft_isdigit.c \
	./util/ft_strchr.c \
	./util/ft_strlen.c \

NAME =	libftprintf.a

OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

%.o :	%.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

bonus :
	make all

.PHONY:	all clean fclean re