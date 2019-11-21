/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 16:14:42 by alidy        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 19:45:45 by alidy       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*recup_maillon(int fd, t_gnl **liste)
{
	t_gnl	*maillon;
	t_gnl	*tmp;

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

int		rm_lst(int fd, t_gnl **lst)
{
	t_gnl	*maillon;

	maillon = *lst;
	if (maillon->fd == fd)
	{
		*lst = maillon->next;
		free(maillon);
		return (0);
	}
	else
		return (rm_lst(fd, &(maillon->next)));
}

int		ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
		{
			if (s[i] == c)
				return (1);
			i++;
		}
	return (0);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}
