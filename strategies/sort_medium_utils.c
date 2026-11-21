/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 01:34:31 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/20 01:34:31 by vkoch            ###   ########.ch       */
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
			if (*(int *)tmp2->content < *(int *)tmp1->content)
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
