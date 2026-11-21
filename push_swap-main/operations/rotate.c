/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:52:26 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/17 14:54:03 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **stack_a, t_bench *bench)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (bench)
	{
		ft_putstr_fd("ra\n", 1);
		bench->ra++;
	}
}

void	rb(t_stack **stack_b, t_bench *bench)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (bench)
	{
		ft_putstr_fd("rb\n", 1);
		bench->rb++;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next
		|| !stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (bench)
	{
		ft_putstr_fd("rr\n", 1);
		bench->rr++;
	}
}
