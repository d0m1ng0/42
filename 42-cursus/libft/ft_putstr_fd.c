/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:30:15 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:20:26 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	if (s)
	{
		l = ft_strlen(s);
		write(fd, s, l);
	}
}
/*
	DESCRIPTION
		Outputs the string ’s’ to the specified file
		descriptor.
	RETURN
		Nothing.
 
 LESSION
 Outputs the string 's' to the specified file descriptor
 1.write has size_t count. Why it asks a "count" ? Because it's made to \
 deplace blocks of memory of a precise dimension !
 -> I MUST CALCULATE THE DIMENSION count before call it.
 2. It's convenient call it few times possible because: user call costs. \
 Kernel achieve the task of the call costs. Less calls less costs.
 3. Nella piscine non c era bisogno di controllare che s non fosse NULL. \
 Ora si. Se s = NULL, se uso notazione i, ad esempio s[0] e un modo piu carino \
 ed equivalente di dire *(s + 0), cioe *(NULL + 0) cioe *(0x) il programma che \
 cerca di leggere la memoria all inidirzzo 0(*(Ox)) che non appartiene al \
 programma. Risulta un accesso illegale ed ho crash. Errore hardware/OS.
 dire *(s + 0), ma 

4. Since
		char const	*s = "ciao";	CORRECT if s not to modify
		char 	*s = "ciao";		DANGEROUS compiling error
		char 	s[] = "ciao";		CORRECT if s to modify.
						Alternative will be malloc!
		
		char 	s[];
		s = "ciao";	NEVER! 2 errors :
				- with s[] the stack does not know the size
				- array s[] is like a label to ATTACH \
				to attach immediately to as string. The \
				address of an array is constant, it can't be \
				used on another string.

	in the write() s is the exact address of the content of pointer s!

		| "ciao" |
		<-------->
		- "ciao" is the buffer of 5 elements: 4 + '\0'
		- char	*s; is the declaration of the pointer to s
		- s is the address of the buffer of 5 elem
		- &s is the addres s of the pointer NOT of the buffer of 5 elem
5. It is possible to put
	if (s)
	{
		//code
	}
	return;
but unuseful beacause in a void function(){} le last "}" is equivalent to\
execute a
	return;
*/
