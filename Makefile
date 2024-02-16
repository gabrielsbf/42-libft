NAME=libft.a

LIBRARY_DIR = ./libraries

LIBFT_A = $(LIBRARY_DIR)/$(NAME)
CC=cc

INCLUDE_FOLDER = ./includes

CFLAGS=-Wall -Wextra -Werror -I $(INCLUDE_FOLDER)

SRC_FOLDER = ./srcs

BUILD_DIR = ./build

SRCS = $(shell find $(SRC_FOLDER) -name '*.c')

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

# test:
# 	echo $(OBJS) > file.txt

all: $(LIBFT_A)

$(LIBFT_A): $(OBJS)
	ar rc $(LIBFT_A) $(OBJS)

$(BUILD_DIR)/%.o : $(SRCS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT_A)

re : fclean $(LIBFT_A)

.PHONY:  all clean fclean re
