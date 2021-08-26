/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:03:24 by mservage          #+#    #+#             */
/*   Updated: 2021/07/28 20:18:19 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../push_swap.h"

/* utils_bis_re.c */
void	reverse_the_rotate__on_a(t_var *var, t_stack **a, int i);
void	reverse_the_rotate__on_b(t_var *var, t_stack **b, int i);

/* utils_bis.c */
void	var_init(t_var *var);
void	ft_lst_stack_add_front(t_stack **alst, t_stack *new);
void	print_stacks(t_stack *a, t_stack *b);
int		ft_stack_size(t_stack *stack);
int		check_sort(t_stack *stack, int a_b, int len);

/* utils.c */

int		free_stacks(t_stack *a, t_stack *b, const char *s);
int		check_closest(t_stack *stack, int median, int a_b);
void	ft_lst_stack_add_back(t_stack **alst, t_stack *new);
void	found_median_bis(t_var *var, t_stack **temp2, int *j);
int		found_median(t_stack *stack, t_var *var, int len);

#endif