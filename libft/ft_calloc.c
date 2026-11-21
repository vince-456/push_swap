/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_calloc.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 14:21:17 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/12 14:21:19 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bellekten yer ayırır ve ayrılan alanı sıfır (0) ile doldurur.
 * 
 * Bu fonksiyon, 'nmemb' adet eleman için 'size' boyutunda dinamik bellek alanı
 * ayırır. Standart malloc'tan farkı, ayrılan belleğin içeriğini tamamen 
 * temizlemesidir.
 * 
 * @param nmemb  Ayrılacak eleman sayısı.
 * @param size   Her bir elemanın bayt cinsinden boyutu.
 * 
 * @return void* Tahsis edilen ve sıfırlanan bellek alanının başlangıç 
 * adresi (pointer).
 *               Başarısızlık durumunda veya taşma oluştuğunda NULL döner.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
