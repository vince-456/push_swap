/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:25:57 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/12 14:26:27 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_strategy(void)
{
	if (compute_disorder < 0.2)
		sort_simple(stack_a, stack_b);
	if (0.2 <= compute_disorder < 0.5)
		sort_medium(stack_a, stack_b);
	if (0.5 <= compute_disorder)
		sort_complex(stack_a, stack_b);
}
