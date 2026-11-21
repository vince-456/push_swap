/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   swap.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/10 18:40:31 by fozturk        #+#    #+#                */
/*   Updated: 2026/11/10 18:40:33 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **a, t_bench *bench)
{
	t_list	*first;

	if (!a || !*a || !(*a)->next)
		return (0);
	first = *a;
	*a = (*a)->next;
	first->next = (*a)->next;
	(*a)->next = first;
	if (bench)
	{
		ft_putstr_fd("sa\n", 1);
		bench->sa++;
	}
	return (1);
}

int	sb(t_list **b, t_bench *bench)
{
	t_list	*first;

	if (!b || !*b || !(*b)->next)
		return (0);
	first = *b;
	*b = (*b)->next;
	first->next = (*b)->next;
	(*b)->next = first;
	if (bench)
	{
		ft_putstr_fd("sb\n", 1);
		bench->sb++;
	}
	return (1);
}

int	ss(t_list **a, t_list **b, t_bench *bench)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return (0);
	sa(a, 0);
	sb(b, 0);
	if (bench)
	{
		ft_putstr_fd("ss\n", 1);
		bench->ss++;
	}
	return (1);
}
