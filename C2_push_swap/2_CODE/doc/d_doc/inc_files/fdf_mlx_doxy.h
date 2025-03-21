/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:32:38 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/05 17:44:59 by dinepomu         ###   ########.fr       */
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

/**
 * @brief Initializes the MLX library.
 *
 * This function sets up the necessary environment for using the MLX library.
 * It must be called before any other MLX functions are used.
 *
 * @return A pointer to the MLX instance, or NULL if initialization fails.
 */
void	*mlx_init(void);



/**
 * @brief Creates a new window.
 *
 * This function creates a new window with the specified dimensions and title.
 *
 * @param mlx_ptr A pointer to the MLX instance.
 * @param size_x The width of the window in pixels.
 * @param size_y The height of the window in pixels.
 * @param title The title of the window.
 * @return A pointer to the newly created window, or NULL if the window could not be created.
 */
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);



/**
 * @brief Creates a new image.
 *
 * This function creates a new image with the specified width and height.
 *
 * @param mlx_ptr A pointer to the MLX instance.
 * @param width The width of the new image.
 * @param height The height of the new image.
 * @return A pointer to the newly created image, or NULL if the creation fails.
 */
void	*mlx_new_image(void *mlx_ptr, int width, int height);



/**
 * @brief Get the address of the image data.
 *
 * This function returns the address of the image data for the given image pointer.
 * It also provides information about the image's bits per pixel, size of each line,
 * and endian format.
 *
 * @param img_ptr Pointer to the image.
 * @param bits_per_pixel Pointer to an integer where the function will store the number of bits per pixel.
 * @param size_line Pointer to an integer where the function will store the size of each line in bytes.
 * @param endian Pointer to an integer where the function will store the endian format (0 for little endian, 1 for big endian).
 * @return Pointer to the image data.
 */
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);



/**
 * @brief Sets up a hook for a specific event on a given window.
 *
 * This function allows you to define a callback function that will be called
 * when a specified event occurs on the given window.
 *
 * @param win_ptr A pointer to the window where the event will be monitored.
 * @param x_event The event identifier to hook (e.g., key press, mouse click).
 * @param x_mask The mask that specifies which events to listen for.
 * @param funct A pointer to the callback function that will be called when the event occurs.
 * @param param A pointer to any additional parameters that need to be passed to the callback function.
 *
 * @return An integer indicating the success or failure of setting the hook.
 */
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);




/**
 * @brief Puts an image to a window at the specified coordinates.
 *
 * This function displays an image in a window at the given (x, y) coordinates.
 *
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window where the image will be displayed.
 * @param img_ptr Pointer to the image to be displayed.
 * @param x The x-coordinate where the image will be placed in the window.
 * @param y The y-coordinate where the image will be placed in the window.
 * @return An integer status code (usually 0 for success).
 */
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);



/**
 * @brief Retrieves the color value in the format used by the MLX library.
 *
 * This function converts a given color value to the format used internally by the MLX library.
 *
 * @param mlx_ptr A pointer to the MLX instance.
 * @param color The color value to be converted.
 * @return The color value in the MLX format.
 */
uint	mlx_get_color_value(void *mlx_ptr, int color);




/**
 * @brief Draws a string on the window at the specified coordinates.
 *
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window instance.
 * @param x The x-coordinate where the string will be drawn.
 * @param y The y-coordinate where the string will be drawn.
 * @param color The color of the string in hexadecimal format.
 * @param string The string to be drawn.
 *
 * @return An integer status code (typically 0 for success).
 */
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);



/**
 * @brief Destroys a window created by the MiniLibX library.
 *
 * This function takes two pointers as arguments: one to the MiniLibX instance
 * and one to the window to be destroyed. It releases all resources associated
 * with the specified window.
 *
 * @param mlx_ptr A pointer to the MiniLibX instance.
 * @param win_ptr A pointer to the window to be destroyed.
 * @return An integer indicating the success or failure of the operation.
 */
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
