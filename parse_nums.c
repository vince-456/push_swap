/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkoch <vkoch@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:49:31 by vkoch             #+#    #+#             */
/*   Updated: 2026/11/20 20:49:31 by vkoch            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	err_exit(t_list **nums)
{
	ft_lstclear(nums, free);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	add_num(t_list **nums, int val)
{
	t_list	*tmp;
	int		*content;

	tmp = *nums;
	while (tmp)
	{
		if (*(int *)(tmp->content) == val)
			err_exit(nums);
		tmp = tmp->next;
	}
	content = (int *)ft_calloc(1, sizeof(int));
	if (!content)
		err_exit(nums);
	*content = val;
	tmp = ft_lstnew(content);
	if (!tmp)
	{
		free(content);
		err_exit(nums);
	}
	ft_lstadd_back(nums, tmp);
}

static long	parse_one(char **s, t_list **nums)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (**s == '-' || **s == '+')
		if (*(*s)++ == '-')
			sign = -1;
	if (!ft_isdigit(**s))
		err_exit(nums);
	while (ft_isdigit(**s))
	{
		res = res * 10 + (*(*s)++ - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			err_exit(nums);
	}
	if (**s && **s != ' ')
		err_exit(nums);
	return (res * sign);
}

t_list	*parse_nums(char **argv)
{
	t_list	*nums;
	char	*s;
	int		i;

	nums = NULL;
	i = 0;
	while (argv[i])
	{
		s = argv[i++];
		while (*s == ' ')
			s++;
		if (!*s)
			err_exit(&nums);
		while (*s)
		{
			add_num(&nums, (int)parse_one(&s, &nums));
			while (*s == ' ')
				s++;
		}
	}
	return (nums);
}
