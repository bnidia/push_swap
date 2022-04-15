/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/21 02:21:32 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include "libft.h"
# include "ft_lstc.h"

typedef struct s_minmaxmed
{
	int	min;
	int	med;
	int	max;
}			t_mmm;

t_listc	*init_stack(int argc, char *argv[]);
bool	check_if_sorted(t_listc **stack_a);
void	check_if_duplicated(t_listc **a, t_mmm *minmaxmed);
void	ft_quick_sort(int *s_arr, int first, int last);
void	ft_error(void);
void	leave_three(t_listc **a, t_listc **b, t_mmm minmaxmed);
void	pa(t_listc **a, t_listc **b, bool print);
void	pb(t_listc **a, t_listc **b, bool print);
void	ra(t_listc **a, bool print);
void	rb(t_listc **b, bool print);
void	rr(t_listc **a, t_listc **b, bool print);
void	rra(t_listc **a, bool print);
void	rrb(t_listc **b, bool print);
void	rrr(t_listc **a, t_listc **b, bool print);
void	sa(t_listc *a, bool print);
void	sb(t_listc *b, bool print);
void	ss(t_listc *a, t_listc *b, bool print);
void	score_rr_rrr(t_listc *b, t_listc **stack_a, t_listc **stack_b, bool p);
void	get_index(t_listc **a, t_mmm m);
void	reset_scores(t_listc *b);
void	score_count_a(t_listc *a, t_listc *b);
void	sort_three(t_listc **a);
void	sort_five(t_listc **a, t_listc **b, t_mmm minmaxmed);
void	score_count(t_listc *stack_a, t_listc *stack_b, int *score);
void	score_process(t_listc **stack_a, t_listc **stack_b, int score);
void	sort_final(t_listc **a, t_mmm minmaxmed);

#endif //PUSH_SWAP_H
