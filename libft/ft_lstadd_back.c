/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:31:16 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/11 09:36:48 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
/*
int	main()
{
//	valeurs des noeuds.
	char *a = "bonjour";
	char *b = "Lorem ficia deserunt mollit anim id est laborum.";
	char *c = "hello";
	char *d = "bloup";
	char *e = "si il est a la fin alors, das ist gut !";

//	noeuds.
	t_list *n1 = ft_lstnew(b);
	t_list *n2 = ft_lstnew(c);
	t_list *n3 = ft_lstnew(d);
	t_list *lst = ft_lstnew(a);
	t_list *end = ft_lstnew(e);


// ajoute des noeuds dans la liste "lst";
	ft_lstadd_front(&lst, n3);
	ft_lstadd_front(&lst, n2);
	ft_lstadd_front(&lst, n1);
	ft_lstadd_back(&lst, end);
// ajoute a la fin

	t_list *tmp;
	tmp = lst;

	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	
}*/
