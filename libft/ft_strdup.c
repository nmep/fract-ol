/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:56:40 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/11 19:40:44 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc((sizeof(*s) * ft_strlen(s)) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = 0;
	return (str);
}
/*
#include <string.h>
int	main()
{
	int	i = 0;
	char *dst = ft_strdup((char *)"coucou");
	while (dst[i])
		write(1, &dst[i++],1);
}*/
