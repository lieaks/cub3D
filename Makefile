SRCS_MAIN = main.c free.c key_hook.c move_player.c rotate_player.c item.c minimap.c
SRCS_CUB = cub.c fill_map.c fill_textures_and_colors.c map_checking.c
SRCS_RAY = draw.c raycasting.c ft_put_pixel.c dda.c render.c
SRCS = $(addprefix srcs/, $(SRCS_MAIN)) \
		$(addprefix srcs/cub/, $(SRCS_CUB)) \
		$(addprefix srcs/raycasting/, $(SRCS_RAY))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CC = /usr/bin/cc
CFLAGS = -Wall -Wextra -Werror -MMD
# CFLAGS += -g3
# CFLAGS += -fsanitize=address
INCLUDE = -Lmlx -lmlx -Lincludes -lXext -lX11 -lm

LIBFT = libft/libft.a
MLX = mlx/libmlx.a
NAME = cub3D

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) 

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

ffclean: fclean
	make -C libft fclean
	make -C mlx clean

re: fclean all

rere: ffclean all

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

bonus: all

norm:
	norminette srcs/ includes/

leak: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/little.cub

.PHONY: all clean fclean ffclean re rere bonus norm leak
