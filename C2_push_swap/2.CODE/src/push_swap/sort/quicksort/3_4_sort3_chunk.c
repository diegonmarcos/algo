/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_sort3_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:09 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 09:38:21 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_chunk_case(t_sort_3_cases case_, t_list_program *list_program);
void	sort_3_chunk_case_1(t_sort_3_cases case_, t_list_program *list_program);

/*
| Case 0 | Case A | Case B | Case C | Case D | Case E | Case F |
|--------|--------|--------|--------|--------|--------|--------|
|   2    |   3    |   3    |   2    |   2    |   1    |   1    |
|   1    |   2    |   1    |   1    |   3    |   3    |   2    |
|   2    |   1    |   2    |   3    |   1    |   2    |   3    |
*/
void	sort_3_chunk(t_list_program *list_program)
{
	t_list_dls	**stack_a;
	int			first;
	int			second;
	int			third;

	stack_a = list_program->stack_a;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && first == third)
		sort_3_chunk_case(CASE_0, list_program);
	else if (first > second && second > third && first > third)
		sort_3_chunk_case(CASE_A, list_program);
	else if (first > second && second < third && first > third)
		sort_3_chunk_case(CASE_B, list_program);
	else if (first > second && second < third && first < third)
		sort_3_chunk_case(CASE_C, list_program);
	else if (first < second && second > third && first > third)
		sort_3_chunk_case(CASE_D, list_program);
	else if (first < second && second > third && first < third)
		sort_3_chunk_case(CASE_E, list_program);
	else if ((first < second && second < third && first < third) \
		|| first == second)
		return ;
}

void	sort_3_chunk_case(t_sort_3_cases case_, t_list_program *list_program)
{
	if (case_ == CASE_0)
		swap('a', list_program);
	else if (case_ == CASE_A)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if (case_ == CASE_B)
	{
		swap('a', list_program);
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if (case_ == CASE_C)
		swap('a', list_program);
	else
		sort_3_chunk_case_1(case_, list_program);
}

void	sort_3_chunk_case_1(t_sort_3_cases case_, t_list_program *list_program)
{
	if (case_ == CASE_D)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		push('a', list_program);
	}
	else if (case_ == CASE_E)
	{
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if (case_ == CASE_F)
		return ;
}

/* void	sort_3_chunk(t_list_program *list_program)
{
	t_list_dls	**stack_a;
	int			first;
	int			second;
	int			third;

	stack_a = list_program->stack_a;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && first == third)
		swap('a', list_program);
	else if (first > second && second > third && first > third)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		swap('a', list_program);
		push('a', list_program);

	}
	else if (first > second && second < third && first > third)
	{
		swap('a', list_program);
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if (first > second && second < third && first < third)
		swap('a', list_program);
	else if (first < second && second > third && first > third)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		push('a', list_program);
	}
	else if (first < second && second > third && first < third)
	{
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if ((first < second && second < third && first < third) \
		|| first == second)
		return ;
} */
