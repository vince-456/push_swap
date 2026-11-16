/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:14:03 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/16 19:14:03 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	radix_pass(t_list **stack_a, t_list **stack_b, int size, int bit)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*stack_a)->index >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		j++;
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

void	sort_complex(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	i;

	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	sort_index(stack_a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(stack_a, stack_b, size, i);
		i++;
	}
}