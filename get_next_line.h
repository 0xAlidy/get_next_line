/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 19:56:43 by alidy        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 19:57:03 by alidy       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;

}				t_gnl;

t_gnl			*ft_lstnew(int fd, t_gnl **liste);
t_gnl			*recup_maillon(int fd, t_gnl **liste);
int				rm_lst(int fd, t_gnl **lst);
int				ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char s2[BUFFER_SIZE], int limit);
char			*ft_strdup(char *s1);
int				ft_strlen(char *s);
char			*ft_remove(char *current);
int				get_next_line(int fd, char **line);

#endif
