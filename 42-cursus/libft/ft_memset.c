/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:18:14 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:18:24 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_joker;

	ptr_joker = (unsigned char *)s;
	while (n-- > 0)
	{
		*ptr_joker++ = (unsigned char)c;
	}
	return (s);
}
/*
	DESCRIPTION
		Fills the first n bytes of the memory area pointed to by s \
		with the constant byte c.
	RETURN VALUE
		The memset() function returns a pointer to the memory area s.

	LESSON:
	1. I am working with "bit raw" (which normaly has a range 0-255)\
	2. access to the memory byte per byte
		unsigned char *ptr_joker = (unsigned char*)s
	Why this ? If void *s it is not possible to do *s = c. So it is\
	I must find a type to reppresent 1 byte. So I have:
		char, unsigned char, signed char.
	why unsigned? To avoid problems when c has value > 127
		|-128	-0-	127|
			|0		255|
	if I use unsigned char
		inc = 200;
		chr ch = c;		can be out the range, if the compiler\
					is set on  signed char. If so then\
					c becomes 200-256 = -56, no more 200.
		unsigned char uch = c	is for sure 200.
	What I learnt: THE BEST TYPE TO REPPRESENT 1 BYTE IS UNSIGNED CHAR. \
	NOT CHAR, NOT UNSIGNED CHAR TOO SMALL, NOT INT TOO BIG NO MORE 1 BYTE.
	3. how to covert int c in 1 byte
		unsigned char byte_value = (unsigned char)c
	4. who to write n bytes ? with the while
*/
