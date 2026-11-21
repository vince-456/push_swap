/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstsize.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:17:05 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:17:07 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bağlı listenin toplam eleman (düğüm) sayısını hesaplar.
 * 
 * Bu fonksiyon, listenin başlangıcından itibaren sonuna kadar tüm elemanları tek
 * tek gezerek sayar. Orijinal listenin yapısını veya elemanlarını değiştirmez.
 * 
 * @param lst  Uzunluğu ölçülecek olan bağlı listenin ilk elemanının adresi.
 * 
 * @return unsigned int Listede bulunan toplam düğüm sayısı. Liste boşsa 0 döner.
 */
unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
