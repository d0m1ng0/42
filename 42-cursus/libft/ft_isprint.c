/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:37:53 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:57:26 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}
/*
	RETURN
		Checks for any printable character including space.
	RETURN VALUE
		The  values  returned are nonzero if the character c falls into
		the tested class, and zero if not.
*/
