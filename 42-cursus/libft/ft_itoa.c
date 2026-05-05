/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:12:50 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:02:39 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	flags_negative_or_zero(long *n_l, size_t *len, size_t *flag)
{
	*len = 1;
	if (*n_l < 0)
	{
		*flag = 1;
		*n_l = -*n_l;
	}
}

static void	len_counting(long *n_l, size_t *len)
{
	long	n_l_backup;

	n_l_backup = *n_l;
	while (n_l_backup > 0)
	{
		n_l_backup = n_l_backup / 10;
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	char	*n_ch;
	size_t	len;
	long	n_l;
	size_t	flag;

	n_l = n;
	len = 0;
	flag = 0;
	if (n_l <= 0)
		flags_negative_or_zero(&n_l, &len, &flag);
	len_counting (&n_l, &len);
	n_ch = (char *)malloc(len + 1);
	if (!n_ch)
		return (NULL);
	n_ch[len] = '\0';
	while (len > flag)
	{
		n_ch[len - 1] = n_l % 10 + '0';
		n_l = n_l / 10;
		len--;
	}
	if (flag)
		n_ch[0] = '-';
	return (n_ch);
}
/*
	DESCRIPTION
		Allocates memory using malloc and returns a string \
		representing the integer received as an argument. \
		Negative numbers must be handled.
	RETURN
		The string representing the integer.
LESSON
1. Example for n <= 0

	int	-42 -> n_l = 42
			len = 1, for minus -	// '-'
			n_ch[3] = '\0'
			while (3>1)		
				n_l[3-1] => 42%10 => ='2'
				len = 2		// '-', '2', '\0' 
			while (2>1)		
				n_l[2-1] => '4%10' => ='4'
				len = 1		// '-', '4', '2', '\0'
	int	0  -> n_l = 0
			len = 1
			n_ch[1] = '\0'
			while (1>0)		
				n_l[2-1] => 0%10 => ='0' 
				len = 0		// '0', '\0'

1. Ho usato due funzioni ausiliarie per accorciare la funzione principale.
Ho imparao che per modificare i valori presenti nella funzione principale \
basta prendere il loro indirizzo di memoria negli argomenti di funzioni \
ausiliarie nella cui firma vanno come argomenti ai corrispondenti puntatori.
2. Uso flag_negative che diventa 1 nel caso dei numeri negativi come pavimeno \
per il while.
nel caso dei numeri negativi ho len-1 valori da stoccare quindi len-1 giri del \
while quindi len > 1 (ricordo che 1 valore e per il segno.
Mentre per i positivi ho len valori, quindi len > 0 -> uso flag_negative come \
pavimento per i due casi
	len > flag_negative
*/
/*
PSEUDO CODE
char	*atoi(int n)
{
	variables: the string, len to malloc, to stock a long, a flag for neg
	
	initialize everything but not the string to stock
	
	detect if neg do something.
	
	in that case take the long, the len, the flag, and give space in len \
	for the '-', turn on the flag, change the sign to the long

	count the len to malloc dividing a copy of long by 10 

	malloc and secure

	copy the null terminator at len-elem
	copy from the end-1 to the start all the digits using the flag for \
	negatives numbers ad (tricky) tor zero too!

	put ne sign '-'

	return the string
}
*/
