/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:11:32 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:43:43 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_mapped;
	unsigned int	l_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	l_s = ft_strlen (s);
	str_mapped = (char *)malloc(l_s + 1);
	if (!str_mapped)
		return (NULL);
	i = 0;
	while (i < l_s)
	{
		str_mapped[i] = f(i, s[i]);
		i++;
	}
	str_mapped[i] = '\0';
	return (str_mapped);
}
/*
	DECRIPTION
		Applies the function f to each character of the
		string s, passing its index as the first argument
		and the character itself as the second. A new
		string is created (using malloc(3)) to store the
		results from the successive applications of f.
	RETURN
		The string created from the successive applications
		of ’f’.
		Returns NULL if the allocation fails.

LESSON:

1. The function f receives the index (unsigned int) and the char at that index.
It will get back that char but trasformed.
	"...s..." -> f('s')
2. Pointer to function *f main idea is the  "callback": pass a function
f with a precise firm (A), which is a variable, in a function B (ft_strmapi) 
where at a certain point it (A) will be called.
3. f: variable OR pointer of function OR dynamic dispatch = CALLBACK.


PSEUDOCODE:

	declare the string mapped, a counter for length, an index

	calculate the length

	malloc the space for the string and securization

	loop to copy at the index eleent  of th string to map the correspondat 
	char of the original string at that indexat position

4. POINTER TO FUNCTION: forgetting ft_strmapi, in general to use a pointer to
function f, in the main we must declare

//declaratin of function nothing()
int	main(void)
{
	//code
	char (*f)(unsigned int, char);
	<---------------------------> this is the firm, but can be different
	//code
	f = nothing;	//now I can use f;
}

MAIN TO TEST ft_strmapi
Example: a functions which does nothing
	char	nothing(unsigned int i,	char c)
	{
		void(i);
		return (c); 
	}

	int main(void)
	{
		//code
		char	*str = "abc";
		char	*reslt;
		//code
		result = ft_strmapi(str, nothing);
		//code
	}
*/
