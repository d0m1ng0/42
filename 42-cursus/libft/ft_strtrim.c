/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:00:07 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:49:03 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*strtrimmed;

	if (!s1 && !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	strtrimmed = (char *)malloc(end - start + 1);
	if (!strtrimmed)
		return (NULL);
	ft_memcpy(strtrimmed, s1 + start, end - start);
	strtrimmed[end - start] = '\0';
	return (strtrimmed);
}
/*
	DESCRIPTION
		Allocates memory (using malloc) and returns a copy of ’s1’ 
		with characters from ’set’ removed from the beginning
		and the end.

	RETURN
		The trimmed string.
		NULL if the allocation fails.

	LESSON:
	1.If I pass a char ocnst *s1 to ft_memcpy (which as the second argument\
	const void* src) no problem at all: in such cases the complir makes an\
	implicit cast.
	2. How to fix my second strtrimmed return
		<-----------------------------------> = 16 the lenght
		0.1.2.3.4.5.h.e.l.l.o.11.12.13.14.15. + '\0';
	following the processus while (s1[start_index]), while (end_index...) \
	start_index is on 'h'
	end_index is on s1[11] before 'o'.
	so end_index - start_index = 11 - 6 = 5 this is the length of bytes to \
	of the substring to write! unless + 1 nul terminator char.
*/
