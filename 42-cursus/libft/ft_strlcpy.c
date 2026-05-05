/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 02:31:42 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:38:53 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		l_src;

	l_src = ft_strlen(src);
	if (size == 0)
		return (l_src);
	i = 0;
	while (i < size - 1 && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (l_src);
}
/*
	RETURN
		Copy a string. Copy src to string dst of "size" size. \
		At most size-1 characters will be copied. \
		Always NULL terminates (unless size == 0).
	RETURN VALUE
		The strlcpy() function returns strlen(src). If retval >= size,\
		truncation occurrer

LESSON:

1. Why save l_src?
   |- Symmetry with ft_strlcat (uses l_dst and l_src)
   |- If using pointer increment (*src++), src moves!
      After loop: src points to '\0', ft_strlen(src) = 0	(X)
      Solution: Save length BEFORE loop 			(V)

2. Return value:
   Returns length of src (what it TRIED to copy), not what was copied.
   Example: ft_strlcpy(dst, "hello", 3) → dst="he\0", returns 5 (not 2)
   Useful to detect truncation: if (ret >= size) → truncated

3. Edge case size == 0:
   Return l_src without copying (avoid buffer overflow)
*/
