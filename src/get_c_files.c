/*
** get_c_files.c for hmake
**
** Made by glastis
**
** Last update Sat Oct 17 19:15:47 2015 glastis
*/

#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "../include/fa.h"

int	is_c_file(unsigned char type, char *name)
{
  int	i;

  i = 0;
  if (type == 4)
    return (0);
  while (name[i + 1] != '\0')
    ++i;
  if (name[i] == 'c' && name[i - 1] == '.')
    return (1);
  return (0);
}

int		get_c_files(char *path, char *hpath)
{
  DIR		*dir;
  struct dirent	*dp;
  char		*tmp;
  char		*tmp2;

  if ((dir = opendir(path)) == NULL)
    {
      fprintf(stderr, "Can't open %s\n", path);
      return (-1);
    }
  while (dir)
    {
      if ((dp = readdir(dir)) != NULL && is_c_file(dp->d_type, dp->d_name))
	{
	  tmp = str_coupler(path, "/");
	  tmp2 = str_coupler(tmp, dp->d_name);
	  printf("/* In %s */\n", tmp2);
	  free(tmp2);
	  add_function(str_coupler(tmp, dp->d_name), hpath);
	  free(tmp);
	}
      else if (dp == NULL)
	{
	  closedir(dir);
	  dir = NULL;
	}
    }
  return (0);
}
