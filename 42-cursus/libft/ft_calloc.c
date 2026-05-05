/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:53:01 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:55:01 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_alloc;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	mem_alloc = (void *)malloc(nmemb * size);
	if (mem_alloc == NULL)
		return (NULL);
	ft_bzero(mem_alloc, nmemb * size);
	return (mem_alloc);
}
/*
	DESCRIPTION
		The  calloc()  function  allocates  memory for an array of 
		nmemb elements of size bytes each and returns a pointer to 
		the allocated memory.  The memory is set to zero.  If nmemb 
		or size is 0, then calloc() returns either NULL, or a unique
		pointer value that can later be successfully passed to free().
		If the multiplication of nmemb and size would result in
		integer overflow, then calloc() returns an error. By contrast,
		an  integer over‐flow would not be detected in the following
		call to malloc(), with the result that an incorrectly sized
		block of memory would be allocated:
	           malloc(nmemb * size);
	RETURN
		calloc() functions return a pointer to the allocated memory,
		which is suitably aligned for any built-in type.  On error, 
		these functions return NULL.  NULL may also be returned by a  
		successful  call  to malloc() with a size of zero, or by a 
		successful call to calloc() with nmemb or size equal to zero.

  
LESSON
1. calloc set to zero the whole memory: zero is 0x00, 
the one interpreted '\0' with chars, NULL with pointers *p etc ...
*/
