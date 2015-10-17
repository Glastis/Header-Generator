/*
** add_function.c for hmake
**
** Made by glastis
**
** Last update Sat Oct 17 19:18:21 2015 glastis
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "../include/fa.h"

static int	before_p(char *str)
{
  int		i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
    ++i;
  while (str[i] != '(' && str[i] != '{' && str[i])
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	return (0);
      ++i;
    }
  return (1);
}

void	print_function(char *str)
{
  int	i;
  int	open_p;
  int	writed;
  int	flag;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n' && str[i + 1] && is_func(&str[i + 1]))
	{
	  writed = 0;
	  flag = 0;
	  ++i;
	  open_p = 0;
	  while ((str[i] != '\n' || open_p != 0) && str[i] != '{')
	    {
	      if (str[i] == '(')
		++open_p;
	      else if (str[i] == ')')
		--open_p;
	      if (flag == 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && before_p(&str[i]))
		{
		  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		    ++i;
		  --i;
		  if (writed < 8)
		    {
		      printf("\t\t\t");
		      writed = 8;
		    }
		  else if (writed < 16)
		    {
		      printf("\t\t");
		      writed = 16;
		    }
		  else if (writed < 24)
		    {
		      printf("\t");
		      writed = 24;
		    }
		  flag = 1;
		}
	      else
		{
		  printf("%c", str[i]);
		  ++writed;
		}
	      ++i;
	    }
	  printf(";\n");
	}
      ++i;
    }
}

char	*get_src(char *path)
{
  int	fd;
  char	*src;
  int	i;
  int	r;

  r = 0;
  fprintf(stderr, "Opening %s\n", path);
  if ((fd = open(path, O_RDONLY)) <= 0)
    {
      fprintf(stderr, "%sFailed to open %s%s\n", RED, path, WHITE);
      return (NULL);
    }
  if ((src = malloc(READ_SIZE + 1)) == NULL)
    {
      fprintf(stderr, "%sFailed to get %s:Malloc failed%s\n", RED, path, WHITE);
      return (NULL);
    }
  while ((i = read(fd, &src[r], READ_SIZE)) > 0)
    {
      r = r + i;
      if ((src = realloc(src, r + READ_SIZE + 1)) == NULL)
	{
	  fprintf(stderr, "%sFailed to get %s:Malloc failed%s\n", RED, path, WHITE);
	  return (NULL);
	}
    }
  src[r] = '\0';
  close(fd);
  return (src);
}

int	add_function(char *path, char *hpath)
{
  char	*raw;

  if ((raw = get_src(path)) == NULL)
    {
      free(path);
      path = NULL;
      return (-1);
    }
  print_function(raw);
  fprintf(stderr, "Writed %s%s%s'functions into %s%s%s\n", GREEN, path, WHITE, GREEN, hpath, WHITE);
  free(raw);
  free(path);
  path = NULL;
  return (0);
}
