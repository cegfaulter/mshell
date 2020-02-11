/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:35:57 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/11 21:19:14 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECOGNIZER_H
# define RECOGNIZER_H

# include "../dt/linkedlist/linkedlist.h"
# include "../dt/hash_table/hash_map.h"
# include "../split/ft_split.h"
# include "../print/print.h"
# include <stdlib.h>

typedef struct	s_rec
{
	char		*text;
	t_list		*files;
	t_list		*oper;
}				t_rec;

t_rec			*init_rec();
int				in_set(char c, char *set);
void			switcher(char s, char *ignored);
int				get_operator(t_rec *rec, char *str, int *is_);
int				get_files(t_rec *rec, char *str, char *ignored, int *is_);
int				get_text(t_rec *rec, char *str, char *ignored);
char			*ft_strjoin(char *text, char *s);
char			*ft_strcpy(char *dst, const char *src, int len);
int				ft_strlen(const char *s);
char			*ft_substr(char *str, int len);
t_rec			*init_rec();
void			init_condition(int *cond, int size, char *c);
void			display_data(void *data);
void			print_rec(t_rec *rec);
t_map			*get_cmd_data(char	*str);
t_rec			*get_cdata(t_map *cd, char *key);
void			free_keys(t_list	**keys);
void			free_cmd_data(t_map **cmd_data);
void			free_rec(t_rec **rec);
#endif
