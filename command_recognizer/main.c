/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:05:21 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/11 21:23:38 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

void		display_map(t_map *map)
{
	t_list		*keys;
	t_list		*iter_key;

	keys = get_keys(map);
	iter_key = keys;
	while (iter_key)
	{
		print("key: %s\nvalue: >>>\n", (char *)iter_key->data);
		print_rec(get_cdata(map, (char *)iter_key->data));
		iter_key = iter_key->next;
		print("\n\n");
	}
	free_keys(&keys);
}

int			main(void)
{
	char		*str = "echo blablabla >> file1 makaine maidare > file2 ejdj | grep";
	t_map		*cmd_data;
	t_list		*keys;

	cmd_data = get_cmd_data(str);
	display_map(cmd_data);
	return (0);
}
