/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:31:15 by lgarfi            #+#    #+#             */
/*   Updated: 2024/01/17 17:49:05 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	mandelbrot(t_fractal *f, double c_re, double c_im)
{
	int				n;
	t_comp			z;

	z.re = c_re;
	z.im = c_im;
	n = -1;
	while (++n < f->max_iteration)
	{
		z.re2 = z.re * z.re;
		z.im2 = z.im * z.im;
		if ((z.re2 + z.im2) > 4.0)
			break ;
		z.im = 2 * z.re * z.im + c_im;
		z.re = z.re2 - z.im2 + c_re;
	}
	return (n);
}
