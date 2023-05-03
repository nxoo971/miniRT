/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:02:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/04 00:43:21 by jewancti         ###   ########.fr       */
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

int	main(int ac, char **av, char **env)
{
	t_infos	infos;

	if (!env || !*env)
		return ft_printf("{red}Error{reset}\nNo environment path available\n");
	if (ac != 2)
		return ft_printf("{red}Error{reset}\nWrong arguments count\n");
	if (check_extension_filename(av[1]) == false)
		return ft_printf("{red}Error{reset}\nWrong filename extension\n");
	t_content_file *cf = readfile(av[1], & infos);
	print_content_file(cf);
	cf_delete(cf);
	return 0;
}
