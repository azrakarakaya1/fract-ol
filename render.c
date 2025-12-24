/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:15:37 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/16 19:15:39 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static int	calculate_fractal(t_complex z, t_complex c, t_fractal *fractal)
{
	int	i;
	int	color;

	i = 0;
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = (i * 3) << 16 | (i * 3) << 8 | (i * 10);
			return (color);
		}
		i++;
	}
	return (BLACK);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			color;

	z.x = (x - WIDTH / 2.0) * (4.0 / WIDTH) * fractal->zoom + fractal->shift_x;
	z.y = ((y - HEIGHT / 2.0) * (4.0 / WIDTH) * fractal->zoom
			+ fractal->shift_y) * -1.0;
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c.x = fractal->julia_x;
		c.y = fractal->julia_y;
	}
	else
	{
		c.x = z.x;
		c.y = z.y;
		z.x = 0;
		z.y = 0;
	}
	color = calculate_fractal(z, c, fractal);
	my_pixel_put(x, y, &fractal->image, color);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
