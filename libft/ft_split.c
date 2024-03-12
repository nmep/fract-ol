/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:05:07 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/12 14:40:11 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_world(char const *s, char sep)
{
	int	flag;
	int	count;

	if (!s)
		return (0);
	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != sep && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (*s == sep)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*dup_word(char const *s, int start, int end)
{
	char	*str;
	int		i;

	str = malloc((end - start) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	int			start_word;
	int			j;
	size_t		i;

	tab = malloc(sizeof(char *) * (count_world(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	j = 0;
	i = 0;
	start_word = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			tab[j++] = dup_word(s, start_word, i);
			start_word = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
/*
int	main()
{
	char **tab = ft_split("  tripouille  42  ", ' ');
	int	len = ft_strlen(tab[1]) + 1;
	int	i = 0;
	while (tab[1][i])
		i++;
	printf("i = %d\nlen = %d\n", i, len);
	
	while (tab[i] != NULL)
	{
		printf("tab[%d] == %s\n", i, tab[i]);
		i++;
	}
	ft_free(tab);
	return 0;

}*/
