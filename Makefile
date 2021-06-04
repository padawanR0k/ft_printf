CFLAGS =	-Wall -Wextra -Werror
SRCS =	\
	ft_printf.c
LIBFT = libft
NAME =	libftprintf.a

OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

%.o :	%.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/libft.a $(NAME)
	ar -cr $@ $^

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

bonus :
	make all

.PHONY:	all clean fclean re