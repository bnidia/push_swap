/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/19 18:49:54 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	pa(t_listc **stack_a, t_listc **stack_b)
{
	t_listc	*a;
	t_listc	*b;

	a = *stack_a;
	b = *stack_b;
	if (b == b->next)
		*stack_b = NULL;
	else
		*stack_b = b->next;
	ft_lstc_pop(b);
	ft_lstc_add(a->prev, b);
	*stack_a = b;
	if (write(1, "pa\n", 3) == -1)
		exit(EXIT_FAILURE);
}

void	pb(t_listc **a, t_listc **b)
{
	t_listc	*pop;

	pop = *a;
	*a = (*a)->next;
	ft_lstc_pop(pop);
	if (*b == NULL)
		*b = pop;
	else
		ft_lstc_add((*b)->prev, pop);
	*b = (*b)->prev;
	if (write(1, "pb\n", 3) == -1)
		exit(EXIT_FAILURE);
}
