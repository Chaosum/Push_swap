/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:17 by mservage          #+#    #+#             */
/*   Updated: 2021/07/01 13:56:20 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	sort_three_elem_b_bis(t_stack **a, t_stack **b)
{
	int	A;
	int	B;
	int	C;

	A = (*b)->value;
	B = (*b)->next->value;
	C = (*b)->next->next->value;
	if (A > B && A < C && B < C)
	{
		push(a, b, 'b');
		swap(b, 'b');
		push(a, b, 'a');
		swap(b, 'b');
	}
	else if (A < B && A > C && B > C)
		swap(b, 'b');
	else if (A > B && A > C && C > B)
	{
		push(a, b, 'b');
		swap(b, 'b');
		push(a, b, 'a');
	}
	return (0);
}

int	sort_three_elem_b(t_stack **a, t_stack **b)
{
	int	A;
	int	B;
	int	C;

	A = (*b)->value;
	B = (*b)->next->value;
	C = (*b)->next->next->value;
	if (A < B && B < C)
	{
		swap(b, 'b');
		push(a, b, 'b');
		swap(b, 'b');
		push(a, b, 'a');
		swap(b, 'b');
	}
	else if (A < B && A < C && B > C)
	{
		swap(b, 'b');
		push(a, b, 'b');
		swap(b, 'b');
		push(a, b, 'a');
	}
	return (sort_three_elem_b_bis(a, b));
}

int	sorting_stack_b_bis(t_stack **a, t_stack **b, t_var *var, int len)
{
	found_median(*b, var, len);
	var->max = 0;
	while (var->i < len && var->j <= (len / 2) - 1)
	{
		if ((*b)->value > var->median)
		{
			push(a, b, 'b');
			var->j++;
		}
		else
		{
			rotate(b, 'b');
			var->max++;
		}
		var->i++;
	}
	while (var->max > 0)
	{
		r_rotate(b, 'b');
		var->max--;
	}
	return (0);
}

int	sorting_stack_b(t_stack **a, t_stack **b, t_var var, int len)
{
	var_init(&var);
	if (*b == NULL)
		return (0);
	else if (len == 2 && check_sort(*b, 'b', len) == 1)
		swap(b, 'b');
	else if (len == 3 && check_sort(*b, 'b', len) == 1)
		sort_three_elem_b(a, b);
	if (check_sort(*b, 'b', len) == 0)
	{
		while (var.i < len)
		{
			push(a, b, 'b');
			var.i++;
		}
		return (0);
	}
	else if (len > 3)
		sorting_stack_b_bis(a, b, &var, len);
	var.b = 1;
	sorting_stack_a(a, b, var, var.j);
	sorting_stack_b(a, b, var, len - var.j);
	return (0);
}
