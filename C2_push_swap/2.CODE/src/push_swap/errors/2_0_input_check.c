/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.0.Checkargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:30:32 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/19 08:19:56 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
#include "push_swap.h"

//##############################################################################
// ERROR HANDLING
//##############################################################################
/*
** Function to check for duplicates and non-integers in the input
*/
void	error_handling_input_1(t_list_program *list_program)
{
	char	**argv_1;
	int		argc;
	int		size;

	argc = list_program->argc;
	argv_1 = list_program->stack_a_array;
	size = list_program->stack_a_size;
	if (ft_strcmp_duplicate_inter(argv_1)
		|| !ft_is_array_int(argv_1))
	{
		ft_free_push_swap_halt(list_program);
		halt_exit_(1);
	}
	else if (ft_is_sorted_array_char(&argv_1[1]) || size == 1)
	{
		ft_free_push_swap_halt(list_program);
		halt_exit_(0);
	}
	return ;
}

/*
** Function to check for the number of arguments
*/
void	error_handling_input_0(int argc, char **argv)
{
	if (argc < 2)
		halt_exit_(0);
	if (argv[1] == NULL || argv[1][0] == '\0')
		halt_exit_(0);
}
