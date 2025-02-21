NAME = fractol
SRCS = main.c parsing/parsing.c hook_funcs/animation.c hook_funcs/zoom.c fractals/julia.c fractals/init_fractal.c fractals/mandelbrot.c fractals/shuriken.c fractals/fish.c fractals/ship.c utils/get_color.c utils/put_pixel.c hook_funcs/window.c hook_funcs/color_shift.c hook_funcs/handle_keys.c
OBJS = $(SRCS:%.c=%.o)
LIBFTDIR = ./libft
MLXDIR = ./mlx_linux
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx_Linux.a
CC = cc
HEADERS = fractol.h hook_funcs/hooks_local.h
CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math -march=native

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS)  -I. -Imlx_linux -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

bonus: all

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all bonus
