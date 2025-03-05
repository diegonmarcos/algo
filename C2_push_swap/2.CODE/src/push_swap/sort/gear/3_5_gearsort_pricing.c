/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_gearsort_pricing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/05 12:49:28 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gear_sort_pushswap(t_list_program *list_program)
{
	ft_printers(GEAR, list_program);
	if (ft_lstsize(*list_program->stack_a) > 100)
		quick_sort_partial(list_program);
	push('b', list_program);
	push('b', list_program);
	if (list_program->stack_a_size >= 500)
		sort_gearing('a', 'b', 75, list_program);
	else if (list_program->stack_a_size >= 100)
		sort_gearing('a', 'b', 25, list_program);
	else
		sort_gearing('a', 'b', 5, list_program);
}

void	sort_gearing(char stack_from, char stack_to, int base_case, \
			t_list_program *list_program)
{
	t_sort_gearing		v;
	t_move_lower_cost	v1;
	int					count;

	if (sort_gearing_is_base_case(base_case, list_program))
		return ;
	sort_move_lower_cost(stack_from, &v1, list_program);
	v.rotations_a = v1.moves_to_cheapest;
	v.rotations_a_abs = v1.moves_to_cheapest_abs;
	while (v.rotations_a_abs > 0 || v1.rotations_b_abs > 0)
	{
		if (v.rotations_a > 0 && v.rotations_a_abs > 0)
			rotate("r", stack_from, list_program);
		if (v.rotations_a < 0 && v.rotations_a_abs > 0)
			rotate("rr", stack_from, list_program);
		if (v1.rotations_b_cheapest < 0 && v1.rotations_b_abs > 0)
			rotate("rr", stack_to, list_program);
		if (v1.rotations_b_cheapest > 0 && v1.rotations_b_abs > 0)
			rotate("r", stack_to, list_program);
		v.rotations_a_abs--;
		v1.rotations_b_abs--;
	}
	push(stack_to, list_program);
	sort_gearing(stack_from, stack_to, base_case, list_program);
}

void	sort_move_lower_cost(char stack_from, t_move_lower_cost *v, \
			t_list_program *list_program)
{
	v->current = *list_program->stack_a;
	if (stack_from == 'b')
		v->current = *list_program->stack_b;
	v->current_rotations = -5;
	v->current = v->current->prev->prev->prev->prev->prev;
	v->price_of_cheapest = 500;
	while (v->current_rotations <= 5)
	{
		v->rotations_b = node_pos_locator(v->current->index, list_program, \
			'd', stack_from);
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
	ft_printers_gearsort(PRICES, v, list_program);
}

int	node_pos_locator(int value, t_list_program *list_program, char type, \
		char stack_from)
{
	t_node_pos_locator	v;

	v.stack_b = list_program->stack_b;
	if (stack_from == 'b')
		v.stack_b = list_program->stack_a;
	v.size = ft_lstsize(*v.stack_b);
	v.current = *v.stack_b;
	v.pos = 0;
	v.max_node = max_node_finder(v.stack_b, list_program);
	while (v.pos < v.size)
	{
		if (node_pos_locator_is_in_place(stack_from, value, &v))
			break ;
		v.current = v.current->next;
		v.pos++;
	}
	if (type == 'd' && (v.size - v.pos) < v.pos)
		v.pos = v.pos - v.size ;
	return (v.pos);
}

int	sort_gearing_is_base_case(int base_case, t_list_program *list_program)
{
	if (base_case == 25 && ft_lstsize(*list_program->stack_a) == base_case)
	{
		selection_sort(list_program);
		ft_printers(GEAR, list_program);
		sort_gearing('b', 'a', 0, list_program);
		low_up_stack(list_program);
		return (1);
	}
	else if (base_case == 75 && ft_lstsize(*list_program->stack_a) == base_case)
	{
		selection_sort(list_program);
		ft_printers(GEAR, list_program);
		sort_gearing('b', 'a', 0, list_program);
		low_up_stack(list_program);
		return (1);
	}
	else if (base_case == 0 && ft_lstsize(*list_program->stack_b) == base_case)
		return (1);
	return (0);
}
