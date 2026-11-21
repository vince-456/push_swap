/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strnstr.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 13:30:32 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/12 13:30:33 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Bir metin içinde, belirli bir karakter sınırına kadar alt metin arar.
 * 
 * Bu fonksiyon, standart C kütüphanesindeki `strnstr` fonksiyonunun bir 
 * kopyasıdır.
 * 'haystack' (ana metin) içinde 'needle' (aranan kelime) ifadesini arar, ancak 
 * arama işlemini 'len' karakter sınırı ile kısıtlar.
 * 
 * @param haystack  İçinde arama yapılacak ana metin.
 * @param needle    Aranan alt metin (kelime).
 * @param len       Arama yapılacak maksimum karakter sınırı.
 * 
 * @return char*    - Eğer 'needle' boş bir metinse, 'haystack'in kendisini 
 						döndürür.
 *                  - Eğer 'needle' ilk 'len' karakter içinde bulunursa, bulduğu 
 *                    ilk karakterin bellek adresini (pointer) döndürür.
 *                  - Kelime sınır içinde bulunamazsa NULL döndürür.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
