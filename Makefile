NAME = push_swap
NAMEB = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
INC = push_swap.h
RM = rm -f

LIBFTPRINTF_DIR = ./printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

SRCS =	./push_swap/push_swap.c \
		./push_swap/valid_parse.c \
		./push_swap/push_utils.c \
		./push_swap/error_handling.c \
		./push_swap/sorting.c \
		./push_swap/stack_utils.c \
		./push_swap/move_to_stack.c \
		./push_swap/abr/push_a_b.c \
		./push_swap/abr/reverse_a_b_r.c \
		./push_swap/abr/reverse_rotate_a_b_r.c \
		./push_swap/abr/swap_a_b_ss.c\
		./lib/ft_atol.c \
		./lib/utils.c \
		./lib/ft_isdigit.c \
		./lib/ft_split.c \
		./lib/ft_strjoin.c \
		./lib/ft_strlen.c \

SRCSB = ./checker/push_swap_checker.c \
		./checker/push_swap/valid_parse.c \
		./checker/push_swap/push_utils.c \
		./checker/push_swap/error_handling.c \
		./checker/push_swap/sorting.c \
		./checker/push_swap/stack_utils.c \
		./checker/push_swap/move_to_stack.c \
		./checker/push_swap/abr/push_a_b.c \
		./checker/push_swap/abr/reverse_a_b_r.c \
		./checker/push_swap/abr/reverse_rotate_a_b_r.c \
		./checker/push_swap/abr/swap_a_b_ss.c\
		./checker/lib/ft_atol.c \
		./checker/lib/utils.c \
		./checker/lib/ft_isdigit.c \
		./checker/lib/ft_strncmp.c \
		./checker/lib/ft_split.c \
		./checker/lib/ft_strjoin.c \
		./checker/lib/ft_strlen.c \
		./checker/getNextLine/get_next_line.c \
		./checker/getNextLine/get_next_line_utils.c \

OBJS = $(addprefix src/, $(SRCS:.c=.o))
OBJSB = $(addprefix src/, $(SRCSB:.c=.o))


%.o: %.c ${INC}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFTPRINTF}
	${CC} ${FLAGS} ${OBJS} -o ${NAME} ${LIBFTPRINTF}

${NAMEB}: ${OBJSB} ${LIBFTPRINTF}
	${CC} ${FLAGS} ${OBJSB} -o ${NAMEB} ${LIBFTPRINTF}

all: ${NAME}

bonus: ${NAMEB}

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) ${NAME} ${NAMEB}

re: fclean all

.PHONY: all clean fclean re