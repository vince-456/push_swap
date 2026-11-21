/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:53:57 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/17 15:54:37 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_min_index(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		min_idx;
	int		i;

	tmp = stack;
	min = tmp->number;
	min_idx = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->number < min)
		{
			min = tmp->number;
			min_idx = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_idx);
}

void	sort_three(t_stack **stack_a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	if (first > second && second < third && first < third)
		sa(stack_a, bench);
	else if (first > second && second > third)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, bench);
}

void	sort_simple(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	min_idx;
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		min_idx = get_min_index(*stack_a);
		if (min_idx <= size / 2)
		{
			while (min_idx-- > 0)
				ra(stack_a, bench);
		}
		else
		{
			while (min_idx++ < size)
				rra(stack_a, bench);
		}
		pb(stack_a, stack_b, bench);
		size = ft_lstsize(*stack_a);
	}
	sort_three(stack_a, bench);
	while (*stack_b != NULL)
		pa(stack_a, stack_b, bench);
}
