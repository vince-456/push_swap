/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memmove.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/09 11:11:25 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/09 11:11:28 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
/*int	main(void)
{
	char	arr[] = "ABCDE";
	char	*src = &arr[0];
	char	*dest = &arr[2];

	ft_memmove(dest, src, 3);
	printf("Dizinin son hali: %s\n", arr);
	printf("src ne görüyor?  : %s\n", src);
	printf("dest ne görüyor? : %s\n", dest);
	return (0);
}*/
