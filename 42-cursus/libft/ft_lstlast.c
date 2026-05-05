/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:48:32 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:05:08 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
	DESCRIPTION
		Return the last node of the list.
	RETURN
		Last node of the list.
LESSON
1. lst->next equivalent to lst->next != NULL
lst->next is the pointer to the next node. When it is NULL it means\
that I reached the last node!
*/
