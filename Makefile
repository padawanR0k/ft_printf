CFLAGS =	-Wall -Wextra -Werror
SRCS =	\
	ft_printf.c \
	counter.c \
	process.c \
	util_option.c \
	util_print.c \
	util_print2.c \

LIBFT = libft
NAME =	libftprintf.a

OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

%.o :	%.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	make -C ./$(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

bonus :
	make all

.PHONY:	all clean fclean re