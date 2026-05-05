/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:42:33 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:07:02 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	l_lst;

	l_lst = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		l_lst++;
	}
	return (l_lst);
}
/*
int	main(void)
{
	int	l_lst;
	char	str1[] = "Hello ";
	char	str2[] = "World ";
	char	str3[] = "!";
	t_list	*new_node1;
	t_list	*new_node2;
	t_list	*new_node3;
	t_list	*head;

	new_node3 = ft_lstnew(str3);
	head = new_node3;
	new_node2 = ft_lstnew(str2);
	ft_lstadd_front(&head, new_node2);
	new_node1 = ft_lstnew(str1);
	ft_lstadd_front(&head, new_node1);
	l_lst = ft_lstsize(head);
	ft_putstr_fd("The list size is: ", 1);
	ft_putnbr_fd(l_lst, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Their content are: ", 1);
	ft_putstr_fd((char *)new_node1->content, 1);
	ft_putstr_fd(", ", 1);
	ft_putstr_fd((char *)new_node2->content, 1);
	ft_putstr_fd(", ", 1);
	ft_putstr_fd((char *)new_node3->content, 1);
	ft_putstr_fd("\n", 1);
	//NEED TO FREE THE nodes !!! <--- TO DO!
}
*/
/*
	DESCRIPTION
		Counts the number of nodes in the list.
	RETURN
		The length of the list.

PSEUDOCODE
	declaration of the counter

	loop while lst is not NULL address lst to the next list and
	count

	return the counted length
*/
