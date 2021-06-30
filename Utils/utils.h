/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:03:24 by mservage          #+#    #+#             */
/*   Updated: 2021/06/30 15:13:38 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../push_swap.h"

int		free_stacks(t_stack *a, t_stack *b, const char *s);
int		check_sort(t_stack *stack, int a_b, int len);
void	ft_lst_stack_add_front(t_stack **alst, t_stack *new);
int		ft_stack_size(t_stack *stack);
void	var_init(t_var *var);
void	ft_lst_stack_add_back(t_stack **alst, t_stack *new);
int		found_median(t_stack *stack, t_var *var, int len, int a_b);
void	print_stacks(t_stack *a, t_stack *b);
int		check_closest(t_stack *stack, int median, int a_b);

#endif