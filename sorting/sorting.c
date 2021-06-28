/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:17 by mservage          #+#    #+#             */
/*   Updated: 2021/06/28 17:33:21 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	sort_three_elem_only_a(t_stack **a)
{
	int	A;
	int	B;
	int	C;

	A = (*a)->value;
	B = (*a)->next->value;
	C = (*a)->next->next->value;
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
	{
		swap(a, 'a');
	}
	else if (A < B && A > C && B > C)
	{
		r_rotate(a, 'a');
	}
	else if (A > B && A > C && C > B)
	{
		r_rotate(a, 'a');
		r_rotate(a, 'a');
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
	else if (A > B && A < C && B < C)
	{
		push(a, b, 'b');
		swap(b, 'b');
		push(a, b, 'a');
		swap(b, 'b');
	}
	else if (A < B && A > C && B > C)
	{
		swap(b, 'b');
	}
	else if (A > B && A > C && C > B)
	{
		push(a, b, 'b');
		swap(b, 'b');
		push(a, b, 'a');
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
	else if (A > B && A < C && B < C)
	{
		swap(a, 'a');
	}
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

int	sorting_stack_a(t_stack **a, t_stack **b, t_var var, int len)
{
	var_init(&var);
	if ((check_sort(*a, 'a', ft_stack_size(*a)) == 0 && *b == NULL) || len == 0)
		return (0);
	else if (len == 1)
		return (0);
	else if (len == 2)
	{
		if (check_sort(*a, 'a', len) == 1)
			swap(a, 'a');
		return (0);
	}
	else if (len == 3)
	{
		if (check_sort(*a, 'a', len) == 1)
			sort_three_elem_a(a, b);
		return (0);
	}
	else if (len > 3 && check_sort(*a, 'a', len) == 1)
	{
		found_median(*a, &var, len);
		var.min = 0;
		while (var.i < len)
		{
			if ((*a)->value < var.median)
			{
				push(a, b, 'a');
				var.j++;
			}
			else if (check_next(a, var.median) == 1)
			{
				rotate(a, 'a');
				var.min++;
			}
			var.i++;
		}
		while (var.min > 0 && var.b == 1)
		{
			r_rotate(a, 'a');
			var.min--;
		}
	}
	else if (check_sort(*a, 'a', len) == 0 && *b)
		return (0);
	sorting_stack_a(a, b, var, len - var.j);
	sorting_stack_b(a, b, var, var.j);
	return (0);
}

int	sorting_stack_b(t_stack **a, t_stack **b, t_var var, int len)
{
	var_init(&var);
	if (*b == NULL)
		return (0);
	else if (check_sort(*b, 'b', len) == 0)
	{
		while (var.i < len)
		{
			push(a, b, 'b');
			var.i++;
		}
		return (0);
	}
	else if (len == 2)
	{
		swap(b, 'b');
		push(a, b, 'b');
		push(a, b, 'b');
		return (0);
	}
	else if (len == 3)
	{
		sort_three_elem_b(a, b);
		push(a, b, 'b');
		push(a, b, 'b');
		push(a, b, 'b');
		return (0);
	}
	else if (len > 3)
	{
		found_median(*b, &var, len);
		var.max = 0;
		while (var.i < len)
		{
			if ((*b)->value > var.median)
			{
				push(a, b, 'b');
				var.j++;
			}
			else
			{
				rotate(b, 'b');
				var.max++;
			}
			var.i++;
		}
		while (var.max > 0)
		{
			r_rotate(b, 'b');
			var.max--;
		}
	}
	var.b = 1;
	sorting_stack_a(a, b, var, var.j);
	sorting_stack_b(a, b, var, len - var.j);
	return (0);
}
