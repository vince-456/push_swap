/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isalnum.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/06 12:42:22 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/06 12:42:24 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c > 64 && c < 91)
		return (1);
	if (c > 96 && c < 123)
		return (1);
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char ch = '1';

	if (ft_isalnum((unsigned char)ch))
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
