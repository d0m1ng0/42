/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:52:06 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:47:33 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	size_t	j;

	len_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && (i < len))
	{
		if (i > len - len_little)
			return (NULL);
		j = 0;
		while (big[i + j] == little[j] && i + j < len && big[i + j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
	DESCRIPTION
		The strnstr() function locater the first occurrence of the \
		null-terminated string little in the string big, where not
		more than \
		len characters are searched.  Characters that appear after
		a ‘\0’ character are not searched.  Since the strnstr() 
		function is a FreeBSD specifi API, it should only be used 
		when portability is not a concern.
	RETURN
		If little is an empty string, big is returned; if little occurs \
		nowhere in big, NULL is returned; otherwhise a pointer to the first \
		character of the first occurrence of little is returned

	<-------------------------------big------------------------------ ->
	0.1.2.3.h.e.l.l.o. .w.o.r.l.d.,. .l.o.v.e. .n.o.t. .w.a.r.!.30. + 0
		4.5.6.7.8.9.10.	...	17.18.19.20.	...	
	<--little-->
	l.o.v.e. + 0	

	1. [...] no more than FIRST len characters in big are searched.	
	
	LESSON
	(char *)&big[i] equivalent to (char *)big + i;
	big is consta char * so it needs to be casted.
	But (char *)big[i] is the i-character.
*/
