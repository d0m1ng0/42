/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:52:09 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:56:04 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9'));
}
/*
		DESCRIPTION
			Checks  for  an alphanumeric character; \
			it is equivalent to (isalpha(c) || isdigit(c)).
		RETURN VALUE
       		The  values  returned are nonzero if the character c falls\
		into the tested class, and zero if not.
*/
