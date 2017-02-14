NAME = filler
SRC = ./src/centroid.c ./src/ft_choose_direction.c ./src/ft_direction_pos.c \
./src/ft_free_tab.c ./src/ft_get_best_position.c ./src/ft_get_piece.c \
./src/ft_get_xy.c ./src/ft_gnl_tab_free.c ./src/ft_run_filler.c \
./src/ft_select_dir.c ./src/get_next_line.c ./src/main.c
OBJ = $(SRC:.c=.o)

MAKE = make

GCC = gcc
FLAGS = -Wall -Werror -Wextra

INC = ./includes
LIB = ./libft

.PHONY: clean fclean all re lib

all: lib $(NAME)

$(NAME): $(OBJ)
				@echo Compiling $(NAME)
				@$(GCC) $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L $(LIB) -lft
				@echo ======[Done]======

$(OBJ): src/%.o : src/%.c
				@echo "$(NAME) >>> Add/Update $^"
	    	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

lib:
				@$(MAKE) -C $(LIB)

clean:
				@$(MAKE) -C $(LIB) clean
				@echo Clean objects $(NAME)
				@rm -rf $(OBJ)

fclean: clean
				@$(MAKE) -C $(LIB) fclean
				@echo Clean $(NAME)
				@rm -rf $(NAME)
				@echo ======[Clean]======

re: fclean all
