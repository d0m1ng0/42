/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:42:15 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:18:52 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}	
/*
	DESCRIPTION
		Outputs the character 'c' to the\
		speicified file descriptor.
	RETURN
		Nothing.

LESSON:

1. write() want an address.
	&c is an address

		char	c;
		 _______
		|	|
		|  'c'	|
		|_______|
	 	&c =  address = 0x...
*/
