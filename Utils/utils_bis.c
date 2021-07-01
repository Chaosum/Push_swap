/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:00:50 by matthieu          #+#    #+#             */
/*   Updated: 2021/07/01 13:05:48 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	var_init(t_var *var)
{
	var->i = 0;
	var->j = 0;
	var->median = 0;
	var->max = 0;
	var->min = 0;
}

void	ft_lst_stack_add_front(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	*alst = new;
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		ft_putnbr_fd(temp->value, 1);
		write(1, " ", 1);
		temp = temp->next;
	}
	temp = b;
	write(1, "|a b| ", 6);
	while (temp)
	{
		ft_putnbr_fd(temp->value, 1);
		write(1, " ", 1);
		temp = temp->next;
	}
	write(1, "\n", 1);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	if (temp == NULL)
		return (i);
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	check_sort(t_stack *stack, int a_b, int len)
{
	t_stack	*temp;
	t_var	var;

	var_init(&var);
	temp = stack;
	if (ft_stack_size(stack) > 1)
	{
		while (temp->next && var.i < len - 1)
		{
			if (temp->value < temp->next->value)
				var.min++;
			else if (temp->value > temp->next->value)
				var.max++;
			temp = temp->next;
			var.i++;
		}
		if (var.max && a_b == 'a')
			return (1);
		else if (var.min && a_b == 'b')
			return (1);
	}
	return (0);
}
