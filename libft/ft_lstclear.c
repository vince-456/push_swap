/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstclear.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:14:48 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:14:50 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tüm bağlı listeyi elemanlarıyla birlikte siler ve belleği temizler.
 * 
 * Bu fonksiyon, verilen bir listenin tüm düğümlerini sırayla gezer. Her düğümün 
 * içeriğini 'del' fonksiyonu yardımıyla siler ve ardından düğümlerin bellek 
 * alanlarını serbest bırakır. Son olarak listenin başlangıç adresini NULL yapar.
 * 
 * @param lst  Silinecek bağlı listenin başlangıç adresini tutan çift gösterici.
 * @param del  Düğüm içerisindeki veriyi silmek için kullanılacak fonksiyonun 
 * adresi.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}
