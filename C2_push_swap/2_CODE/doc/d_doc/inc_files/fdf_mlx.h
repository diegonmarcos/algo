/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_doxy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:32:38 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:47 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * 
 * MINILIBX_LINUX_URL	= https://github.com/42Paris/minilibx-linux.git
 * MINILIBX_LINUX_DIR	= libs/minilibx/minilibx_linux
 * 
 */

#include "../libs/minilibx/minilibx_linux/mlx.h"

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
uint	mlx_get_color_value(void *mlx_ptr, int color);
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
