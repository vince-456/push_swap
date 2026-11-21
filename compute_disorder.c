/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   compute_disorder.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/11 14:51:07 by fozturk        #+#    #+#                */
/*   Updated: 2026/11/11 14:51:08 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_list *a)
{
	long long	mistakes;
	long long	total_pairs;
	long long	n;
	t_list		*i;
	t_list		*j;

	mistakes = 0;
	n = ft_lstsize(a);
	total_pairs = (n * (n - 1)) / 2;
	if (total_pairs == 0)
		return (0.0);
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)(i->content) > *(int *)(j->content))
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
