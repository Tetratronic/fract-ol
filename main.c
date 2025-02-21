/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:38:06 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/16 22:57:20 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fract;

	fract = valid_args(argc, argv);
	if (!fract)
		return (available_options());
	if (fract == 1)
		init_fractal(mandelbrot, &vars);
	else if (fract == 2)
	{
		vars.c = my_atod(argv[2]);
		vars.ci = my_atod(argv[3]);
		init_fractal(julia, &vars);
	}
	else if (fract == 3)
		init_fractal(shuriken, &vars);
	else if (fract == 4)
		init_fractal(fish, &vars);
	else if (fract == 5)
		init_fractal(ship, &vars);
	return (0);
}
