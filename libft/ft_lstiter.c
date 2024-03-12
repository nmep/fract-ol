/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:12:11 by lgarfi            #+#    #+#             */
/*   Updated: 2023/11/10 20:15:59 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*void	f(void *s)
{
	printf("%s\n", (char *)s);
}

int	main()
{
	t_list *list = ft_lstnew("a");
	t_list *n1 = ft_lstnew("b");
	t_list *n2 = ft_lstnew("c");

	ft_lstadd_back(&list, n1);
	ft_lstadd_back(&list, n2);

	ft_lstiter(list, f);

	return (0);
}*/
