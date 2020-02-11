/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:50:03 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/11 21:11:26 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char		*ft_substr(char *str, int len)
{
	char	*s;
	int		iter;

	iter = 0;
	s = malloc(sizeof(char) * (len + 1));
	while (iter < len)
	{
		s[iter] = str[iter];
		iter++;
	}
	s[len] = 0;
	return (s);
}

int			ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*ft_strcpy(char *dst, const char *src, int len)
{
	int		iter;

	if (!src)
		return (dst);
	iter = 0;
	while (iter < len)
	{
		dst[iter] = src[iter];
		iter++;
	}
	dst[len] = 0;
	return (dst);
}

char		*ft_strjoin(char *text, char *s)
{
	char	*new_text;
	int		len1;
	int		len2;
	int		iter;

	len1 = (text) ? ft_strlen(text) : 0;
	len2 = (s) ? ft_strlen(s) : 0;
	new_text = malloc(sizeof(char) * (len1 + len2 + 1));
	ft_strcpy(new_text, text, len1);
	if (len1 && len2)
	{
		ft_strcpy(new_text + len1, " ", 1);
		len1++;
	}
	ft_strcpy(new_text + len1, s, len2);
	free(text);
	free(s);
	return (new_text);
}
