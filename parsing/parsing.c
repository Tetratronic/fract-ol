/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:37:27 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/19 18:10:33 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	my_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	valid_double(char *arg)
{
	int	i;

	while (my_isspace(*arg))
		arg++;
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg && *arg != '.')
		if (!ft_isdigit(*arg++))
			return (0);
	i = 0;
	if (!*arg || !*++arg)
		return (0);
	while (*arg)
		if (!ft_isdigit(*arg++) || i++ >= 9)
			return (0);
	return (1);
}

double	my_atod(char *str)
{
	int		n;
	int		d;
	double	r;
	int		i;
	int		neg;

	n = 0;
	d = 0;
	neg = 1;
	n = abs(ft_atoi(str));
	if (ft_strchr(str, '-'))
		neg = -1;
	while (*str && *str != '.')
		str++;
	d = abs(ft_atoi(++str));
	i = 0;
	while (*(str + i))
		i++;
	if (n < -2 || n > 2 || (n == -2 && d < 0) || (n == 2 && d > 0))
	{
		available_options();
		exit (0);
	}
	r = (double)n + (double)((double)d / pow(10, i));
	return (r * neg);
}

int	available_options(void)
{
	ft_putstr_fd("AVAILABLE OPTIONS :\n\n\tmandelbrot\n\n", 1);
	ft_putstr_fd("\tjulia <real coordinate> <imaginary coordinate>\n\n", 1);
	ft_putstr_fd("\tshuriken\n\n", 1);
	ft_putstr_fd("\tfish\n\n", 1);
	ft_putstr_fd("\tship\n", 1);
	ft_putstr_fd("\n-You must pass the numeric arguments in float format", 1);
	ft_putstr_fd(", up to nine decimal places.\n\n", 1);
	ft_putstr_fd("EXAMPLES :\n\n\t./fractol julia -.4 0.6\n", 1);
	ft_putstr_fd("\n\t./fractol julia 0.269045362 -0.004996614\n\n", 1);
	ft_putstr_fd("CONTROLS : \n\n\t-Mouse Wheel : Zoom in and out", 1);
	ft_putstr_fd("\n\t-Numbers row 1 to 5 : ", 1);
	ft_putstr_fd("Change colors\n\t-Space : Reset zoom", 1);
	ft_putstr_fd("\n\t-Arrow Keys : Move the screen\n", 1);
	return (0);
}

int	valid_args(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp("mandelbrot", argv[1], 11))
		return (1);
	if (argc == 4 && !ft_strncmp("julia", argv[1], 6))
		if (valid_double(argv[2]) && valid_double(argv[3]))
			return (2);
	if (argc == 2 && !ft_strncmp("shuriken", argv[1], 9))
		return (3);
	if (argc == 2 && !ft_strncmp("fish", argv[1], 5))
		return (4);
	if (argc == 2 && !ft_strncmp("ship", argv[1], 5))
		return (5);
	return (0);
}
