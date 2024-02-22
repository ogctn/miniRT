#include "keys.h"
#include "rt.h"



void    init_mlxs( t_mlx *m ) {
    int w = V_W;
    int h = V_H;

	m->mlx_p = mlx_init();
	m->win_p = mlx_new_window( m->mlx_p, w, h, "miniRT" );
	m->img.img = mlx_new_image( m->mlx_p, w, h );
	m->img.addr = mlx_get_data_addr( m->img.img, &( m->img.bpp ), &( m->img.line_len ), &( m->img.endian ) );
}

void	my_pixel_put( t_img *img, int x, int y, int color ) {
	char	*dst;

	dst = img->addr + ( y * img->line_len + x * ( img->bpp / 8 ) );
	*( unsigned int * )dst = color;
}

void	render_background( t_img *img, int color ) {
    int	i;
    int	j;

    i = -1;
    while ( ++i < V_W ) {
        j = -1;
        while ( ++j < V_H )
            my_pixel_put( img, j, i, color );
    }
}


void	test_handler( int keycode, t_general *genel ); // source at test.c
void render_sphere(t_general *genel);


int	test_handle_key( int keycode, t_general *genel) {
    test_handler( keycode, genel );
	return ( 0 );
}

void mlx_stuffs( t_general *genel ) {
	init_mlxs( genel->mlx );
    
    render_sphere(genel);

	mlx_put_image_to_window( genel->mlx->mlx_p, genel->mlx->win_p, genel->mlx->img.img, 0, 0 );

    //mlx_hook( genel->mlx->win_p, EVENT_KEY_PRESS, 1, &test_handle_key, genel );

	mlx_loop( genel->mlx->mlx_p );
}
