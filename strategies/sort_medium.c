/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:29:45 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/16 18:47:57 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

static int	get_pos(t_list *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack != NULL)
	{
		if (stack->index == target_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

static void	push_back_to_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	pos;

	while (size > 0)
	{
		pos = get_pos(*stack_b, size - 1);
		if (pos <= size / 2)
		{
			while ((*stack_b)->index != size - 1)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != size - 1)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		size--;
	}
}

void	sort_medium(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	range;

	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	sort_index(stack_a);
	range = ft_sqrt(size) + (ft_sqrt(size) / 2);
	push_chunks_to_b(stack_a, stack_b, range);
	push_back_to_a(stack_a, stack_b, size);
}
