/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:03:47 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:54:42 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
	DESCRIPTION
		Erases the data in the n bytes of the memory starting st the\
		location pointed to by s, by writing zeros (bytes containing \
		'\0') to that area.
	RETURN
		Nothing.	
LESSON:
1. t_bzero is implemented by calling ft_memset with the constant \
value '\0\' or 0 or 0x00.
*/
