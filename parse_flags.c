/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   parse_flags.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/10 20:38:49 by fozturk        #+#    #+#                */
/*   Updated: 2026/11/10 20:38:51 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_flag(char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		return (1);
	else if (!ft_strcmp(arg, "--medium"))
		return (2);
	else if (!ft_strcmp(arg, "--complex"))
		return (3);
	else if (!ft_strcmp(arg, "--adaptive"))
		return (4);
	else if (!ft_strcmp(arg, "--bench"))
		return (5);
	return (0);
}

static void	set_strategy(int flag, t_bench *bench)
{
	if (flag == 1)
		bench->strategy = "Simple / O(n^2)";
	else if (flag == 2)
		bench->strategy = "Medium / O(n√n)";
	else if (flag == 3)
		bench->strategy = "Complex / O(n log n)";
	else if (bench->disorder < 0.2)
		bench->strategy = "Adaptive / O(n^2)";
	else if (bench->disorder < 0.5)
		bench->strategy = "Adaptive / O(n√n)";
	else
		bench->strategy = "Adaptive / O(n log n)";
}

char	**parse_flags(char **argv, int *st, t_bench *bench)
{
	int	i;
	int	flag;

	i = 1;
	while (argv[i] && i < 3)
	{
		flag = is_flag(argv[i]);
		if (flag >= 1 && flag <= 4)
		{
			*st = flag;
			set_strategy(flag, bench);
		}
		else if (flag == 5)
			bench->enabled = 1;
		else
			break ;
		i++;
	}
	return (&argv[i]);
}
