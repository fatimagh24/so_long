NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra
MLX_PATH = ../minilibx-linux
MLX_LIB = -L $(MLX_PATH) -lmlx -lXext -lX11

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj

INCLUDES = includes

srcs = check_map_path.c\
		check_map.c\
		collecttibles.c\
		flood_fill.c\
		free_map.c\
		load_images.c\
		parsing_map.c\
		play.c\
		player_moves.c\
		helpers.c

SRC = $(addprefix $(SRC_DIR)/, $(srcs))

OBJ = $(addprefix $(OBJ_DIR)/, $(srcs:%.c=%.o))

all: $(NAME)

$(LIBFT) :
		@$(MAKE) -C $(LIBFT_DIR) all

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(FLAGS) -I $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean: 
	rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) 

re: fclean all

.PHONY: all, re, clean, fclean
