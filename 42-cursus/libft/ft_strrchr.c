/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:28:28 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:48:24 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s);
	s = s + l;
	while (l > 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		l--;
		s--;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/*
	DESCRIPTION
		Returns a pointer to the last occurence of the character c
		in the string s.
	RETURN
		Return a pointer to the matched character or NULL i the 
		character is not found.
		The terminating null byte is considered part of the string,
		so that if c is specified as '\0',
*/
