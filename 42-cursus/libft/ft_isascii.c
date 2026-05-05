/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:17:56 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:56:57 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
/*
	DESCRIPTION
		Check wheter c is a 7-bit unsigned char value \
		that fits into the ASCII character set.
	RETURN VALUE
		The  values  returned are nonzero if the character c falls into
		the tested class, and zero if not.
*/
