/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:10:39 by vkoch             #+#    #+#             */
/*   Updated: 2026/10/20 16:12:45 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	while (str[i] != 0)
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
