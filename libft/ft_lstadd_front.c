/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstadd_front.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:14:28 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:14:30 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bağlı listenin en başına yeni bir eleman ekler.
 * 
 * Bu fonksiyon, verilen 'new' düğümünü 'lst' ile işaret edilen listenin 
 * en önüne yerleştirir ve listenin yeni başlangıç elemanı yapar.
 * 
 * @param lst  Listenin başlangıç adresini tutan çift gösterici
 * (pointer to pointer).
 * @param new  Listenin başına eklenecek olan yeni düğüm.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
