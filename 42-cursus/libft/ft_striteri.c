/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:43:47 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:27:36 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	l;

	if (!s || !f)
		return ;
	i = 0;
	l = ft_strlen(s);
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
	DESCRIPTION
		Applies the function 'f' to each
		character of the string passed as
		argument, passing its index as the
		first argument. Each character is
		passed by address to ’f’ so it can
		be modified if necessary.
	RETURN
		Nothing.
LESSON:

1. Don't need to do
	s[i] = f(i, &s[i])
but yes
	f(i, &s[i])
because f does not return anything. The address of \
the char s[i] is already passed inside and f will\
modify that char directly in the original memory.

PSEUDO CODE:

	declaration of index and length

	calculation of the length

	loop where each element of s are assigned to f passinx its index and \
	the address of that element of s

"string" -> 's' = f(&'s'), 't' =  f(&'t'),  ...
k 
		     0      	    1		     i
*/
