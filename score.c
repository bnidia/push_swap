/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/21 02:21:08 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
	score_rr_rrr(b, stack_a, stack_b, true);
	while (b->score_ra-- > 0)
		ra(stack_a, true);
	while (b->score_rb-- > 0)
		rb(stack_b, true);
	while (b->score_rra-- > 0)
		rra(stack_a, true);
	while (b->score_rrb-- > 0)
		rrb(stack_b, true);
	pa(stack_a, stack_b, true);
}

void	score_rr_rrr(t_listc *b, t_listc **stack_a, t_listc **stack_b, bool p)
{
	while (b->score_rb > 0 && b->score_ra > 0)
	{
		rr(stack_a, stack_b, p);
		b->score_rb--;
		b->score_ra--;
	}
	while (b->score_rrb > 0 && b->score_rra > 0)
	{
		rrr(stack_a, stack_b, p);
		b->score_rrb--;
		b->score_rra--;
	}
}

void	reset_scores(t_listc *b)
{
	b->score_ra = 0;
	b->score_rb = 0;
	b->score_rra = 0;
	b->score_rrb = 0;
}

void	score_count_a(t_listc *a, t_listc *b)
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
