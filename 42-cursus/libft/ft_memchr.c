/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 04:53:19 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:10:08 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned const char		*buff;

	buff = (unsigned const char *)s;
	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*buff == (unsigned char)c)
			return ((void *)buff);
		buff++;
		i++;
	}
	return (NULL);
}
/*
	DESCRIPTION
		Scans the initial n bytes of the memory area pointed to by s\
		for the first intance of c. Both c and the bytes of the memory\
		area pointed to by s are interpreted as unsigned char.
	RETURN VALUE
		The  memchr()  function return a pointer to the matching byte\
		or NULL if the character does not occur in the given memory\
		area.
	LESSON
	1. Returns a pointer to the matching byte or NULL if the character\
	does occur in the given memory area.

	DOMANDA:
	unsigned char * buff;
	buff = (void *) buff;
	Il valore degli indirizzi di buff e del buff castato sono gli stessi.
	Ma cambia
	┌─────────────────────────┐
	│ INDIRIZZO (valore)      │  ← 0x1000 (sempre lo stesso)
	├─────────────────────────┤
	│ TIPO (metadato)         │  ← char* vs void* vs int* (CAMBIA)
	└─────────────────────────┘
	Perche castare a void alla fine? Per coerenza con la firma della\
	funzione
	void	*ft_memchr(const void *s, int c, size_t n)
	                  ↑
			  La funzione RITORNA void*

	 LEZIONE PER PUSH_SWAP
	 Quando crei strutture dati (liste, stack), tornerai molti puntatori.

	 Sempre fai il cast esplicito.

	 C
	 // Cattivo:
	 t_list *node = malloc(sizeof(t_list));
	 return (node);

	 // Buono:
	 t_list *node = malloc(sizeof(t_list));
	 return ((t_list *)node);  // Esplicito
*/
