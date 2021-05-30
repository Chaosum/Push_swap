/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:10:29 by mservage          #+#    #+#             */
/*   Updated: 2021/05/26 08:17:23 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_a(int ac, char **av)
{
	int i;
	t_stack *stack_a;
	i = 0;

	while (i <= ac)
	{
		stack_a = ft_calloc(1, sizeof(t_stack));
		stack_a->value = ft_atoi(av[i]);
		if (stack_a->value <= 0)
		{
			/* error */
			return (NULL);
		}
		stack_a = stack_a->next;
		i++;
	}
	return (stack_a);
}

int	check_doublon(t_stack *stack_a, int ac)
{
	int i;
	int current_check;
	int value;

	current_check = 0;
	while (current_check < ac)
	{
		i = 0;
		value = stack_a->value;
		while (i < ac)
		{
			if (value == stack_a->value && i != current_check)
			{
				/* error */
				return (0);
			}
			i++;
		}
		stack_a = stack_a->next;
		current_check++;
	}
	return (1);
}

int	check_arg_num(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit((int)av[i][j]))
			{
				/* error */
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int main (int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (ac < 2)
	{
		/* error */
		return (0);
	}
	if (!check_arg_num(ac, av))
		return (0);
	stack_a = init_stack_a(ac, av);
	if (stack_a == NULL)
	{
		/* error */
		return (0);
	}
	if (!check_doublon(stack_a, ac))
	{
		free(stack_a);
		return (0);
	}
}