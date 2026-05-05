/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 23:51:48 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:25:21 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
/*
	DESCRIPTION
		It returns a pointer to the first occurrence of the
		character c in string s.
	RETURN VALUE
		The  strchr() function return a pointer to the matched 
		character or NULL if the character is not found.
		The terminating null byte is considered part of the string, 
		so that if c is specified as '\0', this function return a
		pointer to the terminator.

INTRO

1. The function returns a pointer to the matched character or NULL if\
the character is not found (BEING CAREFULL NULL is not '\0'.
2. The caracter byte '\0' is considered part of the string.

LESON - ft_strchr:

1. NULL vs '\0':
   - NULL è un puntatore nullo (indirizzo 0)
   - '\0' è il carattere null (byte 0)
   - Non sono la stessa cosa!

2. char vs unsigned char:
   - char è SIGNED (-128 a 127)
   - unsigned char è UNSIGNED (0 a 255)
   - I byte sono sempre positivi (0-255), quindi serve unsigned char

3. ASCII e Extended ASCII:
   - ASCII standard: 0-127 (caratteri base)
   - Extended ASCII: 128-255 (accenti, simboli speciali)
   - Tutti positivi, quindi unsigned char

4. Cast (unsigned char)c:
   - int c arriva come 4 byte
   - Devi estrarre il byte (0-255)
   - unsigned char garantisce confronto corretto

5. Cast (char *)s:
   - s è const char *, ma la funzione ritorna char *
   - Serve il cast per tornare char * (non const)

6. Logica della funzione:
   - Scorri s finché non trovi c o arrivi a '\0'
   - Se trovi c → ritorna puntatore
   - Se cerchi '\0' → ritorna puntatore a '\0'
   - Altrimenti → ritorna NULL

7. Perché '\0' è speciale:
   - '\0' è considerato parte della stringa
   - Se cerchi '\0', devi ritornare il puntatore a '\0'
   - Non è un errore, è corretto
*/
