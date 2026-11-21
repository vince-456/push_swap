/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strncmp.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 11:58:34 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/12 11:58:36 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief İki metni belirli bir karakter sayısına kadar karşılaştırır.
 * 
 * Bu fonksiyon, 's1' ve 's2' metinlerini ilk 'n' karakter boyunca inceler. 
 * Karakterler aynı olduğu sürece devam eder, ilk farklılıkta veya metinlerden 
 * biri bittiğinde durur.
 * 
 * @param s1  Karşılaştırılacak ilk metin.
 * @param s2  Karşılaştırılacak ikinci metin.
 * @param n   Karşılaştırılacak maksimum karakter sayısı.
 * 
 * @return int Karakter farkı (s1[i] - s2[i]). Eşitlerse 0 döner.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
