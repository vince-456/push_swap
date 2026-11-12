/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:56:53 by vkoch             #+#    #+#             */
/*   Updated: 2026/10/22 19:13:06 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (count != 0 && size > (size_t)-1 / count)
		return (0);
	tab = malloc(count * size);
	if (!tab)
		return (0);
	ft_bzero(tab, count * size);
	return (tab);
}

