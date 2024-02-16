NAME=libft.a

CC=cc

INCLUDE_FOLDER = ./includes

CFLAGS=-Wall -Wextra -Werror -I $(INCLUDE_FOLDER)

SRC_FOLDER = ./srcs

BUILD_DIR = ./build

SRCS = $(shell find $(SRC_FOLDER) -name '*.c')

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

# test:
# 	echo $(OBJS) > file.txt

all: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(BUILD_DIR)/%.o : $(SRCS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY:  all clean fclean re
