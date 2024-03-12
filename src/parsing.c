/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:50:41 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/25 16:40:36 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			print_err_mess();
		i++;
	}
}

void	parsing_julia(char **av)
{
	int	i;

	i = 2;
	while (av[i])
	{
		ft_str_is_alpha(av[i]);
		i++;
	}
}
