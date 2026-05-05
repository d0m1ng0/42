/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:38:50 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:49:28 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		l_s;
	size_t		real_l;

	if (!s)
		return (NULL);
	l_s = ft_strlen(s);
	if (l_s <= start)
		real_l = 0;
	else if (len <= l_s - start)
		real_l = len;
	else
		real_l = l_s - start;
	substr = (char *)malloc(real_l + 1);
	if (!substr)
		return (NULL);
	s = s + start;
	if (start < l_s)
		ft_strlcpy(substr, s, real_l + 1);
	else
		substr[0] = '\0';
	return (substr);
}
/*
	DESCRIPTION
		Allocates memory (using malloc) and returns a substring from \
		the string ’s’. The substring starts at index ’start’ and has \
		a maximum length of ’len’.
	RETURN VALUE
		The substring. NULL if the allocation fails.

PSEUDO CODE

	substring, a tmp, length of the original string, beginning, lenght of
	the substring

	calculate the lenght of the string

	if the starting point is far over the string, protect

	else if the given interval less than diff available lenght fix the
	given interval

	else fix the diff

	malloc the right length and protect

	copy the address of the start of the substring

	take a temporary string to shift pointers

	loop copying in substring and null-terminate

	returnthe beginning of the substring


LESSON
Imparate molte cose che ora ho dimenticato.
1. Ternary operator
	condition ? expression_if_true : expression_if_false;
	real_l = (len <= l_s - start) ? len : l_s - start;
2. In the end the protection
	if (starl < l_s) is because is s = s + start points far in point maybe
not good I can have crash, read gargabe memory etc, so with that if I am safe.
Actually is stat is so far I have real_l is 1 then I punt a null-terminator.

OTHER VERSION

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		l_s;
	char		*start_substr;
	size_t		real_l;

	if (!s)
		return (NULL);
	l_s = ft_strlen(s);
	if (l_s <= start)
		real_l = 0;
	else if (len <= l_s - start)
		real_l = len;
	else
		real_l = l_s - start;
	substr = (char *)malloc(real_l + 1);
	if (!substr)
		return (NULL);
	start_substr = substr;
	s = s + start;
	while (real_l-- > 0)
		*substr++ = *s++;
	*substr = '\0';
	return (start_substr);
}
*/
