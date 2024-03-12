/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:58:43 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/11 09:06:23 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main()
{
	t_list *lst = NULL;


	ft_lstadd_back(&lst, ft_lstnew((void *)1));
	ft_lstlast(lst)->content == ((void *)1) ? printf("y") : printf("n");
}*/
