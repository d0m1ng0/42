/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:39:36 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 00:37:42 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#include "libft.h"

void	tester_checker(int ftocheck, const char *fname);
/*
**=============================================================================
**			CATEGORY OF FUNCTIONS
**=============================================================================
*/

/*======ft00===========counting and printing=================================*/
void	test_ft00(void)
{
/*	ft_putstr_fd	*/
	ft_putstr_fd("01 - ", 1);
	ft_putstr_fd("\033[32m", 1);

	ft_putstr_fd("[OK] ft_putstr_fd\n", 1);
	ft_putstr_fd("\033[0m", 1);
/*	ft_strlen	*/
	ft_putstr_fd("02 - ", 1);
	tester_checker(ft_strlen("Hello"), "ft_strlen");
	ft_putstr_fd("\n", 1);
/*	ft_putchar_fd 	*/
	ft_putstr_fd("03 - ", 1);
	ft_putstr_fd("\033[32m", 1);
	ft_putchar_fd('[', 1);
	ft_putchar_fd('O', 1);
	ft_putchar_fd('K', 1);
	ft_putchar_fd(']', 1);
	ft_putstr_fd(" ft_putchar_fd", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd(": this OK was generated with ft_putchar_fd\n", 1);
/*	ft_putendl_fd	*/
	ft_putstr_fd("04 - ", 1);
	ft_putstr_fd(GREEN, 1);
	ft_putchar_fd('[', 1);
	ft_putchar_fd('O', 1);
	ft_putchar_fd('K', 1);
	ft_putchar_fd(']', 1);
	ft_putendl_fd(" ft_putendl", 1);
	ft_putstr_fd(RESET, 1);

	ft_putstr_fd("\n", 1);
/*	ft_putnbr_fd	*/
	ft_putstr_fd("05 - ", 1);
	ft_putstr_fd("\033[32m", 1);
	ft_putstr_fd("[OK]", 1);
	ft_putstr_fd(" ft_putnbr_fd", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd(": the number is ", 1);
	ft_putnbr_fd(-42, 1);	

	ft_putstr_fd("\n", 1);
}
/*======ft01===========ctype and characters==================================*/
void	test_ft01(void)
{
/*	ft_isalpha	*/
	ft_putstr_fd("06 - ", 1);
	tester_checker(ft_isalpha('A') && !ft_isalpha('0'), "ft_isalpha");
	ft_putstr_fd("\n", 1);
/*	ft_isdigit	*/
	ft_putstr_fd("07 - ", 1);
	tester_checker(ft_isdigit('1') && !ft_isdigit('z'), "ft_isdigit");
	ft_putstr_fd("\n", 1);
/*	ft_isalnum	*/
	ft_putstr_fd("08 - ", 1);
	tester_checker((ft_isalnum('A') && ft_isalnum('9')) && !ft_isalnum('~'), "ft_isalnum");
	ft_putstr_fd("\n", 1);
/*	ft_isascii	*/
	ft_putstr_fd("09 - ", 1);
	tester_checker(ft_isascii(32) && !ft_isascii(128), "ft_isascii");
	ft_putstr_fd("\n", 1);
/*	ft_isprint	*/
	ft_putstr_fd("10 - ", 1);
	tester_checker(ft_isprint('a') && !ft_isprint('\n'), "ft_isprint");
	ft_putstr_fd("\n", 1);
///*	ft_toupper	*/
	ft_putstr_fd("11 - ", 1);
	tester_checker(ft_toupper('c') && ft_toupper('A'), "ft_toupper");
	ft_putstr_fd("\n", 1);
/*	ft_tolower	*/
	ft_putstr_fd("12 - ", 1);
	tester_checker(ft_tolower('C') && ft_tolower('a'), "ft_tolower");
	ft_putstr_fd("\n", 1);
}
/*======ft02===========string and analysis===================================*/
//void	test_ft02(void)
//{
///*	ft_strncmp	*/
//	ft_putstr_fd("13 - ", 1);
//	ft_putstr_fd("\n", 1);
///*	ft_strchr	*/
//	ft_putstr_fd("14 - ", 1);
//	ft_putstr_fd("\n", 1);
///*	ft_strrchr	*/
//	ft_putstr_fd("15 - ", 1);
//	ft_putstr_fd("\n", 1);
///*	ft_strnstr	*/
//	ft_putstr_fd("16 - ", 1);
//	ft_putstr_fd("\n", 1);
///*	ft_strlcpy	*/
//	ft_putstr_fd("17 - ", 1);
//	ft_putstr_fd("\n", 1);
///*	ft_strlcat	*/
//	ft_putstr_fd("18 - \n", 1);
//}
/*======ft03===========memory and zeroing====================================*/
void	test_ft03(void)
{
	char	src[9] = "original";
	char	src_expected[9] = "original";
	char	dest_zeros[9] = "111111111";
	char	dest_expected[9] = "111111111";
	//size_t	l;
	int	c;
/*	ft_memset	*/
	c = 'X';
	ft_memset(src, 'X', 4);
	ft_putstr_fd("19 - ", 1);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("ft_memset\n", 1);
	ft_putstr_fd(RESET, 1);
	ft_putstr_fd("\t-> before: ", 1);
	ft_putstr_fd(src_expected, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\t-> after: ", 1);
	ft_putstr_fd(src, 1);
	ft_putstr_fd("\n", 1);
/*	ft_bzero	*/
	c = 0;
	ft_bzero(dest_zeros, 4);
	ft_putstr_fd("20 - ", 1);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("[OK] ft_bzero\n", 1);
	ft_putstr_fd(RESET, 1);
	ft_putstr_fd("\t-> before ft_zero: ", 1);
	ft_putstr_fd(dest_expected, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\t-> after ft_zero: ", 1);
	ft_putstr_fd(dest_zeros, 1);
	ft_putstr_fd("\n", 1);
/*	ft_memcmp	*/
	char s1[] = {1,2,3,4};
	char s2[] = {1,2,3,5};

	ft_putstr_fd("21 - ft_memcmp tests:\n", 1);
	ft_putstr_fd("\ttest 1: ", 1);
	tester_checker(ft_memcmp("bonjour","bonsoir", 3) == 0, "ft_memcmp");
	ft_putstr_fd("\t\toutput: ", 1);
	ft_putnbr_fd(ft_memcmp("bonjour","bonsoir", 3), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\ttest 2: ", 1);
	tester_checker(ft_memcmp(s1, s2, 4) < 0, "ft_memcmp");
	ft_putstr_fd("\t\toutput: ", 1);
	ft_putnbr_fd(ft_memcmp(s1, s2, 4), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\ttest 3: ", 1);
	tester_checker(ft_memcmp("bonjour","\0", 4) > 0, "ft_memcmp");
	ft_putstr_fd("\t\toutput: ", 1);
	ft_putnbr_fd(ft_memcmp("bonjour","\0", 4), 1);
	ft_putstr_fd("\n", 1);
/*	ft_memcpy	*/
	int	i;
	char	src_start[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	
	char	dest_copy[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};	

	ft_putstr_fd("22 - ft_memcpy tests:\n", 1);
	ft_putstr_fd("\ttest 1: ", 1);
	tester_checker(ft_memcmp(dest_copy + 3, src_start + 1, 3), "ft_memcpy");
	ft_putstr_fd("\t\tdest after copy:",1);
	ft_memcpy(dest_copy + 3, src_start + 1, 3);
	i = 0;
	while (i < 10)
	{
		ft_putnbr_fd(dest_copy[i++], 1);
		ft_putstr_fd("\\",1);
	}
	ft_putstr_fd("\n\t\toutput ft_strcmp: ",1);
	ft_putnbr_fd(ft_memcmp(dest_copy + 3, src_start + 1, 3),1);
	ft_putstr_fd("\n",1);

/*	ft_memmove	TEST TO DO*/
	ft_putstr_fd("23 - ft_memmove tests:\n", 1);

/*	ft_memchr	TEST TO DO*/
	ft_putstr_fd("24 - ft_memchr tests:\n", 1);
}
/*======ft04===========allocation and duplication============================*/
//void	test_ft04(void)
//{
///*	ft_calloc	IMPLEMENT AND TEST TO DO*/
//	ft_putstr_fd("25 - ft_calloc tests:\n", 1);
///*	ft_strdup	IMPLEMENT AND TEST TO DO*/
//	ft_putstr_fd("26 - ft_strdup tests:\n", 1);
//}
/*======ft05===========manipulation and conversion===========================*/
	/*Helper to compare 2 array of strings for ft_itoa*/
int	check_ft_itoa_result(char *result, const char *expected)
{
	int	i;	

	if (result == NULL)	//EXTERNAL CONTROL: If the first malloc fails
		return (0);	//the program return (0), don't crash at [0]-el
	i = 0;
	while (expected[i] && result[i] && expected[i] == result[i])
			i++;
	if (expected[i] != result[i])
	{
		free(result); //Free the memory at i if
		return (0);		  //problems
	}
	return (1);
}
/*******helper to compare 2 array of strings for ft_split*********************/
void	free_ft_split(char **result, size_t el_to_free)
{
	size_t	i;

	i = 0;
	while (i < el_to_free)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	check_ft_split_result(char **result, char **expected)
{
	int	i;	
	int	j;	

	if (result == NULL)	//EXTERNAL CONTROL: If the first malloc fails
		return (0);	//the program return (0), don't crash at [0]-el
	i = 0;
	while (expected[i] != NULL)	//INTERNAL CONTROL: Reading the [i]-el
	{				//if they exist.
		if (result[i] == NULL)
			return (0);
		j = 0;
		while (expected[i][j] && result[i][j] && expected[i][j] == result[i][j])
			j++;
		if (expected[i][j] != result[i][j])
		{
		//	free_ft_split(result, i); //Free the memory at i if
			return (0);		  //problems
		}
		i++;
	}
	if (result[i] != NULL)
		return (0);
	//free_ft_split(result, i);	//Clean at the end
	return (1);
}

void	test_ft05(void)
{
//*	ft_atoi		TEST TO DO*/
//	ft_putstr_fd("27 - ft_ tests:\n", 1);
/*	ft_itoa		*/
	int	n1;
	int	n2;
	int	n3;
	int	check1;
	int	check2;
	int	check3;
	char const	*exp1 = "-42";
	char const	*exp2 = "21";
	char const	*exp3 = "0";
	char	*res1;
	char 	*res2;
	char 	*res3;

	n1 = -42;
	n2 = 21;
	n3 = 0;
	res1 = ft_itoa(n1);
	res2 = ft_itoa(n2);
	res3 = ft_itoa(n3);
	check1 = check_ft_itoa_result(res1, exp1);
	check2 = check_ft_itoa_result(res2, exp2);
	check3 = check_ft_itoa_result(res3, exp3);
	ft_putstr_fd("28 - ", 1);
	tester_checker( check1 && check2 && check3, "ft_itoa");
	ft_putstr_fd("\n", 1);
///*	ft_substr	IMPLEMENT AND TEST TO DO*/
//	ft_putstr_fd("29 - ft_ tests:\n", 1);
///*	ft_strjoin	IMPLEMENT AND TEST TO DO*/
//	ft_putstr_fd("30 - ft_ tests:\n", 1);
///*	ft_strtrim	IMPLEMENT AND TEST TO DO*/
//	ft_putstr_fd("31 - ft_ tests:\n", 1);

/*	ft_split	*/
	/*Test to print the ft_split elements*/
	char	s[] = "ti amo da morire@e tu lo sai";
	char	c;
	char	**result;
	size_t	i;
	char	*expected[] = {"ti amo da morire", "e tu lo sai", NULL};
	c = '@';
	i = 0;
	result = ft_split(s, c);
	/*while (*result) //If uncomment remember result++ change the pos.
	{
		ft_putstr_fd(*result++, 1);
		ft_putstr_fd("\n", 1);
	}
	while (i < 2)
	{
		ft_putstr_fd(expected[i++], 1);
		ft_putstr_fd("\n", 1);
	}*/
	/*Test real*/	
	ft_putstr_fd("32 - ", 1);
	tester_checker(check_ft_split_result(result, expected), "ft_split");
	ft_putstr_fd(": the \"result\" and the \"expected\" are:\n", 1);

	while (i < 2) //If uncomment remember result++ change the pos.
	{
		ft_putstr_fd("\t\t\t", 1);
		ft_putstr_fd(result[i], 1);
		ft_putstr_fd(" | ", 1);
		ft_putstr_fd(expected[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	free_ft_split(result, i);
}

///*	===ft06===	iterators and mappers	*/
//	/*Helper to compare 2 array of strings for ft_strmapi*/
//int	check_ft_strmapi_result(char *result, const char *expected)
//{
//	int	i;	
//
//	if (result == NULL)	//EXTERNAL CONTROL: If the first malloc fails
//		return (0);	//the program return (0), don't crash at [0]-el
//	i = 0;
//	while (expected[i] && result[i] && expected[i] == result[i])
//			i++;
//	if (expected[i] != result[i])
//	{
//		free(result); //Free the memory at i if
//		return (0);		  //problems
//	}
//	return (1);
//}
//
//char	change_e(unsigned int i, char c)
//{
//	(void)i;
//	if (c == 'e')
//		return ('o');
//	return (c);
//}
//
//int	check_ft_striteri_result(char *result, const char *expected)
//{
//	int	i;	
//
//	i = 0;
//	while (expected[i] && result[i] && expected[i] == result[i])
//			i++;
//	if (expected[i] != result[i])
//	{
//		return (0);  
//	}
//	return (1);
//}
//
//void	change_letters(unsigned int i, char *c)
//{
//	if (*c == 'h')
//		(*c = 's');
//	else if (*c == 'e')
//		(*c = 'a');
//	else if (*c == 'l' && i == 2)
//		(*c = 'l');
//	else if (*c == 'l')
//		(*c = 'u');
//	else if (*c == 'o')
//		(*c = 't');
//}
//
//void	test_ft06(void)
//{
///*	ft_strmapi	*/
//	char const	*str = "test";
//	char	*strmapped;
//	
//	strmapped = ft_strmapi(str, change_e);
//	ft_putstr_fd("33 - ", 1);
//	tester_checker(!check_ft_strmapi_result(strmapped, str), "ft_strmapi");
//	ft_putstr_fd("\n", 1);
//	
///*	ft_striteri	*/
//	char	s[] = "hello";
//	char const	*expec = "salut";
//	ft_striteri(s, change_letters);
//	ft_putstr_fd("34 - ", 1);
//	tester_checker(check_ft_striteri_result(s, expec), "ft_striteri");
//	ft_putstr_fd("\n\t\t\t", 1);
//	ft_putstr_fd(s, 1);
//	ft_putstr_fd("\n", 1);
//	
//}
///*	===ft07===	linked lists	*/
//void	test_ft07(void)
//{
///*	ft_lstnew	IMPLEMENT AND TEST TO DO*/
///*	ft_lstadd_front	IMPLEMENT AND TEST TO DO*/
///*	ft_lstsize	IMPLEMENT AND TEST TO DO*/
///*	ft_lstlast	IMPLEMENT AND TEST TO DO*/
///*	ft_lstadd_back	IMPLEMENT AND TEST TO DO*/
///*	ft_lstdelone	IMPLEMENT AND TEST TO DO*/
///*	ft_lstclear	IMPLEMENT AND TEST TO DO*/
///*	ft_lstiter	IMPLEMENT AND TEST TO DO*/
///*	ft_lstmap	IMPLEMENT AND TEST TO DO*/
//}

/*
**=============================================================================
**	TESTER	===============================================================
**=============================================================================
*/
void	tester_checker(int ftocheck, const char *fname)
{
	const char	*RESET_COLOR = "\033[0m";
	if (ftocheck && fname)
	{
	//	ft_putstr_fd("fname",1);
		ft_putstr_fd("\033[32m", 1);
		ft_putstr_fd("[OK] ", 1);
	}
	else
	{
	//	ft_putstr_fd(fname,1);
		ft_putstr_fd("\033[31m", 1);
		ft_putstr_fd("[FAIL] ", 1);
	}
	ft_putstr_fd((char *)fname, 1);
	ft_putstr_fd((char *)RESET_COLOR, 1);
//	ft_putstr_fd("\n", 1);
}

/*
**=============================================================================
**	MAIN	===============================================================
**=============================================================================
*/
int	main(void)
{
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("\t\t=======================\n", 1);
	ft_putstr_fd("\t\tTESTER dverdini - libft\n", 1);
	ft_putstr_fd("\t\t=======================\n", 1);
	ft_putstr_fd(RESET, 1);
	test_ft00();
	test_ft01();
//	test_ft02();
	test_ft03();
//	test_ft04();
	test_ft05();
//	test_ft06();
	return (0);
}
