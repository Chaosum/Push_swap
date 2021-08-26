/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:10:29 by mservage          #+#    #+#             */
/*   Updated: 2021/08/25 18:37:18 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_a(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*temp;

	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		temp = ft_calloc(1, sizeof(t_stack));
		if (temp == NULL)
		{
			free_stacks(stack_a, NULL, "Error\nMalloc error.");
			return (NULL);
		}
		temp->value = ft_atoi(av[i]);
		if (temp->value == -1 && ft_strncmp(av[i], "-1", 3))
		{
			free(temp);
			free_stacks(stack_a, NULL, "Error\nWrong arg value.");
			return (NULL);
		}
		ft_lst_stack_add_back(&stack_a, temp);
		i++;
	}
	return (stack_a);
}

int	check_doublon(t_stack *stack_a, int ac)
{
	int		i;
	int		current_check;
	int		value;
	t_stack	*temp;
	t_stack	*temp2;

	temp2 = stack_a;
	current_check = 1;
	while (current_check < ac)
	{
		temp = stack_a;
		i = 1;
		value = temp2->value;
		while (i < ac)
		{
			if (value == temp->value && i != current_check)
				return (0);
			temp = temp->next;
			i++;
		}
		temp2 = temp2->next;
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
		if (av[i][0] == 0)
			return (0);
		if (av[i][j] == '-' && ft_strncmp(av[i], "-", 2))
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit((int)av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_var	var;

	var_init(&var);
	var.b = 0;
	if (ac < 2)
		return (0);
	if (!check_arg_num(ac, av))
		return (free_stacks(NULL, NULL, "Error\nWrong args."));
	stack_a = init_stack_a(ac, av);
	stack_b = NULL;
	if (stack_a == NULL)
		return (1);
	if (!check_doublon(stack_a, ac))
		return (free_stacks(stack_a, stack_b, "Error\nDuplicated values."));
	if (ft_stack_size(stack_a) == 3)
		sort_three_elem_only_a(&stack_a, stack_a->value,
			stack_a->next->value, stack_a->next->next->value);
	else
		sorting_stack_a(&stack_a, &stack_b, var, ft_stack_size(stack_a));
	free_stacks(stack_a, stack_b, "");
	return (0);
}
