/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:04:57 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/17 12:04:57 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_bits(int lstsize)
{
	int	max_num;
	int	max_bits;

	max_num = lstsize - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_pass(t_list **stack_a, t_list **stack_b, int lstsize, int bit)
{
	int	i;

	i = 0;
	while (i < lstsize)
	{
		if ((((*stack_a)->index >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

void	sort_complex(t_list **stack_a, t_list **stack_b)
{
	int	lstsize;
	int	max_bits;
	int	i;

	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 1)
		return ;
	set_stack_indexes(stack_a);
	max_bits = get_max_bits(lstsize);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(stack_a, stack_b, lstsize, i);
		i++;
	}
}