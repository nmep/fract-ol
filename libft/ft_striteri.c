/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:19:12 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/10 18:55:43 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}
/*
void	f(unsigned int i, char *s)
{
	(void)i;
	*s -= 32;
}

int	main()
{
	char a[] = "bonjour";
	ft_striteri(a, f);
	printf("%s\n", a);
}*/
