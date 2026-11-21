/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:35:52 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/21 13:35:52 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_bench
{
	int		enabled;
	double	disorder;
	char	*strategy;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

char	**parse_flags(char **argv, int *st, t_bench *bench);
t_list	*parse_nums(char **argv);

double	compute_disorder(t_list *a);
void	print_bench(t_bench *b);

int		sort_simple(t_list **a, t_list **b, t_bench *bench);
int		sort_medium(t_list **a, t_list **b, t_bench *bench);
int		sort_complex(t_list **a, t_list **b, t_bench *bench);
int		sort_adaptive(t_list **a, t_list **b, t_bench *bench);

void	set_stack_indexes(t_list **stack);
int		ft_sqrt(int nb);
int		get_pos(t_list *stack, int target_index);

int		sa(t_list **a, t_bench *bench);
int		sb(t_list **a, t_bench *bench);
int		ss(t_list **a, t_list **b, t_bench *bench);

int		pb(t_list **a, t_list **b, t_bench *bench);
int		pa(t_list **a, t_list **b, t_bench *bench);

int		ra(t_list **a, t_bench *bench);
int		rb(t_list **b, t_bench *bench);
int		rr(t_list **a, t_list **b, t_bench *bench);

int		rra(t_list **a, t_bench *bench);
int		rrb(t_list **b, t_bench *bench);
int		rrr(t_list **a, t_list **b, t_bench *bench);

#endif
