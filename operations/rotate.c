/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotate.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/10 21:08:09 by fozturk        #+#    #+#                */
/*   Updated: 2026/11/10 21:08:11 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **a, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return (0);
	last = ft_lstlast(*a);
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	last->next = first;
	if (bench)
	{
		ft_putstr_fd("ra\n", 1);
		bench->ra++;
	}
	return (1);
}

int	rb(t_list **b, t_bench *bench)
{
	t_list	*first;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return (0);
	last = ft_lstlast(*b);
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	last->next = first;
	if (bench)
	{
		ft_putstr_fd("rb\n", 1);
		bench->rb++;
	}
	return (1);
}

int	rr(t_list **a, t_list **b, t_bench *bench)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return (0);
	ra(a, 0);
	rb(b, 0);
	if (bench)
	{
		ft_putstr_fd("rr\n", 1);
		bench->rr++;
	}
	return (1);
}
