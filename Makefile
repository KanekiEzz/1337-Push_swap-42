NAME = push_swap
NAMEB = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
INC = ./mandatory/includes/push_swap.h
INCB = ./bonus/includes/push_swap.h
RM = rm -f

SRCS =	./mandatory/src/push_swap.c \
		./mandatory/src/push_swap/valid_parse.c \
		./mandatory/src/push_swap/push_utils.c \
		./mandatory/src/push_swap/error_handling.c \
		./mandatory/src/push_swap/sorting.c \
		./mandatory/src/push_swap/stack_utils.c \
		./mandatory/src/push_swap/move_to_stack.c \
		./mandatory/src/push_swap/abr/push_a_b.c \
		./mandatory/src/push_swap/abr/reverse_a_b_r.c \
		./mandatory/src/push_swap/abr/reverse_rotate_a_b_r.c \
		./mandatory/src/push_swap/abr/swap_a_b_ss.c \
		./mandatory/src/lib/ft_atol.c \
		./mandatory/src/lib/utils.c \
		./mandatory/src/lib/ft_isdigit.c \
		./mandatory/src/lib/ft_split.c \
		./mandatory/src/lib/ft_strjoin.c \
		./mandatory/src/lib/ft_strlen.c \
		./mandatory/printf/ft_printf.c \
		./mandatory/printf/src/ft_putchar.c\
		./mandatory/printf/src/ft_putnbr.c\
		./mandatory/printf/src/ft_convert_base.c\
		./mandatory/printf/src/ft_putstr.c\
		./mandatory/printf/src/ft_convert_base_p.c\

SRCSB =	./bonus/src/push_swap_checker.c \
		./bonus/src/push_swap/valid_parse.c \
		./bonus/src/push_swap/push_utils.c \
		./bonus/src/push_swap/stack_utils.c \
		./bonus/src/push_swap/error_handling.c \
		./bonus/src/push_swap/abr/push_a_b.c \
		./bonus/src/push_swap/abr/reverse_a_b_r.c \
		./bonus/src/push_swap/abr/reverse_rotate_a_b_r.c \
		./bonus/src/push_swap/abr/swap_a_b_ss.c \
		./bonus/src/lib/ft_atol.c \
		./bonus/src/lib/utils.c \
		./bonus/src/lib/ft_isdigit.c \
		./bonus/src/lib/ft_split.c \
		./bonus/src/lib/ft_strjoin.c \
		./bonus/src/lib/ft_strlen.c \
		./bonus/src/lib/ft_strncmp.c \
		./bonus/printf/ft_printf.c \
		./bonus/printf/src/ft_putchar.c\
		./bonus/printf/src/ft_putnbr.c\
		./bonus/printf/src/ft_convert_base.c\
		./bonus/printf/src/ft_putstr.c\
		./bonus/printf/src/ft_convert_base_p.c\
		./bonus/line/get_next_line.c\
		./bonus/line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

mandatory/%.o: mandatory/%.c ${INC}
	${CC} ${FLAGS} -c $< -o $@

bonus/%.o: bonus/%.c ${INCB}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

${NAMEB}: ${OBJSB}
	${CC} ${FLAGS} ${OBJSB} -o ${NAMEB}

all: ${NAME}

bonus: ${NAMEB}

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) ${NAME} ${NAMEB}

re: fclean all

.PHONY: all bonus clean fclean re
