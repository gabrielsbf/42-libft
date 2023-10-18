NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
