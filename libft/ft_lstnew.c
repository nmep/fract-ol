/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:17:32 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/10 20:13:49 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *toto)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = toto;
	list->next = NULL;
	return (list);
}
/*int		main(void)
{
	char	str[] = "lorem ipsum dolor sit";

	t_list	*elem;

	elem = ft_lstnew((void *)str);
	printf("& == %p\n", (char *)elem->next);
	printf("cont ==%s | & == %p\n", (char *)elem->content, elem->next);
}*/
