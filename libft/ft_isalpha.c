/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isalpha.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/06 11:29:50 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/06 11:30:08 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if (c > 64 && c < 91)
		return (1);
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

/*

int main() {
    char ch = '1';

    if (ft_isalpha((unsigned char)ch)) {
        printf("%c bir harftir.\n", ch); // Bu satır çalışır
    } else {
        printf("%c bir harf degildir.\n", ch);
    }
    return 0;
}*/