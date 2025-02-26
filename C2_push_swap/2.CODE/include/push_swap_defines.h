/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:29:17 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 12:16:56 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEFINES_H
# define PUSH_SWAP_DEFINES_H

//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
/* ***************************************************************** */
/* MACROS															 */
/* ***************************************************************** */
/*
- 0: no debug, false
- 1: debug, true
*/
# ifndef DBG
#  define DBG 0
# endif

# undef NAME_M
# define NAME_M "log/2.Memory_Check/allocs/malloc_allocs.txt"

# ifndef MAX_MOVES
#  define MAX_MOVES 6000
# endif

# define SA_PATH "log/3.Unit_Testing/stack_a.txt"
# define SB_PATH "log/3.Unit_Testing/stack_b.txt"
# define PRICES_PATH "log/3.Unit_Testing/prices.txt"

/*
- selec
- radix
- quick
- gear
*/
# ifndef ALGO
#  define ALGO 0
# endif

#endif