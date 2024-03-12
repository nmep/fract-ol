/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:50:20 by lgarfi            #+#    #+#             */
/*   Updated: 2024/01/18 00:54:10 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	calculate_fractale(t_fractal *f, double c_re, double c_im)
{
	int	iter;

	iter = 0;
	if (!ft_strncmp(f->set, "mandelbrot", 10))
		iter = mandelbrot(f, c_re, c_im);
	else if (!ft_strncmp(f->set, "julia", 5))
		iter = julia(f, c_re, c_im);
	else if (!ft_strncmp(f->set, "burning_ship", 12))
		iter = burning_ship(f, c_re, c_im);
	return (iter);
}

int	render(t_fractal *f)
{
	t_comp	c;
	int		x;
	int		y;
	int		nb_iter;

	y = -1;
	f->im_factor = (f->max_i - f->min_i) / (HEIGHT - 1);
	f->re_factor = (f->max_r - f->min_r) / (WIDTH - 1);
	while (++y < HEIGHT)
	{
		x = -1;
		c.im = (((((f->min_i) + y * f->im_factor) * f->zoom)) - f->shift_y);
		while (++x < WIDTH)
		{
			c.re = ((((f->min_r + x * f->re_factor) * f->zoom)) + f->shift_x);
			nb_iter = calculate_fractale(f, c.re, c.im);
			f->ratio = 1.f - (double)nb_iter / f->max_iteration;
			my_mlx_pixel_put(&f->img_p, x, y, mix_color((create_trgb(0,
							f->color_b.r, f->color_b.g, f->color_b.b)),
					(create_trgb(0, f->color_a.r, f->color_a.g,
							f->color_a.b)), f->ratio));
		}
	}
	mlx_put_image_to_window(f->mlx_p.mlx, f->mlx_p.win, f->img_p.img, 0, 0);
	return (0);
}
