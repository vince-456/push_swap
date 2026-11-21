/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:54:36 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/17 14:57:39 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack_a, t_bench *bench)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (bench)
	{
		ft_putstr_fd("rra\n", 1);
		bench->rra++;
	}
}

void	rrb(t_stack **stack_b, t_bench *bench)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (bench)
	{
		ft_putstr_fd("rrb\n", 1);
		bench->rrb++;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next
		|| !stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (bench)
	{
		ft_putstr_fd("rrr\n", 1);
		bench->rrr++;
	}
}
