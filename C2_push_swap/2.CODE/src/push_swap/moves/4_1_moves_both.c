/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_1_moves_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:31:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/27 10:46:48 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
//#include "all_inc_inc.h"
#include "push_swap.h"

//##############################################################################
// STACK MOVES
//##############################################################################
/*
- Swap the top two elements of both stacks.
*/
void	swap_both(t_list_program *list_program)
{
	swap('a', list_program);
	swap('b', list_program);
	ft_snprintf(list_program->moves[list_program->move_count++], \
				list_program->max_moves, "ss");
	ft_printers(MOVES, list_program);
}

/*
- Rotate the top two elements of stack.
*/
void	rotate_both(char *direction, t_list_program *list_program)
{
	if (!ft_strncmp(direction, "rr", sizeof("rr")))
	{
		rotate("r", 'a', list_program);
		rotate("r", 'b', list_program);
	}
	else if (!ft_strncmp(direction, "rrr", sizeof("rrr")))
	{
		rotate("rr", 'a', list_program);
		rotate("rr", 'b', list_program);
	}

	ft_snprintf(list_program->moves[list_program->move_count++], \
				list_program->max_moves, "%s", direction);
	ft_printers(MOVES, list_program);
}

void	move_stack_fromto_case(char *move_case, t_list_program *list_program)
{
	if (!ft_strncmp("pb+rb", move_case, sizeof("pb+rb")))
	{
		push('b', list_program);
		rotate("r", 'b', list_program);
	}
	else if (!ft_strncmp("rrb+pa+ra", move_case, sizeof("rrb+pa+ra")))
	{
		rotate("rr", 'b', list_program);
		push('a', list_program);
		rotate("r", 'a', list_program);
	}
}

/*
pb+rb
rrb+pa+ra

pb+rb
rra+pb
rra+pb+rb
pa+ra
rrb+pa
rrb+pa+ra
*/