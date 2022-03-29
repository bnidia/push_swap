/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 06:08:59 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void		ft_error(void);
static void	parse_string(t_listc **stack, char *str);
static void	check_valid_parameters(char *s);

t_listc	*init_stack(int argc, char *argv[])
{
	t_listc	*stack;

	stack = NULL;
	if (argc == 1)
		exit (0);
	argv++;
	argc--;
	while (argc--)
		parse_string(&stack, *(argv++));
	return (stack->next);
}

/* parse_string
 * this function can process "3 5" and 7 1 2 values
 * */
void	parse_string(t_listc **stack, char *str)
{
	int		i;
	char	*saved_position;
	char	*s;
	t_listc	*new;

	i = 0;
	saved_position = str;
	check_valid_parameters(str);
	s = ft_strtrim(str, " ");
	while (s[i])
	{
		while (s[i] == ' ')
			saved_position = &s[i++];
		new = ft_lstc_new(ft_atoi(saved_position));
		if (ft_atoi(saved_position) == 0 && s[i++] != '0')
			ft_error();
		while (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-')
			i++;
		if (*stack == NULL)
			*stack = new;
		else
			ft_lstc_add(*stack, new);
		*stack = (*stack)->next;
	}
	free(s);
}

/* check_valid_parameters
 * check incoming strings
 * wrong strings - "" abc 0abc 0- 0+ ++0 --0 +-0
 * 1) if not + - space or digit - error
 * 2) if + or - and then not digit - error
 * 3) if digit and then - or + - error
 * sorted or duplicated values check in another function
 * */
static void	check_valid_parameters(char *s)
{
	int		i;
	char	*spaces;

	i = 0;
	while (s[i])
	{
		if (s[i] != '-' && s[i] != '+' && s[i] != ' ' && !ft_isdigit(s[i]))
			ft_error();
		if ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			ft_error();
		if (ft_isdigit(s[i]) && (s[i + 1] == '-' || s[i + 1] == '+'))
			ft_error();
		i++;
	}
	spaces = ft_strtrim(s, " ");
	if (*spaces == '\0')
		ft_error();
	free(spaces);
}

void	ft_error(void)
{
	if (write(1, "Error\n", 6))
		exit(EXIT_SUCCESS);
}
