/*
** get_dir.c for hmake
**
** Made by glastis
**
** Last update Sat Oct 17 19:15:30 2015 glastis
*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "../include/fa.h"

void	malloc_error()
{
  fprintf(stderr, "Malloc failed.\n");
  exit (-1);
}

char	*clone_str(char *str)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    malloc_error();
  while (str[i])
    {
      new[i] = str[i];
      ++i;
    }
  new[i] = '\0';
  return (new);
}

int		get_dir(char *path, char *hpath)
{
  DIR		*acdir;
  char		*tmp;
  struct dirent	*dp;

  if (path[0] == '\0')
    return (-1);
  /* fprintf(stderr, "%s:\n", path); */
  get_c_files(path, hpath);
  acdir = opendir(path);
  while (acdir)
    {
      if ((dp = readdir(acdir)) != NULL && dp->d_type == 4 && is_same(dp->d_name, ".") == 0 && is_same(dp->d_name, "..") == 0 && dp->d_name != NULL)
	{
	  tmp = str_coupler(path, "/");
	  get_dir(str_coupler(tmp, dp->d_name), hpath);
	  free(tmp);
	  tmp = NULL;
	}
      else if (dp == NULL)
	{
	  closedir(acdir);
	  acdir = NULL;
	}
    }
  if (is_same(path, ".") == 0)
    free(path);
  return (0);
}
