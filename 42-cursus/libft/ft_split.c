/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:27:07 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:21:03 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **str_spl, size_t w_to_free)
{
	size_t	i;

	i = 0;
	while (i < w_to_free)
	{
		free(str_spl[i]);
		i++;
	}
	free(str_spl);
}

static size_t	count_words(char const *s, char c)
{
	size_t	new_w;
	size_t	counter;
	size_t	i;

	new_w = 0;
	counter = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && new_w == 0)
		{
			new_w = 1;
			counter++;
		}
		else if (s[i] == c && new_w == 1)
			new_w = 0;
		i++;
	}
	return (counter);
}

static char	*get_and_stock(char const *s, char c, size_t *gps)
{
	char	*word;
	size_t	start;
	size_t	len;

	start = 0;
	len = 0;
	while (s[*gps] != '\0' && s[*gps] == c)
		(*gps)++;
	if (s[*gps] != c)
		start = *gps;
	while (s[*gps] != '\0' && s[*gps] != c)
		(*gps)++;
	len = *gps - start;
	word = ft_substr(s, (unsigned int)start, len);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**str_spl;
	size_t		w_to_alloc;
	size_t		j;
	size_t		gps;

	if (!s)
		return (NULL);
	w_to_alloc = count_words(s, c);
	str_spl = (char **)malloc((w_to_alloc + 1) * sizeof(char *));
	if (!str_spl)
		return (NULL);
	j = 0;
	gps = 0;
	while (j < w_to_alloc && s[gps] != '\0')
	{
		str_spl[j] = get_and_stock(s, c, &gps);
		if (!str_spl[j])
		{
			free_all(str_spl, j);
			return (NULL);
		}
		j++;
	}
	str_spl[j] = NULL;
	return (str_spl);
}
/*
	DESCRIPTION
		Allocates memory (using malloc) and returns an array of \
		strings obtained by splitting ’s’ using the character ’c’ as a\
		delimiter.
		The array must end with a NULL pointer.
	
	RETURN
	The array of new strings resulting from the split.
	NULL if the allocation fails.

LESSON
	
	
	1. sul count_words
			Example:
			" Hello%world%!%" | c = '%"

			new = 0
			i = 0	while (" ")
					if (TRUE && TRUE)	//done
						new = 1
					i = 1
			i = 1	while ('H')
					if (TRUE && FALSE)
						new = 1		//skipped
					else (FALSE && FALSE)	//skipped
						new = 0
					i = 2
			...
			i = 6	while ('%')
					if (TRUE && FALSE)	//skipped
					else (TRUE && TRUE)	//done
					i = 7
	2. L'Indirezione è l'idea che un dato può essere raggiunto in modo \
	indiretto, cioè attraverso uno o più indirizzi.
	Esempio: Dichiarare char *p; stabilisce un livello di indirezione \
	(un "salto"). Dichiarare char **str_spl; stabilisce due livelli di\
	indirezione (due "salti").
	
	3. Discorsi su putatori a puntatori ... e indirezione	

		type *matrix 	posso accedere anche come 	matrix[i]
		type **matrix					matrix[i][j]
		type ***matrix					matrix[i][j][k]
		type ****matrix			  	matrix[i][j][k][l]


		L indicizzazione [] si traduce in dereferenziazione * da\
		sinistra a destra (dall indice esterno al quello interno)
		matrix[i][j][k] e come dire *( *( *(matrix + i) + j) + ki)

		l ordine in cui il compilatore alloca i dati in un unico ]
		blocco di memoria e, se per es m[3][2]
		adress[0][0]-adress[0][1]-adress[1][0]-adress[1][1]-\
		adress[2][0]-adress[2][1]
		gli elementi della prima riga sono adiacenti a quelli della\
		seconda riga etc..

		come visualizzare la matrice:
		m[3][2] = 
		m00	m01
		m10	m11
		m20	m21

		Aritmetica dei Puntatori e Livelli di Indirezione
		ROW MAJOR ORDER
		l compilatore traduce matrix[i][j] in un calcolo lineare \
		(Row-Major Order) basato su una formula fissa:\
		Offset = [ (i * COLONNE) + j] * sizeof(tipo)
		
		IN DEFINITIVA :
		char **m e char m[i][j] non sono equivalenti in C benche\
		sembrino simili a prima vista.
		char **m e un puntatore a char, usato per un array di puntatori\
		dove  ogni puntatore m[i] punta un array di caratteri (es.\
		stringhe di lunghezze diverse)
		La memoria e allocata in modo NON CONTINUO, le righe possono\
		essere sparse in idirizzi diversi.
		esempio
			char **m;
			m = malloc(3 * sizeof(char*))
			
			m[0] = malloc(10 * sizeof(char))
			m[1] = malloc(20 * sizeof(char))
		d altra parte m[i][j] e un array bidimensionale con righe\
		di lnghezza fissa j.
		La memoria E CONTIGUA, tutte le celle sono allocate in un unico\
		blocco.
		esempio
			char m[3]10]

		IN ENTRAMBI I CASI USO 
			m[row][col] 
		MA IL MECCANISMO SOTTOSTANTE E DIVERSO
			per char **m
			m[row][col] = *(*(m+row)+coli	)//2 dereferenziazioni
			per char m[i][j]
			m[row][col] = *(m+(row*j)+col)	//calcolo diretto \
							dell'offset

		PASSAGGIO A FUNZIONI
		char **m passato come puntatore a puntatore, la funzione non \
		conosce la lunghezza delle righe serve parametro aggiuntivo
		char m[i][j] decade a char (*)[j] puntatore a array di j elem\
		la funzionie deve conoscere la seconda dimensione000
	4. **str_sple : sbucciare la cipolla.
	str_spl e contenitore intero.
	*str_spl accesso ad uno degli indirizzi contenuti nel contenitore.
	**str_spl segue tale indirizzo per arrivare al carattere finale,
	equivale a str_spl[j][0]
*/
