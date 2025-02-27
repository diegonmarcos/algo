/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_moves_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:53:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/27 08:42:23 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to move a value from one position to another
void	move_stack_fromto(t_position from, t_position to, t_list_program \
			*list_program)
{
	if (from == to)
		return ;
	if (from == TOP_A)
	{
		if (to == BOTTOM_A)
			rotate("r", 'a', list_program);
		else if (to == TOP_B)
			push('b', list_program);
		else if (to == BOTTOM_B)
		{
			push('b', list_program);
			rotate("r", 'b', list_program);
		}
	}
	else
		move_stack_fromto1(from, to, list_program);
}

void	move_stack_fromto1(t_position from, t_position to, t_list_program \
			*list_program)
{
	if (from == BOTTOM_A)
	{
		if (to == TOP_A)
			rotate("rr", 'a', list_program);
		else if (to == TOP_B)
		{
			rotate("rr", 'a', list_program);
			push('b', list_program);
		}
		else
		{
			rotate("rr", 'a', list_program);
			push('b', list_program);
			rotate("r", 'b', list_program);
		}
	}
}

void	move_stack_fromto2(t_position from, t_position to, t_list_program \
			*list_program)
{
	if (from == TOP_B)
	{
		if (to == BOTTOM_B)
			rotate("r", 'b', list_program);
		else if (to == TOP_A)
			push('a', list_program);
		else
		{
			push('a', list_program);
			rotate("r", 'a', list_program);
		}
	}
	else
	{
		if (to == TOP_B)
			rotate("rr", 'b', list_program);
		else if (to == TOP_A)
		{
			rotate("rr", 'b', list_program);
			push('a', list_program);
		}
		else
			move_stack_fromto_case("rrb+pa+ra", list_program)
	}
}

/* 			rotate("rr", 'b', list_program);
			push('a', list_program);
			rotate("r", 'a', list_program); 
*/