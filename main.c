/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:16:15 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/16 19:16:17 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_numeric(char *s)
{
	int	i;
	int	dots;

	if (*s == '\0')
		return (0);
	i = 0;
	dots = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
			dots++;
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		if (dots > 1)
			return (0);
		i++;
	}
	return (1);
}

void	handle_error(void)
{
	ft_putstr_fd("Usage:\n", 1);
	ft_putstr_fd("\t./fractol mandelbrot\n", 1);
	ft_putstr_fd("\t./fractol julia <real> <imaginary>\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			if (!is_numeric(argv[2]) || !is_numeric(argv[3]))
				handle_error();
			fractal.julia_x = ft_atof(argv[2]);
			fractal.julia_y = ft_atof(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		handle_error();
	return (0);
}
