/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:15:54 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/16 19:15:56 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == KEY_ESC)
		close_handler(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_UP)
		fractal->zoom *= 0.95;
	else if (button == MOUSE_WHEEL_DOWN)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
