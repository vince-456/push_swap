/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:25:17 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/12 14:25:17 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a)
{
	int	tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->number;
	(*stack_a)->number = (*stack_a)->next->number;
	(*stack_a)->next->number = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	int	tmp;

	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	tmp = (*stack_b)->number;
	(*stack_b)->number = (*stack_b)->next->number;
	(*stack_b)->next->number = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
