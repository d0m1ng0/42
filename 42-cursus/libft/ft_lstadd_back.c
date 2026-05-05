/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:05:02 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:03:19 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
	DESCRIPTION
		Adds the node ’new’ at the end of the list. 
	RETURN
		Nothing.
LESSON

1. Come in ft_lst_addfront, non potendo usare la head nel main, \
usiamo il suo alias **lst.
Nei due casi possibili l'alias **lst si potra riferire sia a head \
sia all'ultimo nodo della lista dove voglio aggiungere un new.
2. Devo sempre usare ft_lstlast (o riscriverne la logica) per trovare\
la cosa. La lista non ha una memoria intrinseca di dove finisce; si \
deve istruire il programma a percorrere i ganci (next) finche non \
trova NULL.

3. nel main
	//code
	t_list	*head;

	head = NULL;
	//Or head = node; 
I am passing head to ft_lstadd_back(&head, new_node), head and
new_node are in the main.
head has an address, it lives somewhere at the addess example  0x7F..
this is the address I obtein with &head.
The value pointed by him if it is NULL this is the address it is
pointing

if the value pointed by head is NULL it meas no nodes added, the list
is empty!!41

La Regola del Doppio Puntatore
* Nel main:
* Hai la variabile puntatore head.
* Per cambiarne il valore (dove punta), scrivi:
	head = new_address
* Perché? Perché head è la variabile che contiene l'indirizzo.
* Nella Funzione (ft_lstadd_back):
* Hai il doppio puntatore lst, che è l'indirizzo della variabile head.
* Per cambiare il valore della variabile head (quella fuori dalla funzione), \
devi "aprire la scatola" lst una volta con un asterisco:
         *lst = new
* Perché? L'asterisco (*) è necessario perché stiamo modificando la variabile \
head del main attraverso il suo indirizzo (lst). Senza l'asterisco, \
modificheremmo solo la copia locale di lst, lasciando la head originale \
invariata.
Il tuo ragionamento è impeccabile. Sei pronto a passare oltre i puntatori doppi! 
Torniamo all'obiettivo di pulizia della memoria: ft_lstdelone .
Eravamo rimasti al Passaggio 1: Liberare il Contenuto.
Dobbiamo chiamare la funzione del (passata come puntatore a funzione) e \
passarle come argomento il contenuto del nodo (lst->content).
Qual è l'istruzione C più semplice per chiamare la funzione puntata da del \
(che accetta un void *) e passarle il contenuto del nodo? 


Other perspective: t_list **lst equivalent t_list *(*lst)
					   |-------|
					   pointer to | pointer
4. GUARD: quando do nel primo argomento NULL, la funzione come se 
ricevesse &lst = NULL, sto dicendo che l'indirizzo della variabile,
che auspico sia head, e NULL, ma poiche nella funzione causerebbe
sef fault sulla riga if (!*lst) sto guardando dentro ad un puntatore
nullo, allora metto clausola di guardia. l altra clausola di guardia
su new si spiega perche il rischo e di agganciare un puntatore nullo
mentre invece voglio agganciare un nodo buono, oltre ad avere
problemi se in futuro accedessi a content di un new nullo.
*/
