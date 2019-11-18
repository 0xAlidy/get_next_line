#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef  struct s_gnl 
{
    int             fd;
    char            *content;
    struct s_gnl    *next; 

}               t_gnl;

int		ft_strlen(char *str);
int		gnl(int fd, char *buffer, char **line, t_gnl *current);
int     ft_strjoin_s(char **current, char *buffer);
int     ft_remove(char **current);
int     ft_lecture(int fd, char *buffer, char **current);
int     ft_fill(char **line, char *current, int size);
t_gnl	*recup_maillon(int fd, t_gnl **liste);
t_gnl	*ft_lstnew(int fd, t_gnl **liste);

#endif