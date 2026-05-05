/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:01:03 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:43:22 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (*str)
	{
		str++;
	}
	return (str - start);
}
/*
	DESCRIPTION
		Calculates the length of the string pointed \
	RETURN VALUE
		The strlen() function returns the number of bytes in the
		string pointed to by s.

LESSON:
0. GOAL: The ft_strlen() function calculates the length of the string pointed \
to by s, excluding the terminating null byte ('\0') 
1. 'size_t' : it is the correct type for dimentions. It is unsigned and strong.
2. 'const char *s': it is the correct type for "only reading" datas.:
3. OLD VERSION
	int	l;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
===============================================================================
	The ft_strlen() function calculates the length of the string pointed \
	to by s, excluding the terminating null byte ('\0').
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*start;

	if (!str)
		return (0);
	start = str;
	while (*str)
		str++;
	return (str - start);
}

LESSON:

1. 'size_t': it is the correct type for dimensions. It is unsigned and strong.

2. 'const char *s': it is the correct type for "only reading" data.

3. NULL vs '\0' - FUNDAMENTAL DISTINCTION:
    -----------------------------------------------------------------
   | NULL (pointer)          vs         '\0' (terminator)            |
   |-----------------------------------------------------------------
   | 0x00 (address)          vs         0 (byte value)               |
   | "No address"            vs         "End of string"              |
   | str == NULL             vs         *str == '\0'                 |
   | Pointer doesn't exist   vs         Character exists (is zero)   |
    ------------------------------------------------------------------

4. NULL vs Empty String:
   
   NULL pointer:
   char *str = NULL;
   |- str = 0x00 (doesn't point anywhere)
   |- NO memory allocated
   |- strlen(NULL) = UNDEFINED BEHAVIOR (crash)
   |- You CANNOT say "dimension is 0" because there's NOTHING to measure
   
   Empty string:
   char str[] = "";
   |- str = 0x1000 (valid address)
   |- Memory: ['\0']
   |- strlen("") = 0
   |-Has dimension 0 (string exists but is empty)

5. Why check if (!str)?
   |- The man doesn't specify behavior for NULL (undefined)
   |- Passing NULL is programmer error
   |- BUT in libft we choose to be SAFE:
   |  |-- Return 0 instead of crashing
   |- Consistency with other libft functions (ft_putstr_fd checks NULL)
   |- Better safe than undefined behavior

6. OLD VERSION (without NULL protection):
   int	l;
   
   l = 0;
   while (str[l] != '\0')
   {
       l++;
       }
   return (l);
7. ALTERNATIVE NOT SAME AS THE ORIGINAL strlen
	size_t	ft_strlen(const char *str)
	{
		const char	*start;
	
		start = str;
		if (str)
		{
			while (*str)
			{
				str++;
			}
		}
		return (str - start);
	}
Does not goes seg-fault. But the original DOES!
*/
