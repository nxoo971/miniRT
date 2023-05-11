/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 06:08:02 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/11 05:26:16 by jewancti         ###   ########.fr       */
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

#ifndef CYLINDER_IDENTIFIER
# define CYLINDER_IDENTIFIER "cy"
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
	char		identifier[3];
	t_color		color;
	float		ratio;
}				t_ambient_light;

typedef struct	s_camera
{
	char		identifier[3];
	t_vector	viewpoint;
	t_vector	orientation;
	float		FOV;
}				t_camera;

typedef struct	s_light
{
	char		identifier[3];
	t_vector	point;
	t_color		color;
	float		brightness;
}				t_light;

typedef struct	s_sphere
{
	char		identifier[3];
	t_vector	point;
	t_color		color;
	float		diameter;
}				t_sphere;

typedef struct	s_plan
{
	char		identifier[3];
	t_vector	point;
	t_vector	orientation;
	t_color		color;
}				t_plan;

typedef struct	s_cylinder
{
	char		identifier[3];
	t_vector	center;
	t_vector	cylinder_axis;
	float		diameter;
	float		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_figure
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light;
	t_sphere		sphere[512];
	t_plan			plan[512];
	t_cylinder		cylinder[512];
}				t_figure;

#endif
