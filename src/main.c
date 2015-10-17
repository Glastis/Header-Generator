/*
** main.c for hmake
**
** Made by glastis
**
** Last update Sat Oct 17 19:14:49 2015 glastis
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/fa.h"

static char	*uppercase_str(char *str)
{
  int		i;
  char		*new;

  i = 0;
  if ((new = malloc((strlen(str) + 1) * sizeof(char))) == NULL)
    malloc_error();
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	new[i] = str[i] + 'A' - 'a';
      else if (str[i] == '.')
	new[i] = '_';
      else
	new[i] = str[i];
      ++i;
    }
  new[i] = '\0';
  return (new);
}

static int	create_head(char *path)
{
  int		fd;
  int		i;
  char		*tmp;

  i = 0;
  while (path[i] != '\0')
    ++i;
  while (i > 0 && path[i] != '/')
    --i;
  if (i > 0)
    ++i;
  if ((fd = open(path, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) <= 0)
    {
      fprintf(stderr, "Can't create %s\n", path);
      exit(-1);
    }
  tmp = uppercase_str(&path[i]);
  write(fd, "#ifndef ", strlen("#ifndef "));
  write(fd, tmp, strlen(tmp));
  write(fd, "_\n# define ", strlen("_\n# define "));
  write(fd, tmp, strlen(tmp));
  write(fd, "_\n\n\n#endif /* ! ", strlen("_\n\n\n#endif /* ! "));
  write(fd, tmp, strlen(tmp));
  write(fd, "_ */\n", strlen("_ */\n"));
  free(tmp);
  return (fd);
}

int	main(int ac, char **av)
{
  int	fd;

  if (ac <= 1)
    {
      fprintf(stderr, "hmake header_path\n");
      return (-1);
    }
  if (access(av[1], F_OK) < 0)
    {
      fprintf(stderr, "%s don't exist.\n", av[1]);
      fprintf(stderr, "Creating %s\n", av[1]);
      fd = create_head(av[1]);
    }
  close(fd);
  get_dir(".", av[1]);
  return (0);
}
