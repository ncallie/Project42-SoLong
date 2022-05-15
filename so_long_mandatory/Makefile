GCC = gcc -Wall -Wextra -Werror
FLAGC_MLX = -lmlx -framework OpenGL -framework Appkit
NAME = so_long
DIR_PRINTF = ./printf
PRINT = ./printf/libftprintf.a
DIR_MLX = ./minilibx
MLX = ./minilibx/libmlx.a

SRCS = create_map.c \
		exit.c \
		init.c \
		key_control.c \
		map_check_param.c \
		map_info.c \
		render.c \
		so_long.c \

OBJECTS = $(SRCS:%.c=%.o)

all: $(NAME) 

$(NAME): $(OBJECTS)
	$(MAKE) -C $(DIR_PRINTF) all
	$(MAKE) -C $(DIR_MLX) all
	$(GCC) $(FLAGC_MLX) $(PRINT) $(MLX) -o $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C $(DIR_PRINTF) clean
	$(MAKE) -C $(DIR_MLX) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(DIR_PRINTF) fclean