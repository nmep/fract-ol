/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:50:55 by lgarfi            #+#    #+#             */
/*   Updated: 2024/01/04 13:54:24 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	close_handler(t_fractal *f)
{
	mlx_destroy_image(f->mlx_p.mlx, f->img_p.img);
	mlx_destroy_window(f->mlx_p.mlx, f->mlx_p.win);
	mlx_destroy_display(f->mlx_p.mlx);
	free(f->mlx_p.mlx);
	exit(1);
}

void	applyzoom(t_fractal *f, double mouse_re, double mouse_im,
	double zoom_factor)
{
	double	interpolation;

	interpolation = 1.0 / zoom_factor;
	f->min_r = interpolate(mouse_re, f->min_r, interpolation);
	f->min_i = interpolate(mouse_im, f->min_i, interpolation);
	f->max_r = interpolate(mouse_re, f->max_r, interpolation);
	f->max_i = interpolate(mouse_im, f->max_i, interpolation);
}
	
int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	double	mouse_re;
	double	mouse_im;

	mlx_mouse_get_pos(f->mlx_p.mlx, f->mlx_p.win, &x, &y);
	mouse_re = x / (WIDTH / (f->max_r - f->min_r)) + f->min_r;
	mouse_im = y / (HEIGHT / (f->max_i - f->min_i)) + f->min_i;
	if (button == 4)
		applyzoom(f, mouse_re, mouse_im, 1.2);
	else if (button == 5)
		applyzoom(f, mouse_re, mouse_im, 0.8);
	return (0);
}

int	key_handler(int keysym, t_fractal *f)
{
	if (keysym == XK_Escape)
		close_handler(f);
	if (keysym == XK_Left || keysym == XK_a)
		f->shift_x += 0.5 * (f->max_r - f->min_r);
	if (keysym == XK_Right || keysym == XK_d)
		f->shift_x -= 0.5 * (f->max_r - f->min_r);
	if (keysym == XK_Up || keysym == XK_w)
		f->shift_y += 0.5 * (f->max_i - f->min_i);
	if (keysym == XK_Down || keysym == XK_s)
		f->shift_y -= 0.5 * (f->max_i - f->min_i);
	else if (keysym == XK_equal)
		f->max_iteration += 10;
	else if (keysym == XK_minus)
		f->max_iteration -= 10;
	if (f->max_iteration < 1)
		f->max_iteration = 1;
	if (keysym == XK_space)
		space_key_colors(f);
	return (0);
}

void	events_init(t_fractal *f)
{
	mlx_hook(f->mlx_p.win, KeyPress, KeyPressMask, key_handler, f);
	mlx_hook(f->mlx_p.win, ButtonPress, ButtonPressMask, mouse_handler, f);
	mlx_hook(f->mlx_p.win, DestroyNotify, StructureNotifyMask,
		close_handler, f);
}
