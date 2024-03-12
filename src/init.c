/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:31:18 by lgarfi            #+#    #+#             */
/*   Updated: 2024/01/08 17:47:09 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_img *img_ptr, int x, int y, int color)
{
	char	*dst;

	dst = img_ptr->addr + (y * img_ptr->line_length + x * (img_ptr->bpp / 8));
	*(unsigned int *)dst = color;
}

void	free_mlx(t_fractal *f)
{
	if (!f)
	{
		print_err_mess();
	}
	else if (!f->mlx_p.win)
	{
		mlx_destroy_display(f->mlx_p.mlx);
		free(f->mlx_p.mlx);
		print_err_mess();
	}
	else if (!f->img_p.img)
	{
		mlx_destroy_image(f->mlx_p.mlx, f->img_p.img);
		mlx_destroy_window(f->mlx_p.mlx, f->mlx_p.win);
		mlx_destroy_display(f->mlx_p.mlx);
		free(f->mlx_p.mlx);
		print_err_mess();
	}
}

void	init_complex_plan(t_fractal *f)
{
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->min_r = -2.0;
	f->min_i = -1.12;
	f->max_r = 0.47;
	f->max_i = (f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH);
}

void	init(t_fractal *f)
{
	f->mlx_p.mlx = mlx_init();
	if (!f->mlx_p.mlx)
		free_mlx(f);
	f->mlx_p.win = mlx_new_window(f->mlx_p.mlx, WIDTH, HEIGHT, "fract-ol");
	if (!f->mlx_p.win)
		free_mlx(f);
	f->img_p.img = mlx_new_image(f->mlx_p.mlx, WIDTH, HEIGHT);
	if (!f->img_p.img)
		free_mlx(f);
	f->img_p.addr = mlx_get_data_addr(f->img_p.img, &f->img_p.bpp,
			&f->img_p.line_length, &f->img_p.endian);
	if (!f->img_p.addr)
		free_mlx(f);
	events_init(f);
	init_complex_plan(f);
	init_color(f);
}

void	clear_init(t_fractal *f)
{
	f->set = NULL;
	f->max_iteration = 50;	
	f->ki = 0.0;
	f->kr = 0.0;
}
