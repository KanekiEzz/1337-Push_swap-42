NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rc
RM = rm -f

SRCS = ft_printf.c \
		src/ft_putchar.c\
		src/ft_putnbr.c\
		src/ft_convert_base.c\
		src/ft_putstr.c\
		src/ft_convert_base_p.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c 	ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re : fclean all

.PHONY: clean 
