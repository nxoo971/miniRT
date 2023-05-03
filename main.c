/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:02:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/03 06:31:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "content_file.h"

static
void	print_content_file(const t_content_file *cf)
{
	t_content_file	*tmp;

	tmp = (t_content_file *)cf;
	while (tmp)
	{
		ft_printf("{cyan}Addr{reset}:\t\t%p\n", & tmp);
		ft_printf("{green}Size{reset}:\t\t%u\n", tmp -> size);
		ft_printf("{blue}Capacity{reset}:\t%u\n", tmp -> capacity);
		ft_printf("{red}Line{reset}:\t\t%s\n", tmp -> line);
		tmp = tmp -> next;
	}
}

int	main(int ac, char **av, char **env)
{
	if (!env || !*env)
		return ft_printf("{red}Error{reset}\nNo environment path available\n");
	if (ac != 2)
		return ft_printf("{red}Error{reset}\nWrong arguments count\n");
	if (check_extension_filename(av[1]) == false)
		return ft_printf("{red}Error{reset}\nWrong filename extension\n");
	t_content_file *cf = readfile(av[1]);
	print_content_file(cf);
	return 0;
}
