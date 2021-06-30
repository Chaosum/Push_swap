/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:03:03 by mservage          #+#    #+#             */
/*   Updated: 2021/06/30 15:19:25 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_stacks(t_stack *a, t_stack *b, const char *s)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	while (b)
	{
		temp = b;
		b = b->next;
		free(temp);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (0);
}

int	check_closest(t_stack *stack, int median, int a_b)
{
	t_stack	*temp;
	int		size;
	int		next;

	temp = stack;
	size = ft_stack_size(stack);
	next = 0;
	while (temp)
	{
		if (temp->value < median && a_b == 'a')
			break ;
		if (temp->value >= median && a_b == 'b')
			break ;
		next++;
		temp = temp->next;
	}
	if ((next * 2) - 1 > size)
		return (1);
	return (0);
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

void	ft_lst_stack_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*temp;

	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp)
	{
		if (temp->next == 0)
		{
			temp->next = new;
			return ;
		}
		temp = temp->next;
	}
	return ;
}

int	found_median(t_stack *stack, t_var *var, int len, int a_b)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		i;
	int		j;

	i = 0;
	temp = stack;
	while (i < len)
	{
		j = 0;
		var->median = temp->value;
		temp2 = stack;
		while (j < len)
		{
			if (var->median <= temp2->value)
				var->min++;
			if (var->median >= temp2->value)
				var->max++;
			temp2 = temp2->next;
			j++;
		}
		if (var->min == var->max
			|| (var->min + 1 == var->max && !(len % 2))
			|| (var->min == var->max + 1 && !(len % 2)))
			return (var->median);
		var->min = 0;
		var->max = 0;
		temp = temp->next;
		i++;
	}
	return (-1);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	temp = b;
	printf("|a b| ");
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
