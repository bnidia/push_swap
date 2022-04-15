/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/21 02:21:47 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_listc **a, bool print)
{
	*a = (*a)->prev;
	if (print && write(1, "rra\n", 4) == -1)
		exit(EXIT_FAILURE);
}

void	rrb(t_listc **b, bool print)
{
	*b = (*b)->prev;
	if (print && write(1, "rrb\n", 4) == -1)
		exit(EXIT_FAILURE);
}

void	rrr(t_listc **a, t_listc **b, bool print)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	if (print && write(1, "rrr\n", 4) == -1)
		exit(EXIT_FAILURE);
}
