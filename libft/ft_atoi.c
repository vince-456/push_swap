/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_atoi.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 13:30:32 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/12 13:30:33 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Bir metni (string) tamsayıya (int) dönüştürür.
 * 
 * Bu fonksiyon, metnin başındaki boşlukları atlar, varsa işaretini (+/-) 
 * belirler ve ardından gelen rakamları sayısal bir değere çevirir.
 * 
 * @param nptr  Dönüştürülecek olan metin.
 * 
 * @return int  Metinden elde edilen tamsayı değeri. 
 *              Geçerli bir sayı bulunamazsa 0 döner.
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
