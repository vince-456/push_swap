/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 01:23:53 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/20 01:23:53 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **a, t_list **b, int st, t_bench *bench)
{
	if (bench->disorder == 0.0)
		return ;
	if (st == 1)
		sort_simple(a, b, bench);
	else if (st == 2)
		sort_medium(a, b, bench);
	else if (st == 3)
		sort_complex(a, b, bench);
	else
		sort_simple(a, b, bench);   /* tri par défaut si aucun flag */
}

int	main(int argc, char **argv)
{
	int		st;
	t_bench	bench;
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	st = 0;
	ft_bzero(&bench, sizeof(t_bench));
	a = parse_nums(parse_flags(argv, &st, &bench));
	if (!a)
		return (0);
	bench.disorder = compute_disorder(a);
	b = NULL;
	push_swap(&a, &b, st, &bench);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
