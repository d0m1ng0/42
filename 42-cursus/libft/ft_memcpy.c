/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:08:32 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:14:42 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_tmp;
	unsigned const char	*src_tmp;

	if (dest == src)
		return (dest);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned const char *)src;
	while (n-- > 0)
	{
		*dest_tmp++ = *src_tmp++;
	}
	return (dest);
}
/*
	DESCRIPTION
		It copies n bytes from memory area src to memory area dest.
		The memory areas must not ovelap.
		Use ft_memmove if the memory areas do overlap.
	RETURN VALUE
		The memcpy() function returns a pointer to dest.

	LESSON:
	1. Overlapping is when the memory areas of src and dest share at least \
	1 byte.
		Example 1: OVERLAPPING.
		Copying 10 bytes from a position and the dest starts\
		5 bytes later. The byte 6, 7, 8, 9, 10 of the src will be\
		overwritten by the bytes 1, 2, 3, 4, 5 of dest before being \
		read.
		
		Exemple 2: NO OVERLAPPING.
		Copying 4 bytes from src (^ position) to dest\
		(*position)
			src		|1 |2 |3^|4^|5^|6^|7 |8 |9 |10 |
			\--->	dest	|1 |2 |3 |4 |5*|6 |7 |8 |9 |10 |
				result	|1 |2 |3 |4 |3^|5^|6^|7^|9 |10 |
	Since now we are dealing with raw bytes, we can have src points on a\
	memory block (const void *src). Then dest can point to a portion of\
	the same memory block. For a certain value of n bytes to copy we can\
 	have olverlapping: while dest is being copied at the same time the src\
	is is being modified and the copy is corrupted on the dest.
	In other words the ft_memcpy "contract" is that src and dest are \
	separated. If not, if they superpose, the behaviour is not guaranteed:\
	it can be datacurruption.
	2. Pointer aliasing.
*/
