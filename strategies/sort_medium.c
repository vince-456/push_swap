/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:05:09 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/17 12:33:42 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_stack_indexes(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		count;

	tmp1 = *stack;
	while (tmp1 != NULL)
	{
		count = 0;
		tmp2 = *stack;
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

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

int	get_pos(t_list *stack, int target_index)
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

void	push_to_b(t_list **stack_a, t_list **stack_b, int chunk)
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
		else if ((*stack_a)->index <= i + chunk)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b, int lstsize)
{
	int	pos;

	while (lstsize > 0)
	{
		pos = get_pos(*stack_b, lstsize - 1);
		if (pos <= lstsize / 2)
		{
			while ((*stack_b)->index != lstsize - 1)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != lstsize - 1)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		lstsize--;
	}
}

void	sort_medium(t_list **stack_a, t_list **stack_b)
{
	int	lstsize;
	int	chunk;

	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 1)
		return ;
	set_stack_indexes(stack_a);
	chunk = ft_sqrt(lstsize) + (ft_sqrt(lstsize) / 2);
	push_to_b(stack_a, stack_b, chunk);
	push_to_a(stack_a, stack_b, lstsize);
}
