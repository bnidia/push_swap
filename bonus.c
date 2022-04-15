/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/04/11 17:23:43 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_operation(t_listc **a, t_listc **b, char *str);
static void	parse_operation2(t_listc **a, t_listc **b, char *str);
static void	print_result(t_listc **a, t_listc **b);

/* This is bonus function - checker */
int	main(int argc, char *argv[])
{
	t_listc	*a;
	t_listc	*b;
	t_mmm	minmaxmed;
	char	*str;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	a = init_stack(argc, argv);
	check_if_duplicated(&a, &minmaxmed);
	str = get_next_line(0);
	while (str)
	{
		parse_operation(&a, &b, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	print_result(&a, &b);
	if (a != NULL)
		ft_lstc_clear(&a);
	if (b != NULL)
		ft_lstc_clear(&b);
	return (0);
}

static void	print_result(t_listc **a, t_listc **b)
{
	if (check_if_sorted(a) && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	parse_operation(t_listc **a, t_listc **b, char *str)
{
	size_t	strlen;

	strlen = ft_strlen((const char *)str);
	if (!ft_strncmp(str, "sa\n", strlen))
		sa(*a, false);
	else if (!ft_strncmp(str, "sb\n", strlen) && b != NULL)
		sb(*b, false);
	else if (!ft_strncmp(str, "ss\n", strlen))
		ss(*a, *b, false);
	else if (!ft_strncmp(str, "pa\n", strlen))
		pa(a, b, false);
	else if (!ft_strncmp(str, "pb\n", strlen))
		pb(a, b, false);
	else
		parse_operation2(a, b, str);
}

static void	parse_operation2(t_listc **a, t_listc **b, char *str)
{
	size_t	strlen;

	strlen = ft_strlen((const char *)str);
	if (!ft_strncmp(str, "ra\n", strlen))
		ra(a, false);
	else if (!ft_strncmp(str, "rb\n", strlen) && b != NULL)
		rb(b, false);
	else if (!ft_strncmp(str, "rr\n", strlen))
		rr(a, b, false);
	else if (!ft_strncmp(str, "rra\n", strlen))
		rra(a, false);
	else if (!ft_strncmp(str, "rrb\n", strlen) && b != NULL)
		rrb(b, false);
	else if (!ft_strncmp(str, "rrr\n", strlen))
		rrr(a, b, false);
	else
		ft_error();
}
