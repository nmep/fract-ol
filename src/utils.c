/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:05:00 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/27 00:55:11 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	is_double(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
	{
		if (((str[i] < '0' || str[i] > '9') && (str[i] != ','
					&& str[i] != '.')))
			return (0);
	}
	return (1);
}

double	ft_atod(char *str)
{
	double	res;
	int		s;
	int		flag;
	int		mult;

	s = 1;
	res = 0;
	flag = 0;
	mult = 1;
	if (str[0] == '-' && str++)
		s *= -1;
	while (*str)
	{
		if (*str == '.' || *str == ',')
			flag = 1;
		if (*str >= '0' && *str <= '9')
		{
			res = res * 10 + (*str - 48);
			if (flag == 1)
				mult *= 10;
		}
		str++;
	}
	return (s * (res / mult));
}

void	print_err_mess(void)
{
	perror(MSG_ERR_1);
	perror(MSG_ERR_2);
	perror(MSG_ERR_3);
	exit(2);
}
