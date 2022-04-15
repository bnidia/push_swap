/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/21 02:21:38 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa
 * swapping two first values of the stack 'a'
 * exchanging values by bit operations */
void	sa(t_listc *a, bool print)
{
	if (a == NULL)
		return ;
	a->value ^= a->next->value;
	a->next->value ^= a->value;
	a->value ^= a->next->value;
	if (print && write(1, "sa\n", 3))
		return ;
}

/* sb
 * swapping two first values of the stack 'b'
 * exchanging values by sum operations */
void	sb(t_listc *b, bool print)
{
	if (b == NULL)
		return ;
	b->value = b->value + b->next->value;
	b->next->value = b->value - b->next->value;
	b->value = b->value - b->next->value;
	if (print && write(1, "sa\n", 3))
		return ;
}

void	ss(t_listc *a, t_listc *b, bool print)
{
	if (a != NULL)
		sa(a, print);
	if (b != NULL)
		sb(b, print);
}
