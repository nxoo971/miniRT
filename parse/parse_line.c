/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:00:34 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/05 03:44:53 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_data(char *s)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	start = i;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	s[i] = 0;
	return (s + start);
}

static
bool	set_color(const char *s, t_color *color)
{
	int *const	ptr = & color -> r;
	int			nb;
	int			i;

	i = 0;
	while (*s)
	{
		nb = 0;
		while (ft_isdigit(*s))
		{
			nb = (nb * 10) + *s++ - '0';
			if (nb > 255)
				return (false);
		}
		if (i != 2 && *s != ',')
			return (false);
		*(ptr + i++) = nb;
		if (!*s)
			break ;
		s++;
	}
	return (true);
}

bool	fill_ambient_light(char *s, const size_t size, void *ptr)
{
	size_t			act_size;
	t_ambient_light	*al;

	al = (t_ambient_light *)ptr;
	ft_strcpy(al -> identifier, s);
	act_size = ft_strlen(s);
	if (size > act_size + 1)
		s += act_size + 1;
	else
		return (false);
	s = get_data(s);
	al -> ratio = atof(s);
	act_size = ft_strlen(s);
	if (size > act_size + 1)
		s += act_size + 1;
	else
		return (false);
	return (set_color(s, & al -> color));
}

// bool	fill_struct(char *content, void *structure)
// {
	
// }

bool	parse_line(t_content_file *node, t_figure *infos)
{
	// t_fill_infos	func[MAX_PARAMETERS] = {

	// };
	char	*tmp;

	tmp = node -> line;
	tmp = get_data(tmp);
	if (ft_strcmp(tmp, AMBIENT_LIGHT_IDENTIFIER) == 0)
	{
		if (fill_ambient_light(tmp, node -> size, & infos -> ambient_light))
			return (true);
	}
	// ft_printf("%s\n", infos -> ambient_light.identifier);
	return (false);
}
