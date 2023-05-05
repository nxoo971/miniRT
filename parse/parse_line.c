/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:00:34 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/06 01:33:45 by jewancti         ###   ########.fr       */
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
bool	set_color(const char *s, int * const ptr)
{
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

static
char	*set_vector(char *s, float * const ptr)
{
	const size_t	size = ft_strlen(s);
	size_t			act_size;
	char			*find;
	int				i;

	i = 0;
	while (i < 3)
	{
		find = ft_strchr(s, ',');
		if (!find && i != 2)
			return (NULL);
		if (i != 2)
			*find = 0;
		*(ptr + i) = atof(s);
		act_size = ft_strlen(s);
		if (size > act_size + 1)
			s += act_size + 1;
		else
			return (NULL);
		i++;
	}
	return (s);
}

bool	fill_struct(char *content, const size_t size, void * const ptr)
{
	size_t	act_size;

	content = get_data(content);
	if (ft_strcmp((char *)ptr, AMBIENT_LIGHT_IDENTIFIER) == 0) {
		*(float *)(ptr + sizeof(t_color) + sizeof(float)) = atof(content); // ratio
		act_size = ft_strlen(content);
		if (size > act_size + 1)
			content += act_size + 1;
		else
			return (false);
		return (set_color(content, ptr + sizeof(char [3]) + 1));
	}
	if (ft_strcmp((char *)ptr, CAMERA_IDENTIFIER) == 0) {
		content = set_vector(content, ptr + sizeof(t_vector));	//viewpoint
		if (!content)
			return (false);
		content = get_data(content);
		content = set_vector(content, ptr + sizeof(t_vector) * 2); // orientation
		*(float *)(ptr + sizeof(t_vector) * 3) = atof(content);
		return (true);
	}
	return (true);
}

static
int	get_index_from_identifier(const char *identifier)
{
	const char * const identifiers[MAX_PARAMETERS] = {
		AMBIENT_LIGHT_IDENTIFIER, CAMERA_IDENTIFIER, LIGHT_IDENTIFIER,
		SPHERE_IDENTIFIER, PLAN_IDENTIFIER, CYLINDRE_IDENTIFIER
	};
	int	i;

	i = 0;
	while (i < MAX_PARAMETERS)
	{
		if (ft_strcmp(identifier, identifiers[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

bool	parse_line(t_content_file *node, t_figure *infos)
{
	void * const addrs[MAX_PARAMETERS] = {
		& infos -> ambient_light,
		& infos -> camera,
		& infos -> light,
		& infos -> sphere,
		& infos -> plan,
		& infos -> cylindre,
	};
	char	*tmp;
	size_t	act_size;
	int		index;

	tmp = node -> line;
	tmp = get_data(tmp);
	index = get_index_from_identifier(tmp);
	if (index == -1)
		return (false);
	ft_strcpy((char *)addrs[index], tmp);
	act_size = ft_strlen(tmp);
	if (node -> size > act_size + 1)
		tmp += act_size + 1;
	return (fill_struct(tmp, node -> size, addrs[index]));
}
