/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/21 02:21:20 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_final(t_listc **stack_a, t_mmm	minmaxmed)
{
	t_listc	*a;
	int		size;
	int		i;

	a = *stack_a;
	i = 0;
	size = ft_lstc_size(a);
	while (a->value != minmaxmed.min)
	{
		a = a->next;
		i++;
	}
	if (i < size / 2)
		while ((*stack_a)->value != minmaxmed.min)
			rra(stack_a, true);
	else
		while ((*stack_a)->value != minmaxmed.min)
			ra(stack_a, true);
}

void	get_index(t_listc **a, t_mmm m)
{
	int	i;

	i = 0;
	while (i++ < 5)
	{
		if ((*a)->value == m.min)
			(*a)->score_ra = 1;
		else if ((*a)->value > m.min && (*a)->value < m.med)
			(*a)->score_ra = 2;
		else if ((*a)->value == m.med)
			(*a)->score_ra = 3;
		else if ((*a)->value > m.med && (*a)->value < m.max)
			(*a)->score_ra = 4;
		else if ((*a)->value == m.max)
			(*a)->score_ra = 5;
		*a = (*a)->next;
	}
	i = 0;
	while (i++ < 5)
	{
		(*a)->value = (*a)->score_ra;
		(*a)->score_ra = 0;
		*a = (*a)->next;
	}
}

bool	check_if_sorted(t_listc **stack_a)
{
	int		size;
	t_listc	*a;

	a = *stack_a;
	size = ft_lstc_size(a) - 1;
	while (size--)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	ft_lstc_clear(stack_a);
	return (true);
}

void	check_if_duplicated(t_listc **a, t_mmm *minmaxmed)
{
	int	*nums;
	int	i;

	nums = (int *)ft_malloc(sizeof(int) * ft_lstc_size(*a));
	i = 0;
	while (i < ft_lstc_size(*a))
	{
		nums[i++] = (*a)->value;
		*a = (*a)->next;
	}
	ft_quick_sort(nums, 0, ft_lstc_size(*a) - 1);
	i = 0;
	while (i++ < ft_lstc_size(*a) - 1)
	{
		if (nums[i - 1] == nums[i])
		{
			ft_lstc_clear(a);
			ft_error();
		}
	}
	minmaxmed->min = nums[0];
	minmaxmed->med = nums[ft_lstc_size(*a) / 2];
	minmaxmed->max = nums[ft_lstc_size(*a) - 1];
	free(nums);
}
