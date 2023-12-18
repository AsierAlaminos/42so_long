/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:13:40 by aalamino          #+#    #+#             */
/*   Updated: 2023/05/10 18:13:42 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*lista;
	t_list	*temp_two;

	temp = lst;
	lista = NULL;
	while (temp)
	{
		temp_two = ft_lstnew(f(temp->content));
		if (temp_two == NULL)
		{
			ft_lstclear(&lista, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&lista, temp_two);
		temp = temp->next;
	}
	temp_two = NULL;
	return (lista);
}
