/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstdelone.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 14:15:13 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/13 14:15:15 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bağlı listenin tek bir elemanını bellekten siler.
 * 
 * Bu fonksiyon, kendisine parametre olarak verilen düğümün içerisindeki 
 * veriyi 'del' fonksiyonu ile serbest bırakır. Ardından düğüm yapısının 
 * (t_list) kendi kapladığı bellek alanını free() ile temizler.
 * 
 * @param lst  Silinecek olan tek düğümün adresi.
 * @param del  Düğümün 'content' (içerik) kısmını silmek için 
 * kullanılacak fonksiyonun adresi.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
