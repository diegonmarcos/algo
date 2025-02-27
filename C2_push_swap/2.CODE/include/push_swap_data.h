/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:25:50 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/27 22:55:22 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DATA_H
# define PUSH_SWAP_DATA_H

//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
# include "ft_mylib.h"
# include <stdbool.h>


//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
//##################################################################### */
// DATA STRUCTURE														*/
//##################################################################### */
/* ***************************************************************** */
/* PUSH SWAP LIST													 */
/* ***************************************************************** */
/*
typedef struct s_list_garbage
{
	void	*allocated_pointers[MAX_ALLOCATIONS];
	int		blocks_count;
}			t_list_garbage;
*/

/*
typedef struct s_list_dls
{
	int					value;
	int					index;
	struct s_list_dls	*next;
	struct s_list_dls	*prev;
}				t_list_dls;
*/

typedef struct s_list_program
{
	int				dbg;
	t_list_garbage	*list_garbage;

	int				argc;
	char			**argv;
	char			**stack_a_array;
	int				stack_a_size;
	t_list_dls		**stack_a;
	t_list_dls		**stack_b;
	char			**moves;
	int				max_moves;
	int				move_count;
	char			**moves_optim;
	int				move_optim_count;
}					t_list_program;

/* ***************************************************************** */
/* QUICK SORT														 */
/* ***************************************************************** */
typedef enum e_position
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}			t_position;

typedef enum e_sort_3_cases
{
	CASE_0,
	CASE_A,
	CASE_B,
	CASE_C,
	CASE_D,
	CASE_E,
	CASE_F
}			t_sort_3_cases;

typedef struct s_chunk
{
	int			min;
	int			max;
	int			size;
	t_position	position;
}				t_chunk;

typedef struct s_split_chunks
{
	int			min_number;
	int			pivot1;
	int			pivot2;
	int			max_number;
	int			size_total;
	t_position	position_from;
	t_chunk		max;
	t_chunk		mid;
	t_chunk		min;
}				t_split_chunks;

/* ***************************************************************** */
/* GEAR SORT														 */
/* ***************************************************************** */
typedef struct s_node_pos_locator
{
	t_list_dls	*current;
	t_list_dls	**stack_b;
	int			size;

	int			pos;
	int			max_node;
}				t_node_pos_locator;

typedef struct s_move_lower_cost
{
	t_list_dls	*current;
	int			current_rotations;
	int			current_price;

	int			price_of_cheapest;
	int			moves_to_cheapest;
	int			value_of_cheapest;
	int			moves_to_cheapest_abs;
	int			rotations_b_cheapest;

	int			rotations_b;
	int			rotations_b_abs;
}				t_move_lower_cost;

typedef struct s_sort_gearing
{
	int					rotations_a;
	int					rotations_a_abs;
	t_move_lower_cost	*t_move_lower_cost;
}						t_sort_gearing;

/* ***************************************************************** */
/* UTILS															 */
/* ***************************************************************** */
typedef struct s_x
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		k;
}			t_x;

typedef struct s_chunk1
{
	int				min;
	int				max;
	int				pivot1;
	int				pivot2;
	struct s_chunk1	*split_chunks_max;
	struct s_chunk1	*split_chunks_mid;
	struct s_chunk1	*split_chunks_min;
}					t_chunk1;

#endif

//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
//##################################################################### */
// DATA STRUCTURE														*/
//##################################################################### */

/* typedef enum e_algos
{
	selec,
	radix,
	quick,
	gear
}	t_algos; */


/* DATA STRUCTURE
// PUSH SWAP LIST
//	- stack_a is a pointer to the stack A.
//	- stack_b is a pointer to the stack B.
//	- moves is an array of strings representing the moves.
//	- move_count is an integer that counts the number of moves.
//	- max_moves is an integer of the maximum of moves allowed.
//	- list_garbage is a pointer to the allocation tracker list.
typedef struct s_list_program
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				stack_a_size;
	char			**moves;
	char			**moves_optim;
	int				move_count;
	int				max_moves;
	int				dbg;
	t_list_garbage	*list_garbage;
}					t_list_program;

*/