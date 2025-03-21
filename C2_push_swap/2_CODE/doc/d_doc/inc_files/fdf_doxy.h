
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:40:13 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/01 12:46:03 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DOXY_H
# define FDF_DOXY_H

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 0. HEADERS/MACROS													*/
/*#####################################################################	*/
/* ***************************************************************** */
/* 0.1 C Library													 */
/* ***************************************************************** */
# include <math.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <error.h>
# include <stdbool.h>
# include <time.h>

/* ***************************************************************** */
/* 0.2 Program Headers												 */
/* ***************************************************************** */
# include "fdf_data.h"
# include "fdf_defines.h"
# include "fdf_keycodes.h"

/* ***************************************************************** */
/* 0.3 Dependencies Headers											 */
/* ***************************************************************** */
/* ************************************************************* */
/* ************************************************************* */
# include "../libs/minilibx/minilibx_linux/mlx.h"
# include "../libs/mylibc/include/mylibc.h"
# include "../libs/mylibc/include/mylibc_data.h"

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 1. MAP LOAD															*/
/*#####################################################################	*/
/**
 * @brief Load the map from a file.
 * 
 * - This function initializes the map structure and loads the map data 
 * from the specified file path.
 * 
 * @param map Pointer to the map structure to be initialized.
 * @param path Path to the file containing the map data.
 */
void	load_map(t_map *map, char *path);
/* ***************************************************************** */
/* 1.1 Map Load														 */
/* ***************************************************************** */
/**
 * @brief Initialize the map structure.
 * 
 * - This function sets up the initial state of the map structure, 
 * 	including allocating memory for the map data.
 * - Initialize the colors for the map.
 * - Calculate the size of the map.
 * 
 * @param map Pointer to the map structure to be initialized.
 * @param total Total number of points in the map.
 */
void	map_ini(t_map *map, int total);
void	map_ini_colors(t_map *map);
void	map_size(t_map *map);

/* ***************************************************************** */
/* 1.1 Get points													 */
/* ***************************************************************** */
/**
 * @brief Retrieve points from the map.
 * 
 * - This function processes the map data to extract individual points.
 * 
 * @param map Pointer to the map structure containing the map data.
 */
void	map_get_points(t_map *map);

/**
 * @brief Load points from a line of map data.
 * 
 * - This function parses a line of map data to load points into the map.
 * 
 * @param line Line of map data to be parsed.
 * @param map Pointer to the map structure to store the points.
 * @param numline Line number in the map data.
 * @return int Returns 1 if points are loaded successfully, otherwise 0.
 */
int		load_points(char *line, t_map *map, int numline);

/**
 * @brief Validate a point value.
 * 
 * - This function checks if a given point value is valid.
 * 
 * @param value String representation of the point value.
 * @return int Returns 1 if the point value is valid, otherwise 0.
 */
int		valid_point(char *value);

/**
 * @brief Check for hexadecimal colors in a line.
 * 
 * - This function cgecks if the map data contains hexadecimal color values.
 * 
 * @param line Line of map data to be checked.
 * @return int Returns 1 if hexadecimal colors are found, otherwise 0.
 */
int		has_hexcolors(char *line);

/* ***************************************************************** */
/* 1.1 Colorize														 */
/* ***************************************************************** */
void	colorize(t_map *map);
void	load_color(int max, int min, t_point *point, t_colors	colors);
int		gradient(int startcolor, int endcolor, int len, int pix);
void	shadow(t_point *points, int len);
void	go_polar(t_map *map);


// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 2. SYSTEM															*/
/*#####################################################################	*/
void	system_init(t_meta *meta);
void	system_init_keys(t_meta *meta);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 3. MAP DRAW															*/
/*#####################################################################	*/
int		draw_map(t_meta *meta, int fit);

/* ***************************************************************** */
/* 3.1 Generate Background											 */
/* ***************************************************************** */
void	generate_background(t_meta *meta, int backcolor, int menucolor);
int		get_color(t_meta *meta, int color);
void	set_color(char *buffer, int endian, int color, int alpha);
void	copy_map(t_point *src, t_point *dst, int len);

/* ***************************************************************** */
/* 3.2 Parse Map													 */
/* ***************************************************************** */
void	parse_map(t_meta *meta, t_point *proyect);
void	z_division(t_point *proyect, float divisor, int len);
void	bending(t_point *points, int len, float range);
void	rotate_x(t_point *points, t_point *projection, float ang, int len);
void	rotate_y(t_point *points, t_point *projection, float ang, int len);
void	rotate_z(t_point *points, t_point *projection, float ang, int len);
void	ortogonal_projection(t_point *points, t_point *projection, int len);
t_point	matrix3_multp(float matrix[3][3], t_point point);
void	scale(t_point *points, int scale, int len);
void	traslate(t_point *points, t_point move, int len);

/* ***************************************************************** */
/* 3.3 Drawining													 */
/* ***************************************************************** */
void	drawing(t_meta *meta, t_point *proyect, int fit);
void	generate_stars(t_meta *meta);
void	go_fit(t_meta *meta, t_point *proyect);
void	wired(t_meta *meta, t_point *wire);
void	wire_line(t_point *point, t_meta *meta, int density, int line);
int		draw_line(t_meta *meta, t_point start, t_point end);
void	doted(t_meta *meta, t_point *proyect);
void	draw_dot(t_meta *meta, t_point point, int radius);
void	dot_util(t_meta *meta, t_point pixel, t_point point, int coord);

/* ***************************************************************** */
/* 3.4 Menu															 */
/* ***************************************************************** */
void	draw_menu(t_meta *meta);
void	draw_info(t_meta *meta);
void	draw_controls(t_meta *meta);
void	draw_mapinfo(t_meta *meta);
void	draw_colorscheme(t_meta *meta);

/* ***************************************************************** */
/* 3.4 Draw Utils													 */
/* ***************************************************************** */
int		valid_pixel(t_point pixel);
int		limits(t_point *points, int len);
int		my_putpixel(t_meta *meta, t_point pixel);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 4. VIEWS																*/
/*#####################################################################	*/
/* ***************************************************************** */
/* 1.1 Views Features												 */
/* ***************************************************************** */
void	isometric(t_map *map);
void	parallel(t_map *map);
void	spherize(t_map *map, t_point *points);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 5. CONTROLS															*/
/*#####################################################################	*/
/* ***************************************************************** */
/* 5.1 Control Keys													 */
/* ***************************************************************** */
//# include "keycodes.h"
int		key_press(int key, void *param);
int		key_release(int key, void *param);
void	control_keys1(int key, t_meta *meta);
void	control_keys2(int key, t_meta *meta);
void	control_keys3(int key, t_meta *meta);

/* ***************************************************************** */
/* 5.2 Control Mouse												 */
/* ***************************************************************** */
int		mouse_move(int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);

/* ***************************************************************** */
/* 5.3 Control Utils												 */
/* ***************************************************************** */
void	control_colorscheme(int key, t_map *map);
void	angle_control(int key, t_meta *meta);
void	angle(float *ang, float value);
int		halt_exit_program(void *param);
void	terminate(char *s);
void	terminate1(char *s, t_meta *meta);
void	print_nbr(t_meta *meta, int x, int y, int nbr);
void	print_str(t_meta *meta, int x, int y, char *str);

#endif
