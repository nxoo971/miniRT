/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:02:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/07 01:17:56 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static
void	print_content_file(const t_content_file *cf)
{
	t_content_file	*tmp;
	size_t			i;

	tmp = (t_content_file *)cf;
	i = 1;
	while (tmp)
	{
		ft_printf("{bgred}{black}Line {white}%d{reset}\n", i++);
		ft_printf("\t{cyan}Addr{reset}:\t\t%p\n", tmp);
		ft_printf("\t{green}Size{reset}:\t\t%u\n", tmp -> size);
		ft_printf("\t{blue}Capacity{reset}:\t%u\n", tmp -> capacity);
		ft_printf("\t{red}Line{reset}:\t\t%s\n", tmp -> line);
		tmp = tmp -> next;
		if (tmp)
			ft_putchar('\n');
	}
}

static
void	print_figure_structs(const t_figure infos)
{
	const t_ambient_light	ambient_light = infos.ambient_light;
	const t_camera			camera = infos.camera;
	const t_light			light = infos.light;
	const t_sphere			sphere = infos.sphere;
	const t_plan			plan = infos.plan;
	const t_cylinder		cylinder = infos.cylinder;

	ft_printf("{red}/* ********************** *\\{reset}\n");
	ft_printf("{cyan}\tAMBIENT LIGHT{reset}\n");
	ft_printf("{red}\\* ********************** */{reset}\n");
	ft_printf("Identifier: %s\n", ambient_light.identifier);
	printf("Ratio: %.1f\n", ambient_light.ratio);
	ft_printf("Struct color:\n");
	ft_printf("\t{red}R{reset}: %d\n", ambient_light.color.r);
	ft_printf("\t{green}G{reset}: %d\n", ambient_light.color.g);
	ft_printf("\t{blue}B{reset}: %d\n", ambient_light.color.b);
	
	ft_printf("\n");

	ft_printf("{red}/* ********************** *\\{reset}\n");
	ft_printf("{cyan}\t   CAMERA{reset}\n");
	ft_printf("{red}\\* ********************** */{reset}\n");
	ft_printf("Identifier: %s\n", camera.identifier);
	ft_printf("View point:\n");
	printf("\tx: %.1f\n", camera.viewpoint.x);
	printf("\ty: %.1f\n", camera.viewpoint.y);
	printf("\tz: %.1f\n", camera.viewpoint.z);
	ft_printf("Orientation:\n");
	printf("\tx: %.1f\n", camera.orientation.x);
	printf("\ty: %.1f\n", camera.orientation.y);
	printf("\tz: %.1f\n", camera.orientation.z);
	ft_printf("FOV: %.1f\n", camera.FOV);
	
	ft_printf("\n");

	ft_printf("{red}/* ********************** *\\{reset}\n");
	ft_printf("{cyan}\t    LIGHT{reset}\n");
	ft_printf("{red}\\* ********************** */{reset}\n");
	ft_printf("Identifier: %s\n", light.identifier);
	ft_printf("Point:\n");
	printf("\tx: %.1f\n", light.point.x);
	printf("\ty: %.1f\n", light.point.y);
	printf("\tz: %.1f\n", light.point.z);
	ft_printf("Struct color:\n");
	ft_printf("\t{red}R{reset}: %d\n", light.color.r);
	ft_printf("\t{green}G{reset}: %d\n", light.color.g);
	ft_printf("\t{blue}B{reset}: %d\n", light.color.b);
	printf("Brightness: %.1f\n", light.brightness);
	
	ft_printf("\n");

	ft_printf("{red}/* ********************** *\\{reset}\n");
	ft_printf("{cyan}\t   SPHERE{reset}\n");
	ft_printf("{red}\\* ********************** */{reset}\n");
	ft_printf("Identifier: %s\n", sphere.identifier);
	ft_printf("Point:\n");
	printf("\tx: %.1f\n", sphere.point.x);
	printf("\ty: %.1f\n", sphere.point.y);
	printf("\tz: %.1f\n", sphere.point.z);
	ft_printf("Struct color:\n");
	ft_printf("\t{red}R{reset}: %d\n", sphere.color.r);
	ft_printf("\t{green}G{reset}: %d\n", sphere.color.g);
	ft_printf("\t{blue}B{reset}: %d\n", sphere.color.b);
	printf("Diameter: %.1f\n", sphere.diameter);
	
	ft_printf("\n");

	ft_printf("{red}/* ********************** *\\{reset}\n");
	ft_printf("{cyan}\t    PLAN{reset}\n");
	ft_printf("{red}\\* ********************** */{reset}\n");
	ft_printf("Identifier: %s\n", plan.identifier);
	ft_printf("Point:\n");
	printf("\tx: %.1f\n", plan.point.x);
	printf("\ty: %.1f\n", plan.point.y);
	printf("\tz: %.1f\n", plan.point.z);
	ft_printf("Orientation:\n");
	printf("\tx: %.1f\n", plan.orientation.x);
	printf("\ty: %.1f\n", plan.orientation.y);
	printf("\tz: %.1f\n", plan.orientation.z);
	ft_printf("Struct color:\n");
	ft_printf("\t{red}R{reset}: %d\n", plan.color.r);
	ft_printf("\t{green}G{reset}: %d\n", plan.color.g);
	ft_printf("\t{blue}B{reset}: %d\n", plan.color.b);
	
	ft_printf("\n");

	ft_printf("{red}/* ********************** *\\{reset}\n");
	ft_printf("{cyan}\t  CYLINDER{reset}\n");
	ft_printf("{red}\\* ********************** */{reset}\n");
	ft_printf("Identifier: %s\n", cylinder.identifier);
	ft_printf("Center:\n");
	printf("\tx: %.1f\n", cylinder.center.x);
	printf("\ty: %.1f\n", cylinder.center.y);
	printf("\tz: %.1f\n", cylinder.center.z);
	ft_printf("Cylinder axis:\n");
	printf("\tx: %.1f\n", cylinder.cylinder_axis.x);
	printf("\ty: %.1f\n", cylinder.cylinder_axis.y);
	printf("\tz: %.1f\n", cylinder.cylinder_axis.z);
	ft_printf("Struct color:\n");
	ft_printf("\t{red}R{reset}: %d\n", cylinder.color.r);
	ft_printf("\t{green}G{reset}: %d\n", cylinder.color.g);
	ft_printf("\t{blue}B{reset}: %d\n", cylinder.color.b);
	printf("Diameter: %.1f\n", cylinder.diameter);
	printf("Height: %.1f\n", cylinder.height);
	
	ft_printf("\n");
}

int	main(int ac, char **av, char **env)
{
	t_figure	infos = { 0 };

	if (!env || !*env)
		return ft_printf("{red}Error{reset}\nNo environment path available\n");
	if (ac != 2)
		return ft_printf("{red}Error{reset}\nWrong arguments count\n");
	if (check_extension_filename(av[1]) == false)
		return ft_printf("{red}Error{reset}\nWrong filename extension\n");
	t_content_file *cf = readfile(av[1], & infos);
	if (cf) {
		print_content_file(cf);
		print_figure_structs(infos);
		cf_delete(cf);
	} else {
		ft_printf("{red}Error{reset}\nParsing: KO\n");
	}

	// ft_memset(& infos, 0, sizeof(t_figure));

	// void *ptr = (& infos);

	// *((int *)(ptr + sizeof(int))) = -42;
	// *((int *)(ptr + sizeof(int) * 2)) = 18;
	// *((int *)(ptr + sizeof(int) * 3)) = 127;
	// *((float *)(ptr + sizeof(int) * 3 + sizeof(float))) = -193.;
	
	// ft_printf("%p\n", & infos.camera.identifier);
	// ft_printf("%p\n", & infos.camera.viewpoint);
	// ft_printf("%p\n", & infos.camera.orientation);
	// ft_printf("%p\n", & infos);
	// ft_printf("%p\n", & infos.ambient_light);
	// ft_printf("%p\n", & infos.ambient_light.color);
	// ft_printf("%p\n", & infos.ambient_light.color.r);
	// ft_printf("%p\n", & infos.ambient_light.color.g);
	// ft_printf("%p\n", & infos.ambient_light.color.b);
	// ft_printf("%p\n\n", & infos.ambient_light.ratio);

	// ft_printf("%p\n", & infos.camera.identifier);
	// ft_printf("%p\n", & infos.camera.viewpoint);
	// ft_printf("%p\n", & infos.camera.orientation);
	// ft_printf("%p\n", & infos.camera.FOV);
	// ft_printf("%d\n", sizeof(t_vector));
	
	// ft_printf("%p\n", ptr);
	// ft_printf("%p\n", ptr + 4);
	// ft_printf("%p\n", ptr + 8);
	// printf("%d\n", *(int*)(ptr + sizeof(int)));
    // printf("%d\n", *(int*)(ptr + sizeof(int) * 2));
    // printf("%d\n", *(int*)(ptr + sizeof(int) * 3));
    // printf("%f\n", *(float *)(ptr + sizeof(int) * 3 + sizeof(float)));
	// print_figure_structs(infos);
	return 0;
}
