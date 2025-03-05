/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_gearsort_pricing2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/05 12:48:55 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_pos_locator_is_in_place(char stack_from, int value, \
		t_node_pos_locator *v)
{
	if (stack_from == 'a' \
		&& ((v->current->index == v->max_node && value > v->current->index) \
		|| (v->current->index == v->max_node && value < v->current->index \
		&& value < v->current->prev->index) \
		|| (value > v->current->index && value < v->current->prev->index)))
		return (1);
	if (stack_from == 'b' \
		&& ((v->current->prev->index == v->max_node \
		&& value < v->current->index) \
		|| (v->current->prev->index == v->max_node \
		&& value > v->current->prev->index) \
		|| (value < v->current->index && value > v->current->prev->index)))
		return (1);
	return (0);
}

void	high_up_stack(t_list_program *list_program)
{
	int			max_node;
	int			node_pos;
	int			node_pos_abs;
	t_list_dls	**stack;

	stack = list_program->stack_b;
	if (!*stack)
		return ;
	max_node = max_node_finder(stack, list_program);
	node_pos = node_pos_locator(max_node + 1, list_program, 'd', 'a');
	node_pos_abs = ft_abs(node_pos);
	while (node_pos_abs-- > 0)
	{
		if (node_pos > 0)
			rotate("r", 'a', list_program);
		else
			rotate("rr", 'a', list_program);
	}
}

void	low_up_stack(t_list_program *list_program)
{
	int			max_node;
	t_list_dls	**stack;

	stack = list_program->stack_a;
	max_node = max_node_finder(stack, list_program);
	while ((*stack)->prev->index != max_node)
	{
		if ((*stack)->index < list_program->stack_a_size / 2)
			rotate("rr", 'a', list_program);
		else
			rotate("r", 'a', list_program);
	}
}
