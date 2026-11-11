/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:19:03 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/11 18:45:52 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write (1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write (1, "pb\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write (1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write (1, "rr\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*prev;

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
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*prev;

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
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write (1, "rrr\n", 4);
}
