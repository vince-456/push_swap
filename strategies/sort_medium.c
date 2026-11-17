/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:57:56 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/17 15:57:56 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size,
	t_bench *bench)
{
	int	i;

	i = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, bench);
			rb(stack_b, bench);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk_size)
		{
			pb(stack_a, stack_b, bench);
			i++;
		}
		else
			ra(stack_a, bench);
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b, int lstsize,
	t_bench *bench)
{
	int	pos;

	while (lstsize > 0)
	{
		pos = get_pos(*stack_b, lstsize - 1);
		if (pos <= lstsize / 2)
		{
			while ((*stack_b)->index != lstsize - 1)
				rb(stack_b, bench);
		}
		else
		{
			while ((*stack_b)->index != lstsize - 1)
				rrb(stack_b, bench);
		}
		pa(stack_a, stack_b, bench);
		lstsize--;
	}
}

void	sort_medium(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	lstsize;
	int	chunk_size;

	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 1)
		return ;
	set_stack_indexes(stack_a);
	chunk_size = ft_sqrt(lstsize) + (ft_sqrt(lstsize) / 2);
	push_to_b(stack_a, stack_b, chunk_size, bench);
	push_to_a(stack_a, stack_b, lstsize, bench);
}
