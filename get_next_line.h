/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:36:16 by gcornet-          #+#    #+#             */
/*   Updated: 2021/03/02 10:36:18 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
int			check_has_new_line(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
void		*ft_memmove(void *dst, const void *src, size_t len);

#endif
