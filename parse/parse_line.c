/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:00:34 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/04 01:25:47 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "content_file.h"
# include "figure.h"

char	*get_identifier(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	while (!ft_isspace(s[i]))
		i++;
	s[i] = 0;
	return (s);
}

bool	fill_ambient_light(char *s, t_ambient_light *al)
{
	ft_strcpy(al -> identifier, s);
	ft_printf("%s: %s => %s\n", "fill_ambient_light", s, al -> identifier);
	ft_printf("%s\n", s + ft_strlen(s) + 1);
	return (true);
}

bool	parse_line(t_content_file *node, t_infos *infos)
{
	char	*tmp;

	tmp = node -> line;
	get_identifier(tmp);
	if (ft_strcmp(tmp, AMBIENT_LIGHT_IDENTIFIER) == 0)
		fill_ambient_light(tmp, & infos -> ambient_light);
	else
		return (false);
	return (true);
}