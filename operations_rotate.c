/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/21 02:21:43 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_listc **a, bool print)
{
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	if (print && write(1, "ra\n", 3) == -1)
		exit(EXIT_FAILURE);
}

void	rb(t_listc **b, bool print)
{
	if (*b == NULL)
		return ;
	*b = (*b)->next;
	if (print && write(1, "rb\n", 3) == -1)
		exit(EXIT_FAILURE);
}

void	rr(t_listc **a, t_listc **b, bool print)
{
	if (*a != NULL)
		*a = (*a)->next;
	if (*b != NULL)
		*b = (*b)->next;
	if (print && write(1, "rr\n", 3) == -1)
		exit(EXIT_FAILURE);
}
