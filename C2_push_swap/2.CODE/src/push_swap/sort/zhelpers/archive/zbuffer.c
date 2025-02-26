/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/24 11:57:43 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_node_finder(t_list_dls **stack, t_list_program *list_program);
int	node_pos_locator(int value, t_list_program *list_program, char type, \
		char stack_origin);

void	merge_back_size0_gear(t_list_program *list_program)
{
	int	max_node;

	max_node = max_node_finder(list_program->stack_b, list_program);
	while ((*list_program->stack_b)->index != max_node)
		rotate("r", 'b', list_program);
	while (ft_lstsize(*list_program->stack_b))
		push('a', list_program);
}

void	merge_back_to_a_gear(t_list_program *list_program)
{
	t_list_dls	**stack_a;
	t_list_dls	**stack_b;
	int			rotations_a;
	int			rotations_a_abs;

	stack_a = list_program->stack_a;
	stack_b = list_program->stack_b;
	rotations_a = node_pos_locator((*stack_b)->index, list_program, 'd', 'b');
	rotations_a_abs = ft_abs(rotations_a);
	while (rotations_a_abs-- > 1)
	{
		if (rotations_a > 0)
			rotate("r", 'a', list_program);
		else
			rotate("rr", 'a', list_program);
	}
	while ((*stack_a)->prev->index < (*stack_b)->index)
		push('a', list_program);
	if (ft_lstsize(*stack_b) > 0)
		merge_back_to_a_gear(list_program);
}

int	max_node_finder(t_list_dls **stack, t_list_program *list_program)
{
	int			max_node;
	int			rotations;
	t_list_dls	*current;

	rotations = 0;
	max_node = (*stack)->index;
	current = *stack;
	while (rotations < ft_lstsize(*stack))
	{
		if (current->index > max_node)
			max_node = current->index;
		current = current->next;
		rotations++;
	}
	return (max_node);
}


int	node_pos_locator(int value, t_list_program *list_program, char type, \
		char stack_origin)
{
	t_node_pos_locator	v;

	v.stack_b = list_program->stack_b;
	if (stack_origin == 'b')
		v.stack_b = list_program->stack_a;
	v.size = ft_lstsize(*v.stack_b);
	v.current = *v.stack_b;
	v.pos = 0;
	v.max_node = max_node_finder(v.stack_b, list_program);
	while (v.pos < v.size)
	{
		if ((v.current->index == v.max_node && value > v.current->index) || \
			(v.current->index == v.max_node && value < v.current->prev->index) \
			|| (value < v.current->prev->index && value > v.current->index))
			break ;
		v.current = v.current->next;
		v.pos++;
	}
	if (type == 'd' && (v.size - v.pos) < v.pos)
		v.pos = v.pos - v.size ;
	return (v.pos);
}

void	sort_move_lower_cost(char stack_origin, t_move_lower_cost *v, \
			t_list_program *list_program)
{
	v->current = *list_program->stack_a;
	if (stack_origin == 'b')
		v->current = *list_program->stack_b;
	v->current_rotations = -2;
	v->current = v->current->prev->prev;
	v->price_of_cheapest = 10;
	while (v->current_rotations <= 2)
	{
		v->rotations_b = node_pos_locator(v->current->index, list_program, \
			'd', stack_origin);
		v->current_price = ft_abs(v->current_rotations) + \
			ft_abs(v->rotations_b);
		if (v->current_price < v->price_of_cheapest)
		{
			v->price_of_cheapest = v->current_price;
			v->moves_to_cheapest = v->current_rotations;
			v->rotations_b_cheapest = v->rotations_b;
			v->value_of_cheapest = v->current->index;
		}
		v->current = v->current->next;
		v->current_rotations++;
	}
	v->moves_to_cheapest_abs = ft_abs(v->moves_to_cheapest);
	v->rotations_b_abs = ft_abs(v->rotations_b_cheapest);
}


void	sort_gearing(char stack_origin, t_list_program *list_program)
{
	t_sort_gearing		v;
	t_move_lower_cost	v1;

	if (ft_lstsize(*list_program->stack_a) == 0)
	{
//		sort_3(list_program->stack_a, list_program);
//		sort_gearing('b', list_program);
//		merge_back_to_a_gear(list_program);
		merge_back_size0_gear(list_program);	if (ft_lstsize(*list_program->stack_a) == 0)
	{
//		sort_3(list_program->stack_a, list_program);
//		sort_gearing('b', list_program);
//		merge_back_to_a_gear(list_program);
		return ;
	}
	sort_move_lower_cost(stack_origin, &v1, list_program);
	v.rotations_a = v1.moves_to_cheapest;
	v.rotations_a_abs = v1.moves_to_cheapest_abs;
	while (v.rotations_a_abs > 0 || v1.rotations_b_abs > 0)
	{
		if (v.rotations_a > 0 && v.rotations_a_abs > 0)
			rotate("r", 'a', list_program);
		if (v.rotations_a < 0 && v.rotations_a_abs > 0)
			rotate("rr", 'a', list_program);
		if (v1.rotations_b_cheapest < 0 && v1.rotations_b_abs > 0)
			rotate("rr", 'b', list_program);
		if (v1.rotations_b_cheapest > 0 && v1.rotations_b_abs > 0)
			rotate("r", 'b', list_program);
		v.rotations_a_abs--;
		v1.rotations_b_abs--;
	}
	push('b', list_program);
	sort_gearing('a', list_program);
}

void	gear_sort_pushswap(t_list_program *list_program)
{
	ft_printers(GEAR, list_program);
	push('b', list_program);
	push('b', list_program);
	sort_gearing('a', list_program);
}
