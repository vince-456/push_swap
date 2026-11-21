/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isprint.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/08 13:19:24 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/08 13:19:42 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	k = 'a';
    char	ch1 = 'A';
    char	ch2 = '\n'; // Alt satıra geçme (kontrol karakteri)

	if (ft_isprint((unsigned char)k))
		printf("%c evet ascii karakteri\n", k);
	else
		printf("%c hayir ascii karakteri degil\n", k);


	if (ft_isprint((unsigned char)ch1))
		printf("%c evet ascii karakteri\n", ch1);
	else
		printf("%c hayir ascii karakteri degil\n", ch1);


	if (ft_isprint((unsigned char)ch2))
		printf("%c evet ascii karakteri\n", ch2);
	else
		printf("%c hayir ascii karakteri degil\n", ch2);	

	return (0);
}
*/
