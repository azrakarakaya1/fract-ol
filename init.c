/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:15:13 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/16 19:15:20 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("malloc error");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = ESCAPE_VALUE;
	fractal->iterations = MAX_ITERATIONS;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 1L << 0, key_handler, fractal);
	mlx_hook(fractal->mlx_window, 4, 1L << 2, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, 1L << 17, close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (NULL == fractal->mlx_window)
		malloc_error();
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractal->image.image_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		malloc_error();
	}
	fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bpp, &fractal->image.line_len,
			&fractal->image.endian);
	events_init(fractal);
	data_init(fractal);
}
