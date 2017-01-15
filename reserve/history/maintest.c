#include "Freelibtest/inc/free.h"

int			main(int __unused argc, char __unused **argv)
{
	int		fd;
	int		ret;
	char	*line;
	t_dlist	**list_history;
	t_dlist	*tmp;

	fd = open("/Users/ariard/.ariard_history", O_RDONLY | O_CREAT, 0644);
	line = 0;
	list_history = ft_memalloc(sizeof(t_dlist));
	*list_history = NULL;
	if (fd < 0)
		ft_putstr("error");
	while ((ret = get_next_line(fd, &line)) > 0)
		ft_list_push_front(list_history, line, line);
	tmp = *list_history;
	while (tmp)
	{
		ft_putstr(tmp->data);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	return (0);
}
