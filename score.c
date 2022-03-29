/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/21 09:02:05 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

extern void	rr(t_listc **a, t_listc **b);
extern void	rrr(t_listc **a, t_listc **b);
extern void	ra(t_listc **a);
extern void	rb(t_listc **b);
extern void	rra(t_listc **a);
extern void	rrb(t_listc **b);
extern void	pa(t_listc **stack_a, t_listc **stack_b);
static void	rr_rrr(t_listc *b, t_listc **stack_a, t_listc **stack_b);
static void	reset_scores(t_listc *b);
static void	score_count_a(t_listc *a, t_listc *b);

void	score_count(t_listc *stack_a, t_listc *stack_b, int *score)
{
	t_listc	*a;
	t_listc	*b;
	int		len_b;
	int		i;

	b = stack_b;
	a = stack_a;
	i = 0;
	*score = INT_MAX;
	len_b = ft_lstc_size(b);
	while (i < len_b)
	{
		reset_scores(b);
		score_count_a(a, b);
		b->score_rb = i;
		b->score_rrb = len_b - i;
		if (b->score_rrb >= b->score_rb)
			b->score_rrb = 0;
		else
			b->score_rb = 0;
		if (*score > b->score_rb + b->score_ra + b->score_rrb + b->score_rra)
			*score = b->score_rb + b->score_ra + b->score_rrb + b->score_rra;
		b = b->next;
		i++;
	}
}

void	score_process(t_listc **stack_a, t_listc **stack_b, int score)
{
	t_listc	*b;

	b = *stack_b;
	while (b->score_rb + b->score_ra + b->score_rrb + b->score_rra != score)
		b = b->next;
	rr_rrr(b, stack_a, stack_b);
	while (b->score_ra-- > 0)
		ra(stack_a);
	while (b->score_rb-- > 0)
		rb(stack_b);
	while (b->score_rra-- > 0)
		rra(stack_a);
	while (b->score_rrb-- > 0)
		rrb(stack_b);
	pa(stack_a, stack_b);
}

static void	rr_rrr(t_listc *b, t_listc **stack_a, t_listc **stack_b)
{
	while (b->score_rb > 0 && b->score_ra > 0)
	{
		rr(stack_a, stack_b);
		b->score_rb--;
		b->score_ra--;
	}
	while (b->score_rrb > 0 && b->score_rra > 0)
	{
		rrr(stack_a, stack_b);
		b->score_rrb--;
		b->score_rra--;
	}
}

static void	reset_scores(t_listc *b)
{
	b->score_ra = 0;
	b->score_rb = 0;
	b->score_rra = 0;
	b->score_rrb = 0;
}

static void	score_count_a(t_listc *a, t_listc *b)
{
	int		len_a;
	int		j;

	j = 0;
	len_a = ft_lstc_size(a);
	while (j < len_a)
	{
		a = a->next;
		b->score_ra++;
		if (b->value > a->prev->value && b->value < a->value)
			break ;
		j++;
	}
	b->score_rra = len_a - b->score_ra;
	if (b->score_rra >= b->score_ra)
		b->score_rra = 0;
	else
		b->score_ra = 0;
}
