/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:54:44 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/11 16:11:23 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (n == 0 || (!dest && !src))
		return (dest);
	if (src <= dest)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}
