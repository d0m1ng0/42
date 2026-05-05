/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:33:34 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:57:15 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
/*
	RETURN
		Checks for a digit (0 through 9).\
	RETURN VALUE
		The  values  returned are nonzero if the character c falls into
		the tested class, and zero if not.
*/
