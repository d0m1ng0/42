/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:30:20 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:05:39 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node_tmp;
	void	*new_content;

	new_list = NULL;
	node_tmp = NULL;
	new_content = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		node_tmp = ft_lstnew(new_content);
		if (node_tmp == NULL)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node_tmp);
		lst = lst->next;
	}
	return (new_list);
}
/*
	DESCRIPTION
		Iterates through the list ’lst’, applies the
		function ’f’ to each node’s content, and creates
		a new list resulting of the successive applications
		of the function ’f’. The ’del’ function is used to
		delete the content of a node if needed.
	RETURN
		The new list. 
		NULL if the allocation fails.
LESSON
1. Its a "mapping" function, works in parall to the original list
(lst) to built a new list (a transformed copy of the origina list).
2. 'del' function here is an emergency funtion: it prevents memory
leaks. During the process if a malloc goes wrong we can use 
ft_lstclear and pass 'del' to it, to partially destroy the list 
built until that moment.
3. STRATEGY:
-la nuova lista e indipendente alla vecchia lista ed ha la sua testa
- costruzione: scansiono la vecchia lista e uso ft_lstadd_back per
agganciare un nodo alla volta alla nuova catena
- ritorno: restituisco il puntatore alla testa della nuova lista
4. The head of the new list is here new_list;
5. void *(*f)(void *)
	-<---------->--
	pointer of a f to a pointer to void
   <----->
   void * is pointer to a void. It is a pointer to address
   but void, nothing is returned.
La domanda come posso fare
   	new_content = f(...)
se 'f' torna void ?
Occhio all'asterisco, ho void * e NON void, e questi sono due
mondi diversi!
void f(void) non fanulla -> "IL NULLA"
=>ERRORE: variabile = f(), non posso mettere il nulla 
dentro la variabile.
=> OK: la funzione restituisce un INDIRIZZO di memoria
generico.
QUINDI: new_content e dichiarato come void *, 'f' restituisce
un void *, indirizzo generico : I TIPI COMBACIANO percio
POSSO SALVARE UN INDIRIZZO DI UNA VARIABILE
	new_content = f

PSEUDOCODE
	declaration of the new head, the nodes created, the content
	transformed

	initalization. 
*/
