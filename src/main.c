/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:32:36 by lgarfi            #+#    #+#             */
/*   Updated: 2024/01/14 15:53:53 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_get_clear_arg(t_fractal *f, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_tolower(str[i]);
	if (!ft_strncmp(str, "mandelbrot", 11))
		f->set = "mandelbrot";
	else if (!ft_strncmp(str, "julia", 5))
		f->set = "julia";
	else if (!ft_strncmp(str, "burning_ship", 12))
		f->set = "burning_ship";
	if (!f->set)
		print_err_mess();
}

void	get_julia_arg(t_fractal *f, char **av)
{
	parsing_julia(av);
	f->kr = ft_atod(av[2]);
	f->ki = ft_atod(av[3]);
}

void	handle_arg(t_fractal *f, int ac, char **av)
{
	ft_get_clear_arg(f, av[1]);
	if (ac == 4)
		get_julia_arg(f, av);
	if (ac == 3 || ac > 4)
		print_err_mess();
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac < 2)
		print_err_mess();
	clear_init(&f);
	handle_arg(&f, ac, av);
	init(&f);
	mlx_loop_hook(f.mlx_p.mlx, render, &f);
	mlx_loop(f.mlx_p.mlx);
}
