/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/13 08:24:27 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ARG=ruby -e "puts (1..100).to_a.shuffle.join(' ')";
 * ./push_swap $ARG | ./checker $ARG
 * */
int	main(int argc, char *argv[])
{
	t_listc	*a;
	t_listc	*b;
	t_mmm	minmaxmed;
	int		score;

	a = init_stack(argc, argv);
	minmaxmed = (t_mmm){};
	check_if_duplicated(&a, &minmaxmed);
	if (check_if_sorted(&a))
		exit(EXIT_SUCCESS);
	if (ft_lstc_size(a) == 5)
		sort_five(&a, &b, minmaxmed);
	leave_three(&a, &b, minmaxmed);
	sort_three(&a);
	while (b)
	{
		score_count(a, b, &score);
		score_process(&a, &b, score);
	}
	sort_final(&a, minmaxmed);
	ft_lstc_clear(&a);
	return (0);
}

void	leave_three(t_listc **a, t_listc **b, t_mmm m)
{
	int	size;

	*b = NULL;
	size = ft_lstc_size(*a);
	if (size <= 3)
		return ;
	while (size--)
	{
		if ((*a)->value == m.min || (*a)->value == m.max \
			|| (*a)->value == m.med)
		{
			ra(a, true);
			continue ;
		}
		if ((*a)->value < m.med)
			pb(a, b, true);
		else
		{
			pb(a, b, true);
			rb(b, true);
		}
	}
}

void	sort_three(t_listc **a)
{
	int	z1;
	int	z2;
	int	z3;

	z1 = (*a)->value;
	z2 = (*a)->next->value;
	z3 = (*a)->next->next->value;
	if (z1 < z2 && z1 < z3 && z2 > z3)
		sa(*a, true);
	if (z1 > z2 && z1 > z3 && z2 > z3)
		sa(*a, true);
	if (z1 > z2 && z2 < z3)
		sa(*a, true);
}

void	sort_five(t_listc **a, t_listc **b, t_mmm m)
{
	get_index(a, m);
	*b = NULL;
	while (ft_lstc_size(*a) != 3)
	{
		if ((*a)->value == 1 || (*a)->value == 5)
		{
			pb(a, b, true);
			continue ;
		}
		ra(a, true);
	}
	sort_three(a);
	if ((*a)->value == 4)
		ra(a, true);
	if ((*a)->value == 3)
		rra(a, true);
	pa(a, b, true);
	if ((*a)->value == 5)
		ra(a, true);
	pa(a, b, true);
	if ((*a)->value == 5)
		ra(a, true);
	ft_lstc_clear(a);
	exit(EXIT_SUCCESS);
}
