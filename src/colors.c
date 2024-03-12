/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:44:45 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/25 16:18:02 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	space_key_colors(t_fractal *f)
{
	f->color_a.r -= 28;
	f->color_a.g -= 21;
	f->color_a.b -= 567;
	f->color_b.r -= 59;
	f->color_b.g -= 10;
	f->color_b.b -= 110;
}

void	init_color(t_fractal *f)
{
	f->color_a.r = 0;
	f->color_a.g = 0;
	f->color_a.b = 0;
	f->color_b.r = 255;
	f->color_b.g = 255;
	f->color_b.b = 255;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_channel(int channel, int index)
{
	unsigned char	color;

	color = channel >> (index * 8) & 0xFF;
	return (color);
}

int	mix_color(int color_a, int color_b, double ratio)
{
	unsigned char	palet[3];

	palet[0] = (1.f - ratio) * (int) get_channel(color_a, 0)
		+ ratio * get_channel(color_b, 0);
	palet[1] = (1.f - ratio) * (int) get_channel(color_a, 1)
		+ ratio * get_channel(color_b, 1);
	palet[2] = (1.f - ratio) * (int) get_channel(color_a, 2)
		+ ratio * get_channel(color_b, 2);
	return (create_trgb(0, palet[0], palet[1], palet[2]));
}
