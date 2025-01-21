#include <mlx.h>
#include <stdlib.h>
#include <math.h>
# include "libftper/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <unistd.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITER 100

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_data;

typedef struct s_complex {
    double re;
    double im;
} t_complex;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) 
{
    char *dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int mandelbrot(double cx, double cy) {
    t_complex z = {0, 0};
    int iter = 0;

    while (z.re * z.re + z.im * z.im <= 4 && iter < MAX_ITER) {
        double temp = z.re * z.re - z.im * z.im + cx;
        z.im = 2 * z.re * z.im + cy;
        z.re = temp;
        iter++;
    }
    return iter;
}

int get_color(int iter) {
    if (iter == MAX_ITER)
        return 0x000000; // Black for points inside the set
    int r = (iter * 9) % 256;
    int g = (iter * 7) % 256;
    int b = (iter * 3) % 256;
    return (r << 16) | (g << 8) | b; // RGB color
}

void render_mandelbrot(t_data *data) {
    double left = -2.0;
    double right = 1.0;
    double top = 1.5;
    double bottom = -1.5;
    double x_scale = (right - left) / WIDTH;
    double y_scale = (top - bottom) / HEIGHT;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cx = left + x * x_scale;
            double cy = top - y * y_scale;
            int iter = mandelbrot(cx, cy);
            int color = get_color(iter);
            my_mlx_pixel_put(data, x, y, color);
        }
    }
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);

    render_mandelbrot(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_loop(data.mlx);

    mlx_destroy_image(data.mlx, data.img);
    mlx_destroy_window(data.mlx, data.win);
    return 0;
}
