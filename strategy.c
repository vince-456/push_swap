/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:15:48 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/12 12:25:24 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_strategy(void)
{
	if (compute_disorder < 0.2)
		sort_simple(stack_a, stack_b);
	if (0.2 <= compute_disorder < 0.5)

	if (0.5 <= compute_disorder)

}

void	sort_simple(t_list **stack_a, t_list **stack_b)
{
	int				smallest_number;
	int				index;
	int				min_index;
	unsigned int	lstsize;
	t_list			*tmp;

	lstsize = ft_lstsize(stack_a);
	while (*stack_a != NULL)
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
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
