/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_helper2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:23:45 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/11 21:15:03 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

int			get_operator(t_rec *rec, char *str, int *is_)
{
	int		iter;
	int		i;
	char	c;

	i = 0;
	iter = 0;
	while (str[i] == ' ')
		i++;
	if (in_set(str[i], "><"))
	{
		c = str[i];
		iter = 1;
		while (str[i + iter] == c)
			iter++;
		append(&rec->oper, ft_substr(str + i, iter));
		is_[0] = 1;
	}
	return (i + iter);
}

int			get_files(t_rec *rec, char *str, char *ignored, int *is_)
{
	int		i;
	int		iter;

	i = 0;
	while (str[i] == ' ' && !*ignored)
		i++;
	iter = 0;
	while ((str[i + iter] != ' ' || *ignored) && str[i + iter])
	{
		if (in_set(str[i + iter], "\"'"))
			switcher(str[i + iter], ignored);
		iter++;
	}
	append(&rec->files, ft_substr(str + i, iter));
	i += iter;
	is_[0] = 0;
	return (i);
}

int			get_text(t_rec *rec, char *str, char *ignored)
{
	int		i;
	int		iter;

	i = 0;
	while (str[i] == ' ')
		i++;
	iter = 0;
	while ((str[i + iter] != ' ' || *ignored) && str[i + iter])
	{
		if (in_set(str[i + iter], "\"'"))
			switcher(str[i + iter], ignored);
		iter++;
	}
	if (iter > 0)
		rec->text = ft_strjoin(rec->text, ft_substr(str + i, iter));
	else
		rec->text = ft_strjoin(rec->text, NULL);
	i += iter;
	return (i);
}

int			in_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

void		switcher(char s, char *ignored)
{
	if (*ignored == s)
		*ignored = 0;
	else if (!(*ignored))
		*ignored = s;
}
