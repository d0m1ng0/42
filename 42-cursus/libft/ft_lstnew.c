/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:37:50 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:07:21 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	char	str[] = "You can do it!";
	t_list	*new_node;

	new_node = ft_lstnew(str);//Not need to explicit cast
	ft_putstr_fd((char *)new_node->content, 1);//Need to cast
	ft_putstr_fd("\n", 1);
	free (new_node);
	return (0);
}
*/
/*
	DESCRIPTION:
		Allocate memory using malloc and returns a new node.\
		The 'content' member variable is initialazed with the\
		given parameter 'content'.
		The variable 'next' is inizialized to NULL.
	RETURN:
		A pointer to the new node.

LESSON
- What is a struct ?
- Difference between a struct and a type
- What is a list? What is a node ?
- How it works memory allocation for a t_list ?

LESSON: Identical Names (Structure vs. Parameter)
Code: new->content = content;

Il fatto di mettere il nome "content" nel campo del parametro della funz
ft_lstnew  invece di un altro nome (esempio "val") dice gia la sua 
destinazione finale nella struttura.
- se t_list *ft_lstnew(void *val) -> Qui ti chiedi: "Dove va a finire \
argument? Nel campo content? O serve a qualcos'altro?"
- t_list *ft_lstnew(void *content) -> Qui sai immediatamente: "Ah,\
questo parametro finisce dritto nel campo content della struttura".


1. ON THE LEFT (new->content): THE FIXED FIELD
This "content" depends on the TYPE (t_list) defined in the header file (.h).
It is a "fixed" name: you cannot choose it now; it was decided when
the struct was invented. The compiler looks at the definition of t_list
and searches for a field with this name.

2. ON THE RIGHT (= content): THE LOCAL PARAMETER
This "content" is the variable entering YOUR function right now.
It is named this way because the ft_lstnew prototype mandates it.
If the prototype had said (void *foo), here we would have written = foo.

SUMMARY:
We are assigning the VALUE of the parameter (right) into the SPACE
reserved by the structure's field (left).

VISUALIZZAZIONE MEMORIA: new->content = content;
Data moves from right to left, Source -> Destination,

A DESTRA DELL'UGUALE (=)            A SINISTRA DELL'UGUALE (new->)
-----------------------------       ----------------------------------
LO STACK (Variabili Locali)           LO HEAP (Memoria Allocata)
"Quello che hai in mano ora"         "La scatola che hai appena creato"

Variabile: content                    Puntatore: new
+-----------------------------+       +-----------------------------+
|                             |       |   ETICHETTA: [content]      |
|   Indirizzo del dato        | ===>  |   (Lo spazio vuoto da       |
|   (es. 0x42...)             |       |    riempire)                |
|                             |       |                             |
+-----------------------------+       +-----------------------------+
|   ETICHETTA: [next]         |
|   (NULL)                    |
+-----------------------------+

3. In the main.
	new_node = ft_lstnew(str);//Not need to explicit cast
	ft_putstr_fd((char *)new_node->content, 1);//Need to cast
In C the pointers work with a order specificity:
from PARTICULAR to GENERAL is AUTOMATIC 
	(char *) -> (void *)
from GENERAL to PARTICULAR is MANUAL
	(void *) -> (char *)
No problem if after the action of ft_lstnew in the new_node there
is
	void	*content = "You can do it!"
here I am writing in the memory RODATA, read only data, no errors
becaus on a void * I can't write. It's ok.
More problematic is, for example,
	char	*content = "You can do it!"
because there I can decide to write, but It's not ok in RODATA,
there will be segmentation fault.
*/
