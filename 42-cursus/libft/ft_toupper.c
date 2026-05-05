/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:52:39 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:51:54 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	else
		return (c);
}
/*
	DESCRIPTION
		Convert lowercase letters to uppercase.
	RETURN
       		The value returned is that of the converted letter, or c 
		if the conversion was not possible.
		
	
	LESSON
	1. It returs c if the conversion was not possible.
*/
