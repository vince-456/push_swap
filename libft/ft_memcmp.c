/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memcmp.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 11:58:34 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/12 11:58:36 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief İki bellek bloğunu belirli bir bayt sayısına kadar karşılaştırır.
 * 
 * Bu fonksiyon, 's1' ve 's2' bellek alanlarını ilk 'n' bayt boyunca inceler.
 * Karakter tabanlı çalışan strncmp'nin aksine, bellek içinde '\0' (boş karakter)
 * görse bile durmaz, 'n' bayt tamamlanana kadar karşılaştırmaya devam eder.
 * 
 * @param s1  Karşılaştırılacak ilk bellek alanı.
 * @param s2  Karşılaştırılacak ikinci bellek alanı.
 * @param n   Karşılaştırılacak maksimum bayt (karakter) sayısı.
 * 
 * @return int İlk farklılıkta baytların arasındaki sayısal farkı döner. 
 *             Eğer tüm baytlar eşitse 0 döner.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = (const unsigned char *)s1;
	const unsigned char	*p2 = (const unsigned char *)s2;

	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
