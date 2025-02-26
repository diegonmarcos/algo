/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.5.Gearsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/23 17:09:35 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_node_pos(t_list_program *list_program)
{
	t_list_dls	**stack_a;
	int			max_node;
	int			rotations;
	t_list_dls	*current;

	rotations = 0;
	stack_a = list_program->stack_a;
	max_node = (*stack_a)->index;
	current = *stack_a;
	while (rotations < ft_lstsize(*stack_a))
	{
		if (current->index > max_node)
			max_node = current->index;
		current = current->next;
		rotations++;
	}
	return (max_node);
}


int	node_pos_locator(int value, t_list_program *list_program)
{
	int			pos;
	t_list_dls	**stack_a;
	int			max_node;
	t_list_dls	*current;

	pos = 0;
	stack_a = list_program->stack_a;
	max_node = max_node_pos(list_program);
	current = *stack_a;
	while (pos < ft_lstsize(*stack_a))
	{
		if ((value < current->index && value > current->prev->index) \
			|| (value < current->index \
			&& current->prev->index == max_node))
			break ;
		current = current->next;
		pos++;
	}
	return (pos);
}

void	merge_back_to_a_gear_step(t_list_program *list_program)
{
	int			value;
	int			pos;
	int			size;
	t_list_dls	**stack_b;

	stack_b = list_program->stack_b;
	if (!ft_lstsize(*stack_b))
		return ;
	if ((*stack_b)->index < (*stack_b)->prev->index)
		rotate("rr", 'b', list_program);
	value = (*stack_b)->index;
	size = ft_lstsize(*(list_program->stack_a));
	pos = node_pos_locator(value, list_program);
	if (pos < size / 2)
	{
		while (pos-- > 0)
			rotate("r", 'a', list_program);
	}
	else
	{
		while (size - pos++ > 0)
			rotate("rr", 'a', list_program);
	}
	push('a', list_program);
	merge_back_to_a_gear_step(list_program);
}

void	merge_back_to_a_gear(t_chunk *chunk_to_sort, \
			t_split_chunks *split_chunks, t_list_program *list_program)
{
	int			value;
	int			value_prev;
	t_list_dls	**stack_b;

	stack_b = list_program->stack_b;
	printer_dbg_split(MERGE_AS, split_chunks, list_program);
	if (!(*stack_b))
		return ;
	merge_back_to_a_gear_step(list_program);
}

// Function to split a chunk into three parts
void	split_chunk_gear( t_chunk *chunk_to_sort, t_split_chunks *split_chunks, \
			t_list_program *list_program)
{
	int	value;
	int	i;
	int	pivot1;

	if (!*list_program->stack_b)
		is_sorted_linked_list_push(list_program);
	chunk_to_sort->position = TOP_A;
	pivot_calculation(chunk_to_sort, split_chunks);
	printer_dbg_split(SPLIT, split_chunks, list_program);
	i = chunk_to_sort->min;
	pivot1 = split_chunks->pivot1;
	while (i <= chunk_to_sort->max)
	{
		value = (*list_program->stack_a)->index;
		if (value > split_chunks->pivot2)
			rotate("r", 'a', list_program);
		else if (value > pivot1)
			push('b', list_program);
		else
		{
			push('b', list_program);
			rotate("r", 'b', list_program);
		}
		i++;
	}
}

// Recursive function to sort a chunk
void	recursive_split_chunk_gear(t_chunk *chunk_to_sort, \
			t_list_program *list_program)
{
	t_split_chunks	split_chunks;

	if ((chunk_to_sort->max - chunk_to_sort->min <= 2))
		return ;
	split_chunk_gear(chunk_to_sort, &split_chunks, list_program);
	recursive_split_chunk_gear(&split_chunks.max, list_program);
	merge_back_to_a_gear(chunk_to_sort, &split_chunks, list_program);
}

void	gear_sort_pushswap(t_list_program *list_program)
{
	t_chunk	initial_chunk;

	ft_printers(GEAR, list_program);
	initial_chunk = (t_chunk){0, list_program->stack_a_size - 1, TOP_A};
	recursive_split_chunk_gear(&initial_chunk, list_program);
}
