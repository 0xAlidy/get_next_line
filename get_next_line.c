#include "get_next_line.h"

int		gnl(int fd, char *buffer, char **line, t_gnl *current)
{
	int		i;
	int		res;

	i = 0;
	if((res = ft_lecture(fd, buffer, &(current->content))) == -1)
		return (-1);
	while ((current->content)[i] && (current->content)[i] != '\n')
		i++;
	if((current->content)[i] == '\n')
	{
		if(!(ft_fill(line, current->content, i)))
			return (-1);
		if ((current->content)[i])
			if((ft_remove(&(current->content))) == -1)
				return (-1);
	}
	else if ((current->content)[i] == 0 && res < BUFFER_SIZE)
	{
		if(!(ft_fill(line, current->content, i)))
			return (-1);
		return (0);
	}
	else 
		return(gnl(fd, buffer, line, current));
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*current;
	char			*buffer;
	int				res;

	if (!fd || !line || BUFFER_SIZE < 1)
		return (-1);
	if(!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	buffer[BUFFER_SIZE] = 0;
	if(!(current = recup_maillon(fd, &lst)))
		return (-1);
	res = gnl(fd, buffer, line, current);
	printf("line return :%s\n",*line);
	free(buffer);
	return (res);
}

int main()
{  
    int		fd;
	char	*line;
	int 	res;

	res = 1;
	if((fd = open("test", 'r')) == -1)
		return (-1);
	while (res != 0)
	{
		res = get_next_line(fd,&line);
	}
    return (0);
}
