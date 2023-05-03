/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 06:08:02 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/03 06:09:48 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

#ifndef AMBIENT_LIGHT_IDENTIFIER
# define AMBIENT_LIGHT_IDENTIFIER "A"
#endif

#ifndef CAMERA_IDENTIFIER
# define CAMERA_IDENTIFIER "C"
#endif

#ifndef LIGHT_IDENTIFIER
# define LIGHT_IDENTIFIER "L"
#endif

#ifndef SPHERE_IDENTIFIER
# define SPHERE_IDENTIFIER "sp"
#endif

#ifndef PLAN_IDENTIFIER
# define PLAN_IDENTIFIER "pl"
#endif

#ifndef CYLINDRE_IDENTIFIER
# define CYLINDRE_IDENTIFIER "cy"
#endif

typedef float	t_vector __attribute__((ext_vector_type(3)));

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_ambient_light
{
	t_color		color;
	float		ratio;
	char		identifier[3];
}				t_ambient_light;

typedef struct	s_camera
{
	t_vector	viewpoint;
	t_vector	orientation;
	float		FOV;
	char		identifier;
}				t_camera;

typedef struct	s_light
{
	t_vector	point;
	t_color		color;
	char		identifier[3];
}				t_light;

typedef struct	s_sphere
{
	t_vector	point;
	t_color		color;
	float		diameter;
	char		identifier[3];
}				t_sphere;

typedef struct	s_plan
{
	t_vector	point;
	t_vector	orientation;
	t_color		color;
	char		identifier[3];
}				t_plan;

typedef struct	s_cylindre
{
	t_vector	center;
	t_vector	cylinder_axis;
	t_color		color;
	float		diameter;
	float		height;
	char		identifier[3];
}				t_cylindre;

typedef struct	s_infos
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light;
	t_sphere		sphere;
	t_plan			plan;
	t_cylindre		cylindre;
}				t_infos;

#endif
