/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:51:35 by mservage          #+#    #+#             */
/*   Updated: 2021/06/26 04:13:55 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sorting_stack_a(t_stack **a, t_stack **b, t_var var, int len)
{
	t_stack	*temp;

	var_init(&var);
	if (check_sort((*a), 'a', ft_stack_size(*a)) == 0 && *b == NULL)
		return (0);
	if (check_sort((*a), 'a', len) == 1)
	{
		found_median(*a, &var, len);
		while (var.i < len)
		{
			if ((*a)->value < var.median)
				push(a, b, 'a');
			else
				rotate(a, 'a');
			var.i++;
		}
	}
	else if (check_sort(*a, 'a', len) == 1 && len == 2)
		swap(a, 'a');
	else if (check_sort(*a, 'a', len) == 1 && len == 3)
		sort_three_elem_a(a, b, &var, 'a'); /* a opti */
	else if (check_sort(*a, 'a', ft_stack_size(*a)) == 1 && len == 3)
		sort_three_elem_a(a, b, &var, 'a');
	sorting_stack_a(a, b, var, len - ft_stack_size(*a));
	sorting_stack_b(a, b, var, var.i);
	return (0);
}

int	sorting_stack_b(t_stack **a, t_stack **b, t_var var, int len)
{
	int i;

	i = 0;
	var_init(&var);
	if (check_sort(*b, 'b', len) == 0)
	{
		while (i < len)
		{
			push(a, b, 'b');
			i++;
		}
	}
	else if (len == 1)
		push(a, b, 'b');
	else if (check_sort(*b, 'b', len) == 1 && len == 2)
	{
		swap(b, 'b');
		push(a, b, 'b');
		push(a, b, 'b');
	}
	else if (check_sort(*b, 'b', len) == 1 && len > 3)
	{
		found_median(*b, &var, len);
		while (var.i < len)
		{
			if ((*a)->value > var.median)
				push(a, b, 'b');
			else
				rotate(b, 'b');
			var.i++;
		}
	}
	//sorting_stack_a(a, b, var, var.i);
	return (0);
}