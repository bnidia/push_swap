/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/19 19:10:47 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	rra(t_listc **a)
{
	*a = (*a)->prev;
	if (write(1, "rra\n", 4) == -1)
		exit(EXIT_FAILURE);
}

void	rrb(t_listc **b)
{
	*b = (*b)->prev;
	if (write(1, "rrb\n", 4) == -1)
		exit(EXIT_FAILURE);
}

void	rrr(t_listc **a, t_listc **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	if (write(1, "rrr\n", 4) == -1)
		exit(EXIT_FAILURE);
}
