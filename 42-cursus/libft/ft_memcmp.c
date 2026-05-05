/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:25:43 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:13:10 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buff1;
	unsigned char	*buff2;

	if (n == 0)
		return (0);
	i = 0;
	buff1 = (unsigned char *)s1;
	buff2 = (unsigned char *)s2;
	while (i < n - 1 && buff1[i] == buff2[i])
		i++;
	return ((int)buff1[i] - (int)buff2[i]);
}
/*
	DESCRIPTION
		It compares the first n bytes (each interpreted as unsigned \
		char) of the memory areas s1 and s2.
	RETURN VALUE
		The memcmp() function returns an integer less than,  equal \
		to,  or greater  than  zero  if  the  first n bytes of s1 is\
		found, respec‐tively, to be less than, to match, or be greater\
		than the  first  n bytes of s2.
		
		For  a  nonzero return value, the sign is determined by the\
		sign of the difference between the first pair of bytes\
		(interpreted as  un‐signed char) that differ in s1 and s2.
		
		If n is zero, the return value is zero.

	LESSON:
	1. Similar approach ad ft_strcmp, but this time we work on raw memory \
	and we can check the buffer differences with arrays orgeneral blocks \
	of memory.

	ALTERNATIVE

	unsigned char	*buff1;
	unsigned char	*buff2;

	buff1 = (unsigned char *)s1;
	buff2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*buff1 != *buff2)
			return (*buff1 - *buff2);
		buff1++;
		buff2++;
	}
	return (0);
*/
