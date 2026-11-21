/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstlast.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:15:53 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:15:54 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bağlı listenin en son elemanını bulur.
 * 
 * Bu fonksiyon, listenin başından başlayarak ileriye doğru gider ve 
 * kendisinden sonra başka hiçbir eleman gelmeyen (next adresi NULL olan) 
 * son düğümü tespit edip döndürür.
 * 
 * @param lst  Arama yapılacak bağlı listenin başlangıç düğümü.
 * 
 * @return t_list*  Listenin son düğümünün adresi. Liste boşsa NULL döner.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
