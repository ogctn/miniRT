/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:32:43 by sgundogd          #+#    #+#             */
/*   Updated: 2024/03/01 06:41:21 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// https://graphics.cs.wisc.edu/WP/cs559-fall2016/files/2016/12/shirley_chapter_4.pdf
// https://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/basic_algo.pdf
// https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing/implementing-the-raytracing-algorithm.html


int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || control_extension(av[1]))
		return (printf("Error!\nWrong argument"), 1);
	initialize(&data, av[1]);
	main_loop(&data);
	return (0);
}

// Cylinder intersection formula is uncompleted. [intersections.c: intersects_cylinder() ] 
// Camera direction and rotation will be implemented. [ test.c: pixel_to_virtual() ]
// Shadows will be corrected. [ test.c: any_obj_between_light_and_hit_point() ]
