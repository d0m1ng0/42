/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:29:37 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:03:46 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	char	str1[] ="First node!";
	char	str2[] ="Second node!";
	t_list	*new_node1;
	t_list	*new_node2;
	t_list	*head;

	new_node2 = ft_lstnew(str2);//Not need to explicit cast
	ft_putstr_fd((char *)new_node2->content, 1);//Need to cast
	ft_putstr_fd("\n", 1);
	head = new_node2;
	new_node1 = ft_lstnew(str1);//Not need to explicit cast
	ft_putstr_fd((char *)new_node1->content, 1);//Need to cast
	ft_putstr_fd("\n", 1);
	ft_lstadd_front(&head, new_node1);
//	free (new_node1);//DA RIVEDERE
//	free (new_node2);//DA RIVERDERE
	return (0);
}
*/
/*
	DESCRIPTION
		Adds the node ’new’ at the beginning of the list.
	RETURN
		Nothing.
PSEUDOCODE	

	(PREMESSA
	to immagine a list as a vagon in the heap:
		void	*content	is the charge
		structs s_list	*next	is the hook
	it occupy 16 bytes

	to immagine the hea, the variable in the main
		t_list	*head = NULL
	the head is just an address 8bytes (the first node address)
	it occupy 8 bytes

catena dei 3 indirizzi usando la tua precisione, che è ineccepibile:
indirizzo 1 (Locale alla funzione): È l'indirizzo della variabile di tipo \
t_list ** (che chiamiamo lst).
Dove vive: Stack della funzione.
Cosa contiene: L'indirizzo di head.
Indirizzo 2 (Nel Main): È l'indirizzo della variabile di tipo t_list * \
(che chiamiamo head).
Dove vive: Stack del Main.
Cosa contiene: L'indirizzo del nodo.
Indirizzo 3 (Nello Heap): È l'indirizzo della struttura di tipo t_list \
(il nodo vero e proprio).
Dove vive: Heap.
Cosa contiene: I dati e il next.


	head	->	nodo

	LOGIC:
	lst *lst gancio nel muro, indirizzo head
	lst *new nuovo vagone new

	se il nuovo vagone non esiste o il gancio non esiste
	allora ritorna NULL
	
	il next del nuovo vagone punta a all indirizzo di tutto il 
	vgon (NB il primo indirizzoe l indirizzo di head, qui lst)
		new -> head -> nodo

	il gancio del muro punta a l nuovo nodo new
	fine

LESSON	
1. In reality a linked list is an hybrid creature, which lives in\
two worlds: his head in the stack and the rest in the heap.
- The head list is in the STACK, in the main.
It is a pointer 8 bytes, that'all.
- The sequence, the real linked list, ins in the HEAP.
"The Gravity": if detach the head to put the new DISASTER! 

The correct way:
At the beginning
	[GANCIO (Head)]  -------->  [NODO A] -> [NODO B] -> ...
				    <------------------------->
				    		TRAIN
Then attach the train to the new vagon
			    [NODO NEW]
				|
				v
[GANCIO (Head)]  -------->  [NODO A] -> [NODO B] -> ...
			    <------------------------->
			    		TRAIN

[GANCIO (Head)]  -------->  [NODO NEW]
                          	|
				v
			    [NODO A] -> [NODO B] -> ...
		
ft_lstadd_front works between the static world of stack (main)
and the dynamic world of heap (the list)

2. neveruse
	t_list	new;
but
	t_list	*new;
	new = malloc ...;
is t_list new, to create a node on the Stack which is a use and throw memory.\
After it is used it is destroyed
t_is *new = malloc... create the node on the heap "forever"until it is free.
So t_list new it is only if I need a temprary structure use and thow to do \
something internal a functionbut then trown away.

3.
1. Il caso ft_ultimate_ft (Il valore numerico)
La Catena: È lunghissima (9 livelli), ma serve solo ad arrivare in fondo.
Il Bersaglio: Una variabile di tipo int (il numero).
L'Azione: Scrivi un numero (42) dentro quella variabile.
*********nbr = 42;
2. Il caso ft_lstadd_front (L'indirizzo)
La Catena: È corta (2 livelli: lst -> head).
Il Bersaglio: Una variabile di tipo t_list * (il gancio head).
L'Azione: Scrivi un indirizzo (l'indirizzo di new) dentro quella variabile.
*lst = new;
Hai detto bene: "copiare un indirizzo in un altro".
In C, i puntatori sono solo variabili che contengono numeri (indirizzi).
Quindi fare *lst = new è concettualmente identico a fare numero = 42. Stai \
solo aggiornando il valore contenuto nella scatola.
======================================
IMPORTANT
LESSON: THE "FT_LSTADD_FRONT" LOGIC (The Safe Handshake)

1. THE GOAL:
   Insert 'new' between the Head pointer and the Old First Node.
      Before: [Head] -> [Old Train]
      After:  [Head] -> [New] -> [Old Train]

 2. THE PLAYERS:
    *lst      : The "Hook" in the main (points to the first node).
    new       : The "New Carriage" (address of the new node).
    new->next : The "Rear Hook" of the new carriage.

  3. THE FATAL MISTAKES (What NOT to do):
		     X  *lst = new;       (Move 1st) -> You lose the Old Train\
	address forever!
		        X  *lst = new->next; (Wrong assignment) -> Head skips \
	'new' and points back to old train.

4. THE CORRECT ALGORITHM (The "Safe Handshake"):
   Step 1: SAFETY FIRST.
   Make 'new' hold the Old Train.
   Code: new->next = *lst;
  Result: [New] ---> [Old Train]

  Step 2: UPDATE THE LEADER.
  Make the Head point to 'new'.
  Code: *lst = new;
  Result: [Head] ---> [New] ---> [Old Train]

Visual Check:
  Head (Main) -> New Node (Heap) -> Old Node (Heap) -> ... -> NULL

5.evitare dangling pointer : liberare bisogna sempre seguire il ollegamento \
next secondo the reeing rule
salvre il prossimo (prendere l indirizzodel vagone successivo)
libera l attuale (distruggere il vagoneattuale)
avanzare (spostarsi all indirizzo salvato)
*/
