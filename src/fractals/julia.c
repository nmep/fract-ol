/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:51:16 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/26 18:40:02 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	julia(t_fractal *f, double c_re, double c_im)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < f->max_iteration)
	{
		if ((c_im * c_im + c_re * c_re) > 4.0)
			break ;
		tmp = 2 * c_re * c_im + f->ki;
		c_re = c_re * c_re - c_im * c_im + f->kr;
		c_im = tmp;
		n++;
	}
	return (n);
}
