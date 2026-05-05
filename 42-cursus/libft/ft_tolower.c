/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:57:07 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:50:47 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 'a' - 'A');
	else
		return (c);
}
/*
	DESCRIPTION
		Convert uppercase  letters to lowercase.
	RETURN
		The value returned is that of the converted letter, or c 
		if the conversion was not possible.

	LESSON
	1. It returs c if the conversion was not possible.
*/
