/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 15:31:46 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_lstc.h"

void	del(void *s);

int	main(void)
{
	t_listc	*a;
	t_listc	*b;
	t_listc	*c;
	t_listc	*d;
	t_listc	*e;
	int	z = 2, x = 0, n = -5, m = 8, k = 1564;

	a = ft_lstc_new(&z);
	b = ft_lstc_new(&x);
	c = ft_lstc_new(&n);
	d = ft_lstc_new(&m);
	e = ft_lstc_new(&k);
	ft_lstc_add(a, b);
	ft_lstc_add(a, c);
	ft_lstc_add(a, d);
	ft_lstc_add(a, e);
	printf("%d\n", ft_lstc_size(a));
	ft_lstc_del_one(&b, &del);
	printf("%d\n", ft_lstc_size(a));
	printf("%p\n", b);
	ft_lstc_clear(&a, &del);
	printf("%d\n", ft_lstc_size(a));
}

void	del(void *s)
{
	if (s == NULL)
		return ;
	return ;
}
