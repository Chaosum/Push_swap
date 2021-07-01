/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:16:34 by mservage          #+#    #+#             */
/*   Updated: 2021/07/01 12:40:23 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "../push_swap.h"

/* sorting_a.c */

int	sort_three_elem_only_a(t_stack **a, int A, int B, int C);
int	sort_three_elem_a(t_stack **a, t_stack **b);
int	sort_three_elem_a_bis(t_stack **a, t_stack **b);
int	sorting_stack_a(t_stack **a, t_stack **b, t_var var, int len);
int	sorting_stack_a_bis(t_stack **a, t_stack **b, t_var *var, int len);

/* sorting_b.c */

int	sort_three_elem_b_bis(t_stack **a, t_stack **b);
int	sort_three_elem_b(t_stack **a, t_stack **b);
int	sorting_stack_b_bis(t_stack **a, t_stack **b, t_var *var, int len);
int	sorting_stack_b(t_stack **a, t_stack **b, t_var var, int len);

#endif