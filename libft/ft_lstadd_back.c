/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstadd_back.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:13:39 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:13:41 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bağlı listenin sonuna yeni bir eleman ekler.
 * 
 * Bu fonksiyon, verilen 'new' düğümünü 'lst' ile işaret edilen listenin 
 * en sonuna yerleştirir. Eğer liste henüz boşsa, yeni eleman listenin başı olur.
 * 
 * @param lst  Listenin başlangıç adresini tutan çift gösterici
 * (pointer to pointer).
 * @param new  Listenin sonuna eklenecek olan yeni düğüm.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
