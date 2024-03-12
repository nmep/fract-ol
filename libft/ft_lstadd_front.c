/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:25:35 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/10 08:39:29 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main()
{
	int	first = 1;
	int second = 2;
	t_list *lst;
	t_list *new;

	new = ft_lstnew(&first);
	lst = ft_lstnew(&second);
	ft_lstadd_front(&lst, new);
	while (lst != NULL)
	{
		printf("%d\n", *((int *)lst->content));
		lst = lst->next;
	}
}*/
