/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   reverse_rotate.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/10 21:08:27 by fozturk        #+#    #+#                */
/*   Updated: 2026/11/10 21:08:28 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstprev_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	rra(t_list **a, t_bench *bench)
{
	t_list	*last;
	t_list	*prev_last;

	if (!a || !*a || !(*a)->next)
		return (0);
	prev_last = ft_lstprev_last(*a);
	last = prev_last->next;
	last->next = *a;
	*a = last;
	prev_last->next = NULL;
	if (bench)
	{
		ft_putstr_fd("rra\n", 1);
		bench->rra++;
	}
	return (1);
}

int	rrb(t_list **b, t_bench *bench)
{
	t_list	*last;
	t_list	*prev_last;

	if (!b || !*b || !(*b)->next)
		return (0);
	prev_last = ft_lstprev_last(*b);
	last = prev_last->next;
	last->next = *b;
	*b = last;
	prev_last->next = NULL;
	if (bench)
	{
		ft_putstr_fd("rrb\n", 1);
		bench->rrb++;
	}
	return (1);
}

int	rrr(t_list **a, t_list **b, t_bench *bench)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return (0);
	rra(a, 0);
	rrb(b, 0);
	if (bench)
	{
		ft_putstr_fd("rrr\n", 1);
		bench->rrr++;
	}
	return (1);
}
