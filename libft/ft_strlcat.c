/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:51:45 by vkoch             #+#    #+#             */
/*   Updated: 2026/10/22 18:52:20 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	d_size;
	size_t	s_size;
	size_t	i;

	d_size = 0;
	while (d_size < destsize && dest[d_size] != 0)
		d_size++;
	s_size = ft_strlen(src);
	if (d_size == destsize)
		return (destsize + s_size);
	i = 0;
	while (i < destsize - d_size - 1 && src[i] != 0)
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = 0;
	return (d_size + s_size);
}
