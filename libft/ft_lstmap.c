/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstmap.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:16:21 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:16:24 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bir listeyi kopyalayarak her elemanına fonksiyon uygular ve yeni bir 
 * liste döndürür.
 * 
 * Bu fonksiyon, 'lst' listesindeki her düğümün içeriğini 'f' fonksiyonuna
 * gönderir. 'f' fonksiyonundan dönen yeni veriyle yeni bir düğüm oluşturur.
 * Eğer süreç esnasında herhangi bir bellek tahsis hatası yaşanırsa, o ana kadar
 * oluşturulan tüm yeni listeyi 'del' fonksiyonunu kullanarak güvenli bir şekilde
 * siler.
 * 
 * @param lst  Üzerinde işlem yapılacak orijinal bağlı listenin başlangıcı.
 * @param f    Her elemanın içeriğini dönüştürmek için kullanılacak fonksiyon.
 * @param del  Hata durumunda içerikleri bellekten temizlemek için 
 * kullanılacak fonksiyon.
 * 
 * @return t_list* Oluşturulan yepyeni bağlı listenin başlangıç adresi.
 * Hata durumunda NULL.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
