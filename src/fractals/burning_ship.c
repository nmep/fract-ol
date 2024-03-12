/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:43:01 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/25 16:19:04 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	burning_ship(t_fractal *f, double c_re, double c_im)
{
	int		n;
	t_comp	z;

	n = -1;
	z.re = c_re;
	z.im = c_im;
	while (++n < f->max_iteration)
	{
		z.re2 = z.re * z.re;
		z.im2 = z.im * z.im;
		if (z.re2 + z.im2 > 4.0)
			break ;
		z.im = fabs(2 * z.re * z.im) + c_im;
		z.re = z.re2 - z.im2 + c_re;
	}
	return (n);
}
