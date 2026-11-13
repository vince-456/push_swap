/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 22:09:21 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/12 22:41:16 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_chunk(t_list **stack_a, t_list **stack_b, unsigned int	lstsize)
{
	int				smallest_number;
	int				index;
	int				min_index;
	t_list			*tmp;

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
}

void	sort_index(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		count;

	tmp1 = *stack_a;
	while (tmp1 != NULL)
	{
		count = 0;
		tmp2 = *stack_a;
		while (tmp2 != NULL)
		{
			if (tmp2->number < tmp1->number)
				count++;
			tmp2 = tmp2->next;
		}
		tmp1->index = count;
		tmp1 = tmp1->next;
	}
}

void	sort_medium(t_list **stack_a, t_list **stack_b)
{
	int				num_chunks;
	int				chunk_size;
	unsigned int	lstsize;

	lstsize = ft_lstsize(*stack_a);
	num_chunks = sqrt(lstsize);
	chunk_size = lstsize / num_chunks;
	sort_index(stack_a);
}
