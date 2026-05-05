/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:38:08 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:16:27 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (s < d)
	{
		d = d + n;
		s = s + n;
		while (n-- > 0)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}
/*
	DESCRIPTION
		It copies n bytes from memory area src to memory area dest. \
		The memory areas may overlap: copying takes place as though\
		the bytes in src are first copied into a temporary array that\
		does not overlap src or dest, and the bytes are then copied\
		from the temporary array to dest.
	RETURN VALUE
		The memmove() function returns a pointer to dest.
*/
/*
#include <string.h>
#include <stdlib.h>
int	main(void)
{
	char dest[] = "ciao! mondo (hello)";
	char src[] = "hello";

	memmove(dest + 5,dest + 13, 15 );
	ft_putstr_fd(dest, 1);
	return (0);

}
*/
