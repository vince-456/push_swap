/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:03:35 by vkoch             #+#    #+#             */
/*   Updated: 2026/10/19 16:50:36 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	while (str[i] != 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (0);
}
