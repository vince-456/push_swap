/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:26:52 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/12 15:26:52 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **stack_a)
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
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_simple(t_list **stack_a, t_list **stack_b)
{
	int				smallest_number;
	int				index;
	int				min_index;
	unsigned int	lstsize;
	t_list			*tmp;

	lstsize = ft_lstsize(*stack_a);
	while (lstsize > 3)
	{
		smallest_number = (*stack_a)->number;
		index = 0;
		min_index = 0;
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (tmp->number < smallest_number)
			{
				smallest_number = tmp->number;
				min_index = index;
			}
			index++;
			tmp = tmp->next;
		}
		if (lstsize / 2 > min_index)
		{
			while ((*stack_a)->number != smallest_number)
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->number != smallest_number)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		lstsize--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
