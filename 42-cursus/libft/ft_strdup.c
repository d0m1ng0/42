/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:54:51 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:27:15 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h> 

char	*ft_strdup(const char *s)
{
	int		l_s;
	char	*s_copy;
	char	*start;

	l_s = ft_strlen(s);
	s_copy = (char *)malloc(l_s + 1);
	if (s_copy == NULL)
		return (NULL);
	start = s_copy;
	while (*s)
	{
		*s_copy++ = *s++;
	}
	*s_copy = '\0';
	return (start);
}
/*
	DESCRIPTION
		Returns a pointer to a new string which is a duplicate of the
		string s. Memory for the new string is obtained with malloc,
		and can be freed with free.
	RETURN VALUE
		On success, the strdup() function returns a pointer to the 
		duplicated string.  It returns NULL if insufficient memory 
		was available, with errno set to indicate the cause of the
		error.
 */
