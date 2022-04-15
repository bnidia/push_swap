/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/21 02:21:56 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_listc **stack_a, t_listc **stack_b, bool print)
{
	t_listc	*a;
	t_listc	*b;

	if (*stack_b == NULL)
		return ;
	a = *stack_a;
	b = *stack_b;
	if (b == b->next)
		*stack_b = NULL;
	else
		*stack_b = b->next;
	ft_lstc_pop(b);
	if (a == NULL)
		a = b;
	else
		ft_lstc_add(a->prev, b);
	*stack_a = a->prev;
	if (print && write(1, "pa\n", 3) == -1)
		exit(EXIT_FAILURE);
}

void	pb(t_listc **stack_a, t_listc **stack_b, bool print)
{
	t_listc	*a;
	t_listc	*b;

	if (*stack_a == NULL)
		return ;
	a = *stack_a;
	b = *stack_b;
	if (a == a->next)
		*stack_a = NULL;
	else
		*stack_a = a->next;
	ft_lstc_pop(a);
	if (b == NULL)
		b = a;
	else
		ft_lstc_add(b->prev, a);
	*stack_b = b->prev;
	if (print && write(1, "pb\n", 3) == -1)
		exit(EXIT_FAILURE);
}
