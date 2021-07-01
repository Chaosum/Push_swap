/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:03:03 by mservage          #+#    #+#             */
/*   Updated: 2021/07/01 13:26:38 by matthieu         ###   ########.fr       */
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

void	found_median_bis(t_var *var, t_stack **temp2, int *j)
{
	if (var->median <= (*temp2)->value)
		var->min++;
	if (var->median >= (*temp2)->value)
		var->max++;
	*temp2 = (*temp2)->next;
	*j = *j + 1;
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
			found_median_bis(var, &temp2, &j);
		if (var->min == var->max || (var->min + 1 == var->max && !(len % 2))
			|| (var->min == var->max + 1 && !(len % 2)))
			return (var->median);
		var->min = 0;
		var->max = 0;
		temp = temp->next;
		i++;
	}
	return (0);
}
