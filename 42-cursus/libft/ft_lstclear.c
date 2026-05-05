/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:35:50 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:04:06 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_backup;
	t_list	*lst_run;

	if (!lst || !del)
		return ;
	lst_run = *lst;
	while (lst_run)
	{
		lst_backup = lst_run->next;
		ft_lstdelone(lst_run, del);
		lst_run = lst_backup;
	}
	*lst = NULL;
}
/*
	DESCRIPTION
		Deletes and frees the given node and all its
		successors, using the function ’del’ and free.
		Finally, set the pointer to the list to NULL.
	RETURN
LESSON
1. Distruction of the entire listi.
2. Double pointer because I need to take the address of head and
reset to NULL the value it points to.

PSEUDOCODE
	guard clause

	copio il primo nodo su indice di copia

	loop:
		salvare l indirizzo del nodo successivo prima di
		cancellare il nodo precedente

		cancellare il nodo corrente

		vanzamento, spostare il puntatore al nodo salvato

	final reset, head must be reset

3. In the while ft_lstdelone destroys lst_run but it exist as a
vriable declared. So I can rinitialize it with the lst_backup.

*/
