/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:58:21 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/11 14:40:22 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlen(const char *str)
{
	char	*p;

	p = (char *)str;
	while (*str)
		str++;
	return (str - p);
}