/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memset.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/06 13:40:02 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/06 13:40:12 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		*((unsigned char *)ptr + i) = (unsigned char)value;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	int	sayilar[5] = {5, 4, 8, 3, 9};

	ft_memset(sayilar, 47, sizeof(sayilar));
	printf("Ilk eleman: %d\n", sayilar[0]);
	return (0);
}
*/