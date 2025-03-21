
/**
 * Bresenham's line algorithm implementation
 * Draws a line between two points (x0,y0) and (x1,y1)
 * Similar to XDrawLine() but implemented for use with MiniLibX
 */

/**
 * Alternative implementation that draws directly to an image buffer
 * Uses Gradient Interpolation for color blending
 * More efficient for MiniLibX as it avoids multiple calls to mlx_pixel_put
 */
/* void	ft_draw_line2(unsigned int *img_data, int img_width, t_points1 *p)
