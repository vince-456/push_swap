/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:48:42 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/17 14:51:47 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack_a, t_bench *bench)
{
	int	tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->number;
	(*stack_a)->number = (*stack_a)->next->number;
	(*stack_a)->next->number = tmp;
	if (bench)
	{
		ft_putstr_fd("sa\n", 1);
		bench->sa++;
	}
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	int	tmp;

	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	tmp = (*stack_b)->number;
	(*stack_b)->number = (*stack_b)->next->number;
	(*stack_b)->next->number = tmp;
	if (bench)
	{
		ft_putstr_fd("sb\n", 1);
		bench->sb++;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next
		|| !stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (bench)
	{
		ft_putstr_fd("ss\n", 1);
		bench->ss++;
	}
}
