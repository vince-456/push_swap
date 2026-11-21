/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstnew.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:16:41 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:16:45 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Yepyeni bir bağlı liste düğümü (node) oluşturur.
 * 
 * Bu fonksiyon, bellekten (heap) 't_list' yapısı boyutunda dinamik bir
 * alan ayırır.
 * Oluşturulan düğümün 'content' alanına gelen veriyi yazar ve listenin 
 * son elemanı olmaya hazır şekilde 'next' işaretçisini NULL olarak başlatır.
 * 
 * @param content Düğümün içerisine yerleştirilecek olan verinin adresi (void *).
 * 
 * @return t_list* Yeni oluşturulan düğümün bellek adresi.
 * Başarısızlıkta NULL döner.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
