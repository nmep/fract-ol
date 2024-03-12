/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:58:54 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/11 19:39:47 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*str;

	if ((!needle || !haystack) && (len == 0))
		return ((char *)haystack);
	str = (char *)haystack;
	n_len = ft_strlen(needle);
	i = 0;
	if (needle == haystack || n_len == 0)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] != '\0' && needle[j] != '\0' && str[i + j]
			== needle[j] && i + j < len)
			j++;
		if (j == n_len)
			return (str + i);
		i++;
	}
	return (NULL);
}
