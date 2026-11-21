/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstiter.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:15:33 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:15:34 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bağlı listenin tüm elemanlarını gezer ve her birine bir 
 * fonksiyon uygular.
 * 
 * Bu fonksiyon, listenin başından başlayarak sonuna kadar her düğümün 'content' 
 * (içerik) alanını 'f' fonksiyonuna parametre olarak geçirir. Listenin yapısını,
 * düğüm sayılarını veya düğüm adreslerini değiştirmez; sadece içeriklerini işler
 * 
 * @param lst  Üzerinde gezinilecek bağlı listenin ilk elemanının adresi.
 * @param f    Her düğümün içeriğine uygulanacak olan fonksiyonun adresi.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
