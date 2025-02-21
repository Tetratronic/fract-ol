/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:49:24 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/19 21:18:05 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# define MAX_ITER 160

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_zoom {
	double	target_zoom;
	double	current_zoom;
	double	zoom_speed;
	double	target_x;
	double	target_y;
	double	current_x;
	double	current_y;
}	t_zoom;

typedef struct s_view {
	double	center_x;
	double	center_y;
	double	zoom;
}	t_view;

typedef struct s_vars	t_vars;

typedef struct s_vars {
	int		color_scheme[10];
	void	*mlx;
	void	*win;
	t_data	img;
	t_view	view;
	t_zoom	zoom;
	int		(*set)(int, int, t_view *, t_vars *);
	double	c;
	double	ci;
}	t_vars;

typedef struct s_rgb {
	int		r;
	int		g;
	int		b;
}	t_rgb;

int		valid_args(int argc, char **argv);
int		available_options(void);
void	init_fractal(int (*set)(int, int, t_view *, t_vars *), t_vars *vars);
int		mandelbrot(int px, int py, t_view *view, t_vars *vars);
int		julia(int px, int py, t_view *view, t_vars *vars);
void	render_frame(t_vars *vars, int (*set)(int, int, t_view *, t_vars *));
int		animation_loop(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		get_color(double iteration, t_vars *vars);
void	p_put(t_data *data, int x, int y, int color);
int		handle_keys(int keycode, t_vars *vars);
int		close_win(t_vars *vars);
int		clean_on_error(t_vars *vars);
double	my_atod(char *str);
int		fish(int px, int py, t_view *view, t_vars *vars);
int		shuriken(int px, int py, t_view *view, t_vars *vars);
int		ship(int px, int py, t_view *view, t_vars *vars);

#endif
