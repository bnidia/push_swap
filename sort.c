/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/20 13:46:34 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern void	sa(t_listc *a);
extern void	rra(t_listc **a);
extern void	ra(t_listc **a);
extern void	pb(t_listc **a, t_listc **b);
extern void	pa(t_listc **a, t_listc **b);
static void	get_index(t_listc **a, t_mmm m);

void	sort_three(t_listc **a)
{
	int	z1;
	int	z2;
	int	z3;

	z1 = (*a)->value;
	z2 = (*a)->next->value;
	z3 = (*a)->next->next->value;
	if (z1 < z2 && z1 < z3 && z2 > z3)
		sa(*a);
	if (z1 > z2 && z1 > z3 && z2 > z3)
		sa(*a);
	if (z1 > z2 && z2 < z3)
		sa(*a);
}

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
			rra(stack_a);
	else
		while ((*stack_a)->value != minmaxmed.min)
			ra(stack_a);
}

void	sort_five(t_listc **a, t_listc **b, t_mmm m)
{
	get_index(a, m);
	while (ft_lstc_size(*a) != 3)
	{
		if ((*a)->value == 1 || (*a)->value == 5)
		{
			pb(a, b);
			continue ;
		}
		ra(a);
	}
	sort_three(a);
	if ((*a)->value == 4)
		ra(a);
	if ((*a)->value == 3)
		rra(a);
	pa(a, b);
	if ((*a)->value == 5)
		ra(a);
	pa(a, b);
	if ((*a)->value == 5)
		ra(a);
	ft_lstc_clear(a);
	exit(EXIT_SUCCESS);
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
