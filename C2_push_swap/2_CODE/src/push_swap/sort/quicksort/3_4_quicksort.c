/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 09:38:21 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_pushswap(t_list_program *list_program)
{
	ft_printers(QUICK, list_program);
}
/* void	recursive_split_chunk(t_chunk *chunk_to_sort, int *i, t_list_program \
			*list_program);
void	pivot_calculation(t_chunk *chunk_to_sort, t_splits *splits);
void	split_chunk(t_splits *splits, t_list_program *list_program);
void	merge_back(t_splits *splits, int *i, t_list_program *list_program);


void	quick_sort_pushswap(t_list_program *list_program)
{
	t_chunk	chunk_to_sort;
	int		size;
	int		i;

	i = 0;
	ft_printers(QUICK, list_program);
	size = list_program->stack_a_size;
	chunk_to_sort = (t_chunk){0, size - 1, size, TOP_A, size};
	recursive_split_chunk(&chunk_to_sort, &i, list_program);
}

void	recursive_split_chunk(t_chunk *chunk_to_sort, int *i, \
			t_list_program *list_program)
{
	t_splits	splits;

	splits = (t_splits){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (chunk_to_sort->size_parent <= 4)	//review this base case!
	{
//		sort_3_chunk(list_program);
		return ;
	}
	pivot_calculation(chunk_to_sort, &splits);
	split_chunk(&splits, list_program);
	recursive_split_chunk(&splits.max, i, list_program);
	recursive_split_chunk(&splits.mid, i,  list_program);
	recursive_split_chunk(&splits.min, i,  list_program);
	merge_back(&splits, i, list_program);
}

void	pivot_calculation(t_chunk *chunk_to_sort, t_splits *splits)
{
	int	delta;

	delta = chunk_to_sort->size - 1;
	splits->min_number = chunk_to_sort->min;
	splits->pivot1 = chunk_to_sort->min + delta / 3;
	splits->pivot2 = chunk_to_sort->min + 2 * delta / 3;
	splits->max_number = chunk_to_sort->max;
	splits->position_from = chunk_to_sort->position;
	splits->size_total = chunk_to_sort->size;
	splits->min.position = BOTTOM_B;
	splits->min.min = chunk_to_sort->min;
	splits->min.max = splits->pivot1;
	splits->min.size = splits->pivot1 - chunk_to_sort->min + 1;
	splits->min.size_parent = chunk_to_sort->size;
	splits->mid.position = TOP_B;
	splits->mid.min = splits->pivot1 + 1;
	splits->mid.max = splits->pivot2;
	splits->mid.size = splits->pivot2 - splits->pivot1;
	splits->mid.size_parent = chunk_to_sort->size;
	splits->max.position = BOTTOM_A;
	splits->max.min = splits->pivot2 + 1;
	splits->max.max = chunk_to_sort->max;
	splits->max.size = chunk_to_sort->max - splits->pivot2;
	splits->max.size_parent = chunk_to_sort->size;
}

// Function to split a chunk into three parts
void	split_chunk(t_splits *splits, t_list_program *list_program)
{
	int	value;
	int	i;
	int	pivot1;
	int	pivot2;

	printer_dbg_split(SPLIT, splits, list_program);
	i = splits->size_total;
	pivot1 = splits->pivot1;
	pivot2 = splits->pivot2;
	if (splits->position_from == BOTTOM_A)
	{
		while (i--)
			move_stack_fromto(BOTTOM_A, TOP_A, list_program);
	}
	if (splits->position_from == TOP_B)
	{
		while (i--)
			move_stack_fromto(TOP_B, TOP_A, list_program);
	}
	if (splits->position_from == BOTTOM_B)
	{
		while (i--)
			move_stack_fromto(BOTTOM_B, TOP_A, list_program);
	}
	i = splits->size_total;
	while (i--)
	{
		value = (*list_program->stack_a)->index;
		if (value > pivot2)
			move_stack_fromto(TOP_A, BOTTOM_A, list_program);
		else if (value > pivot1)
			move_stack_fromto(TOP_A, TOP_B, list_program);
		else
			move_stack_fromto(TOP_A, BOTTOM_B, list_program);
	}
}

void	merge_back(t_splits *splits, int *i, t_list_program *list_program)
{
	int	max_size;
	int	mid_size;
	int	min_size;

	printer_dbg_split(MERGE_NS, splits, list_program);
	if (*i == 3 || (splits->min.min == (*list_program->stack_a)->index \
		&& ft_lstsize(*list_program->stack_a) > 3)) //review this base case!
	{
		*i = 0;
		return ;
	}
	if (splits->min.min == 0 && splits->max.max == \
		list_program->stack_a_size - 1)
		return ;
	max_size = splits->max.size;
	mid_size = splits->mid.size;
	min_size = splits->min.size;
	while (max_size-- > 0)
		move_stack_fromto(BOTTOM_A, TOP_A, list_program);
	while (mid_size-- > 0)
		move_stack_fromto(TOP_B, TOP_A, list_program);
	while (min_size-- > 0)
		move_stack_fromto(BOTTOM_B, TOP_A, list_program);
	(*i)++;
}
 */