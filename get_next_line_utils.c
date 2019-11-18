#include "get_next_line.h"

/*              Liste               */

t_gnl	*recup_maillon(int fd, t_gnl **liste)
{
    t_gnl   *maillon;
    t_gnl   *tmp;

	maillon = *liste;
    if (maillon)
        while (maillon)
        {
            tmp = maillon->next;
            if (fd == maillon->fd)
                return (maillon);
            maillon = tmp;
        }
	maillon = ft_lstnew(fd, liste);
    return (maillon);
}

t_gnl	*ft_lstnew(int fd, t_gnl **liste)
{
	t_gnl	*maillon;

	if (!(maillon = malloc(sizeof(t_gnl))))
		return (0);
	maillon->fd = fd;
	maillon->content = 0;
	maillon->next = *liste;
    *liste = maillon;
	return (maillon);
}

/*              MAIN                */

int     ft_strjoin_s(char **content, char *buffer)
{
    int     size_r;
    int     size_b;
    int     i;
    int     y;
    char    *res;

    size_r = ft_strlen(*content);
    size_b = ft_strlen(buffer);
    i = 0;
    y = -1;
  	if(!(res = malloc((size_r + size_b + 1) * sizeof(char))))
		return (-1);
    if (*content)
        while((*content)[i])
        {
            res[i] = (*content)[i];
            i++;
        }
    while(buffer[++y])
        res[i + y] = buffer[y];
    res[i + y] = 0;
    free(*content);
    *content = res;
    return (0);
}

int     ft_remove(char **current)
{
    int     i;
    int     y;
    char    *res;
    int     size;

    i = 0;
    size = ft_strlen(*current);
    y = 0;
    while ((*current)[i] != '\n')
        i++;
    while ((*current)[i] == '\n')
        i++;
    if(!(res = malloc((size - i + 1) * sizeof(char))))
		return (-1);
    res[size - i] = 0;
    while (i + y < size)
    {
        res[y] = (*current)[i + y];
        y++; 
    }
    free(*current);
    *current = res;
    return (0);
}

int     ft_lecture(int fd, char *buffer, char **current)
{
    int				i;
	int				lecture;
    int             res;

	i = -1;
	lecture = 1;
    res = BUFFER_SIZE;
	if (*current)
		while((*current)[++i])
			if ((*current)[i] == '\n')
				lecture = 0;
	if (lecture == 1)
	{
		if(!(res = read(fd, buffer, BUFFER_SIZE)))
			return(-1);
		if((ft_strjoin_s(current, buffer)) == -1)
			return (-1);
	}
    return (res);
}

int     ft_fill(char **line, char *current, int size)
{
    int i;

    i = 0;
    if(!(*line = malloc(size * sizeof(char))))
			return (-1);
	(*line)[size] = 0; 
	while (current[i] && current[i] != '\n')
    {
		(*line)[i] = current[i];
        i++;
    }
    return (1);
}


int		ft_strlen(char *str)
{
	int i;

	i = 0;
    if (str)
    {
        while(str[i])
		    i++;
    }
	return (i);
}