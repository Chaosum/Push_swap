/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:17 by mservage          #+#    #+#             */
/*   Updated: 2021/06/22 20:49:50 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	sorting_stack_a(t_stack **a, t_stack **b, t_var *var, int len)
{
	int		size;

	var_init(var);
	if (check_sort((*a), 'a') == 0 && (*b) == NULL)
		return (0);
	size = ft_stack_size(*a);
	found_median(*a, var);
	while (var->i < size)
	{
		if ((*a)->value < var->median)
			push(a, b, 'a');
		else
			rotate(a, 'a');
		var->i++;
	}
	if (check_sort(*a, 'a') == 0)
		return (0);
	else if (check_sort(*a, 'a') == 1 && size < 2)
		swap(a, 'a');
	sorting_stack_a(a, b, var, var->i);
	sorting_stack_b(a, b, var, var->i);
	return (0);
}

int	sorting_stack_b(t_stack **a, t_stack **b, t_var *var, int len)
{
	return (0);
}
