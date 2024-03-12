/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:05:18 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/10 14:40:31 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_num(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_itoa2(int count, int i, long int num, char *str)
{
	while (count-- > i)
	{
		str[count] = ((long int)num % 10) + 48;
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	int				count;
	int				i;
	long int		num;

	num = n;
	count = ft_count_num(num);
	if (num < 0 || count == 0)
		count++;
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
		i++;
	}
	ft_itoa2(count, i, num, str);
	str[count] = 0;
	return (str);
}
/*
int	main()
{
	char *a = ft_itoa(-2147483648);
	printf("%s\n", a);
}*/
