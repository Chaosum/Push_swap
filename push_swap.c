/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:10:29 by mservage          #+#    #+#             */
/*   Updated: 2021/06/21 16:27:56 by mservage         ###   ########.fr       */
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
		temp->value = ft_atoi(av[i]);
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
			{
				printf("/* error */ 2\n");
				return (0);
			}
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
		while (av[i][j])
		{
			if (!ft_isdigit((int)av[i][j]) && av[i][j] != '-')
			{
				printf("/* error */ 3\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main (int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_var	var;

	var_init(&var);
	if (ac < 2)
	{
		printf("error 4\n");
		return (0);
	}
	if (!check_arg_num(ac, av))
		return (0);
	stack_a = init_stack_a(ac, av);
	stack_b = NULL;
	if (stack_a == NULL)
	{
		printf("error 5\n");
		return (0);
	}
	if (!check_doublon(stack_a, ac))
	{
		free(stack_a);
		return (0);
	}
	sorting_start(stack_a, stack_b, &var);
}
