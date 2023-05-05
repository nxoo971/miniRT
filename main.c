/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:02:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/05 00:33:50 by jewancti         ###   ########.fr       */
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
	// const t_camera			camera = infos.camera;
	// const t_light			light = infos.light;
	// const t_sphere			sphere = infos.sphere;
	// const t_plan			plan = infos.plan;
	// const t_cylindre		cylindre = infos.cylindre;

	ft_printf("{red}/* ********************** *\\{reset}\n");
	ft_printf("{cyan}\tAMBIENT LIGHT{reset}\n");
	ft_printf("{red}\\* ********************** */{reset}\n");
	ft_printf("Identifier: %s\n", ambient_light.identifier);
	ft_printf("Ratio: %.1f\n", ambient_light.ratio);
	ft_printf("Struct color:\n");
	ft_printf("\t{red}R{reset}: %d\n", ambient_light.color.r);
	ft_printf("\t{green}G{reset}: %d\n", ambient_light.color.g);
	ft_printf("\t{blue}B{reset}: %d\n", ambient_light.color.b);
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
	print_content_file(cf);
	print_figure_structs(infos);
	cf_delete(cf);
	return 0;
}
