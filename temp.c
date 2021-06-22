/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:51:35 by mservage          #+#    #+#             */
/*   Updated: 2021/06/22 16:23:04 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sort_block(t_stack **a, t_stack **b, t_stack **stack_size, t_var **var)
{
	t_stack	*temp;

	if ((*stack_size) == NULL)
	{
		while (*b)
			push(a, b, 'b');
		return (0);
	}
	if ((*stack_size)->value == 1)
	{
		push(a, b, 'b');
		temp = *stack_size;
		*stack_size = (*stack_size)->next;
		free(temp);
		sort_block(a, b, stack_size, var);
	}
	else if ((*stack_size)->value == 2)
	{
		push(a, b, 'b');
		push(a, b, 'b');
		if (check_sort(*a, 'a') == 1)
			swap(a, 'a');
		temp = (*stack_size);
		*stack_size = (*stack_size)->next;
		free(temp);
		sort_block(a, b, stack_size, var);
	}
	else
	{
		temp = (*stack_size);
		*stack_size = (*stack_size)->next;
		free(temp);
		sort_block(a, b, stack_size, var);
	}
	return (0);
}

int	sorting_start(t_stack *a, t_stack *b, t_var *var)
{
	int		size;
	t_stack	*stack_size;

	stack_size = NULL;
	if (check_sort(a, 'a') == 0)
		return (0);
	while (ft_stack_size(a) > 2)
	{
		ft_lst_stack_add_front(&stack_size, ft_calloc(1, sizeof(t_stack)));
		var->i = 0;
		found_median(a, var);
		size = ft_stack_size(a);
		while (var->i < size)
		{
			if (a->value < var->median)
			{
				push(&a, &b, 'a');
				stack_size->value++;
			}
			else
				rotate(&a, 'a');
			var->i++;
		}
	}
	if (check_sort(a, 'a') == 1)
		swap(&a, 'a');
	sort_block(&a, &b, &stack_size, &var);
	if (check_sort(a, 'a') == 1)
		printf("c pa bon mais isoke\n");
	while (a)
	{
		printf("%d|", a->value);
		a = a->next;
	}
	printf("\n");
	while (b)
	{
		printf("%d|", b->value);
		b = b->next;
	}
	return (0);
}