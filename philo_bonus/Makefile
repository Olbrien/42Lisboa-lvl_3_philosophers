
NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread

MAIN = philosophers
UTILS = utils
INITIALIZE = initialize
PROCESS = process process2

SRC = $(addsuffix .c, $(addprefix , $(MAIN))) \
	  $(addsuffix .c, $(addprefix sources/utils/, $(UTILS))) \
	  $(addsuffix .c, $(addprefix sources/initialize/, $(INITIALIZE))) \
	  $(addsuffix .c, $(addprefix sources/process/, $(PROCESS)))

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling philosophers..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating philosophers objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

cclean: all clean

.PHONY: clean fclean re
