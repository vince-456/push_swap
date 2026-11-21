/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:44:44 by fozturk           #+#    #+#             */
/*   Updated: 2026/11/18 22:17:25 by vkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_value(t_list *stack)
{
	int		min_value;
	t_list	*current;

	if (!stack)
		return (0);
	min_value = *(int *)stack->content;
	current = stack->next;
	while (current)
	{
		if (*(int *)current->content < min_value)
			min_value = *(int *)current->content;
		current = current->next;
	}
	return (min_value);
}

static int	find_value_index(t_list *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (index);
		index++;
		stack = stack->next;
	}
	return (0);
}

static void	move_min_to_top(t_list **a, int min_value, t_bench *bench)
{
	int	index;
	int	size;

	if (!a || !*a)
		return ;
	size = ft_lstsize(*a);
	while (*(int *)(*a)->content != min_value)
	{
		index = find_value_index(*a, min_value);
		if (index <= (size / 2))
			ra(a, bench);
		else
			rra(a, bench);
		if (size > 1)
			size = ft_lstsize(*a);
	}
}

int	sort_simple(t_list **a, t_list **b, t_bench *bench)
{
	int		min_value;
	int		size;

	if (!a || !*a)
		return (0);

	size = ft_lstsize(*a);
	if (size <= 1)
		return (0);
	while (*a)
	{
		min_value = find_min_value(*a);
		move_min_to_top(a, min_value, bench);
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
	return (1);
}
