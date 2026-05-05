/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 01:48:58 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:46:15 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*

	DESCRIPTION
		It compares only the first (at most) n bytes of s1 and s2.
		Returns an integer indicating the result of the comparison, \
		as follows:
		- 0, if the s1 and s2 are equal;
		- a negative value ig s1 is less than s2;
		- a positive value is s1 is greather than s2.
	RETURN VALUE
		The strncmp() function return an integer less 
		than, equal  to,  or greater  than  zero if s1 (or the 
		first n bytes thereof) is found, respectively, to be less than,
		to match, or be greater than s2.


	ALTERNATIVA
		i;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i])
	{
		if (s1[i] != s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);


*/
