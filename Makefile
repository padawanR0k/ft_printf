CFLAGS =	-Wall -Wextra -Werror
SRCS =	\
	ft_printf.c \
	process.c \
	process2.c \
	util_option.c \
	util_print.c \
	util_print_blank.c \
	util_print_zero.c \
	./util/ft_isdigit.c \
	./util/ft_strchr.c \
	./util/ft_strlen.c \

BONUS_SRCS =	\
	./bonus/ft_printf_bonus.c \
	./bonus/process_bonus.c \
	./bonus/process2_bonus.c \
	./bonus/util_option_bonus.c \
	./bonus/util_print_bonus.c \
	./bonus/util_print_blank_bonus.c \
	./bonus/util_print_zero_bonus.c \
	./bonus/util/ft_isdigit_bonus.c \
	./bonus/util/ft_strchr_bonus.c \
	./bonus/util/ft_strlen_bonus.c \


NAME =	libftprintf.a

OBJS =	$(SRCS:.c=.o)
BONUS_OBJS =	$(BONUS_SRCS:.c=.o)

all :	$(NAME)

%.o :	%.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean :	clean
	rm -f $(NAME)

bonus :	$(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

re :	fclean all

.PHONY:	all clean fclean re bonus