/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isdigit.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/06 12:10:22 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/06 12:10:26 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

/*

int	main(void)
{
	char ch = '1';

	if (ft_isdigit((unsigned char)ch))
	{
		printf("%c bir sayidir.\n", ch); // Bu satır çalışır
	}
	else
	{
		printf("%c bir sayi degildir.\n", ch);
	}
	return (0);
}
*/