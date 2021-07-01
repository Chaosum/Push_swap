/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:08:11 by matthieu          #+#    #+#             */
/*   Updated: 2021/07/01 12:45:47 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	sort_three_elem_only_a(t_stack **a, int A, int B, int C)
{
	if (A > B && B > C)
	{
		rotate(a, 'a');
		swap(a, 'a');
	}
	else if (A < B && A < C && B > C)
	{
		rotate(a, 'a');
		swap(a, 'a');
		r_rotate(a, 'a');
	}
	else if (A > B && A < C && B < C)
		swap(a, 'a');
	else if (A < B && A > C && B > C)
		r_rotate(a, 'a');
	else if (A > B && A > C && C > B)
	{
		r_rotate(a, 'a');
		r_rotate(a, 'a');
	}
	return (0);
}

int	sort_three_elem_a_bis(t_stack **a, t_stack **b)
{
	int	A;
	int	B;
	int	C;

	A = (*a)->value;
	B = (*a)->next->value;
	C = (*a)->next->next->value;
	if (A > B && A < C && B < C)
		swap(a, 'a');
	else if (A < B && A > C && B > C)
	{
		push(a, b, 'a');
		swap(a, 'a');
		push(a, b, 'b');
		swap(a, 'a');
	}
	else if (A > B && A > C && C > B)
	{
		swap(a, 'a');
		push(a, b, 'a');
		swap(a, 'a');
		push(a, b, 'b');
	}
	return (0);
}

int	sort_three_elem_a(t_stack **a, t_stack **b)
{
	int	A;
	int	B;
	int	C;

	A = (*a)->value;
	B = (*a)->next->value;
	C = (*a)->next->next->value;
	if (A > B && B > C)
	{
		swap(a, 'a');
		push(a, b, 'a');
		swap(a, 'a');
		push(a, b, 'b');
		swap(a, 'a');
	}
	else if (A < B && A < C && B > C)
	{
		push(a, b, 'a');
		swap(a, 'a');
		push(a, b, 'b');
	}
	return (sort_three_elem_a_bis(a, b));
}

int	sorting_stack_a_bis(t_stack **a, t_stack **b, t_var *var, int len)
{
	found_median(*a, var, len, 'a');
	var->min = 0;
	while (var->i < len && var->j <= (len / 2) - 1)
	{
		if ((*a)->value < var->median)
		{
			push(a, b, 'a');
			var->j++;
		}
		else if (check_closest(*a, var->median, 'a') == 1 && var->b == 0)
			r_rotate(a, 'a');
		else
		{
			rotate(a, 'a');
			var->min++;
		}
		var->i++;
	}
	while (var->min > 0 && var->b == 1)
	{
		r_rotate(a, 'a');
		var->min--;
	}
}

int	sorting_stack_a(t_stack **a, t_stack **b, t_var var, int len)
{
	var_init(&var);
	if ((check_sort(*a, 'a', ft_stack_size(*a)) == 0 && *b == NULL) || len == 0)
		return (0);
	else if (len == 1 || check_sort(*a, 'a', len) == 0 && *b)
		return (0);
	else if (len == 2)
	{
		if (check_sort(*a, 'a', len) == 1)
			swap(a, 'a');
		return (0);
	}
	else if (len == 3 && ft_stack_size(*a) == 3)
		return (sort_three_elem_only_a(a, (*a)->value,
				(*a)->next->value, (*a)->next->next->value));
	else if (len == 3)
	{
		if (check_sort(*a, 'a', len) == 1)
			sort_three_elem_a(a, b);
		return (0);
	}
	else if (len > 3 && check_sort(*a, 'a', len) == 1)
		sorting_stack_a_bis(a, b, &var, len);
	sorting_stack_a(a, b, var, len - var.j);
	sorting_stack_b(a, b, var, var.j);
	return (0);
}
