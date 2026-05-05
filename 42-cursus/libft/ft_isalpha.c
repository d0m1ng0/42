/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:16:54 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:56:32 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z'));
}
/*
	DESCRIPTION
		Check for an alphabetic character.\
	RETURN VALUE
	       The  values  returned are nonzero if the character c falls into
	       the tested class, and zero if not.
*/
