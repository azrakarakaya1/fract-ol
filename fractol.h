/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:07:54 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/16 18:07:57 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_mms_20191025_beta/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 750
# define MAX_ITERATIONS 150
# define ESCAPE_VALUE 4.0

# define KEY_ESC 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define BLACK 0x000000

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_image
{
	void	*image_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	double	escape_value;
	int		iterations;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
}			t_fractal;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atof(char *s);
void		ft_putstr_fd(char *s, int fd);
void		handle_error(void);

#endif