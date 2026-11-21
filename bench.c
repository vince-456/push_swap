/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:36:13 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/18 22:36:19 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putdisorder_fd(double disorder, int fd)
{
	int	val;

	val = (int)(disorder * 100.0 + 0.5);
	ft_putnbr_fd(val / 100, fd);
	ft_putchar_fd('.', fd);
	if (val % 100 < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(val % 100, fd);
	ft_putstr_fd("%\n", fd);
}

static void	print_ops_line(t_bench *b)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(b->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_bench *b)
{
	int	total;

	if (!b->enabled)
		return ;
	total = b->sa + b->sb + b->ss + b->pa + b->pb + b->ra
		+ b->rb + b->rr + b->rra + b->rrb + b->rrr;
	ft_putstr_fd("\n[bench] disorder:  ", 2);
	ft_putdisorder_fd(b->disorder, 2);
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(b->strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
	print_ops_line(b);
}
