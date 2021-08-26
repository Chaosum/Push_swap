/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis_re.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:10:10 by mservage          #+#    #+#             */
/*   Updated: 2021/07/30 16:27:53 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	reverse_the_rotate__on_a(t_var *var, t_stack **a, int i)
{
	if (var->min >= ft_stack_size(*a) / 2)
	{
		while (++i < ft_stack_size(*a) - var->min)
			rotate(a, 'a');
	}
	else
	{
		while (var->min > 0 && var->b == 1)
		{
			r_rotate(a, 'a');
			var->min--;
		}
	}
}

void	reverse_the_rotate__on_b(t_var *var, t_stack **b, int i)
{
	if (var->max >= ft_stack_size(*b) / 2)
	{
		while (++i < ft_stack_size(*b) - var->max)
			rotate(b, 'b');
	}
	else
	{
		while (var->max > 0)
		{
			r_rotate(b, 'b');
			var->max--;
		}
	}
}
