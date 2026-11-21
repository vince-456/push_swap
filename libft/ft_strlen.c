/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strlen.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/06 13:24:03 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/06 13:24:06 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char *text = "selam dunya";
	size_t	tstrlen;

	tstrlen = ft_strlen(text);

	printf("uzunluk: %zu\n", tstrlen);
	return (0);
}
*/