/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:23:30 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:04:48 by dverdini         ###   ########.fr       */
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
/*
	DESCRIPTION
		Iterates through the list 'list' and applies the
		function 'f' to the content of each node.
	RETURN
		Nothing.

PSEUDOCODE
	guards
	loop: apply f to the content of each list
	move the pointer to the next

LESSON
1. Its like a function "read-only" (and "apply-only").
*/
