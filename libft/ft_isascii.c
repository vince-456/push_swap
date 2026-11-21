/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isascii.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/06 13:00:08 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/06 13:00:11 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	k = 'a';

	if (ft_isascii((unsigned char)k))
		printf("%c evet ascii karakteri", k);
	else
		printf("%c hayir ascii karakteri degil", k);
	return (0);
}
*/