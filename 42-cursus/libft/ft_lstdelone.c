/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:37:28 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:04:25 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
	DESCRIPTION
		Takes a node as aparameter and frees its content\
		using the function 'del'. Free the node itself but \
		but do NOT free the next node.
	RETURN
		Nothing.

LESSON.
1. Delete and clean only one node of the chain.
2. 
*/
