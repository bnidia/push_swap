/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/19 18:48:39 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ra(t_listc **a)
{
	*a = (*a)->next;
	if (write(1, "ra\n", 3) == -1)
		exit(EXIT_FAILURE);
}

void	rb(t_listc **b)
{
	*b = (*b)->next;
	if (write(1, "rb\n", 3) == -1)
		exit(EXIT_FAILURE);
}

void	rr(t_listc **a, t_listc **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	if (write(1, "rr\n", 3) == -1)
		exit(EXIT_FAILURE);
}
