/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:44:48 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/23 21:18:34 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			i = s1[i] - s2[i];
			free(s1);
			return (i);
		}
		i++;
	}
	free(s1);
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}

int	size_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

void	control_elements(t_parse *file)
{
	if (file->a != 1 || file->c != 1 || file->l != 1)
	{
		printf("Missing or extra Elements\n");
		exit(1);
	}
}

void	free_2d(char **d)
{
	int	i;

	if (!d)
		return ;
	i = 0;
	while (d[i])
		free(d[i++]);
	free(d);
}
