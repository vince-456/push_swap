/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memchr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 11:58:34 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/12 11:58:36 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Bir bellek bloğu içinde belirli bir baytı arar.
 * 
 * Bu fonksiyon, 's' ile işaret edilen bellek alanının ilk 'n' baytını inceler
 * ve 'c' karakterinin (unsigned char olarak yorumlanan) ilk 
 * eşleştiği adresi bulur.
 * 
 * @param s    Arama yapılacak bellek bloğunun başlangıç adresi.
 * @param c    Aranacak bayt değeri (int olarak alınır,
 * unsigned char'a dönüştürülür).
 * @param n    İncelenecek maksimum bayt sayısı.
 * 
 * @return void* Eşleşen baytın bulunduğu yerin bellek adresi.
 * Bulunamazsa NULL döner.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;
	unsigned char		uc;

	uc = (unsigned char)c;
	while (n--)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
