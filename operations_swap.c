/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/19 18:48:16 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

/* sa
 * swapping two first values of the stack 'a'
 * exchanging values by bit operations */
void	sa(t_listc *a)
{
	a->value ^= a->next->value;
	a->next->value ^= a->value;
	a->value ^= a->next->value;
	if (write(1, "sa\n", 3))
		return ;
}

/* sb
 * swapping two first values of the stack 'b'
 * exchanging values by sum operations */
void	sb(t_listc *b)
{
	b->value = b->value + b->next->value;
	b->next->value = b->value - b->next->value;
	b->value = b->value - b->next->value;
	if (write(1, "sa\n", 3))
		return ;
}
