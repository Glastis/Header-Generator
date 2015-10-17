/*
** is_func.c for hmake
**
** Made by glastis
**
** Last update Sat Oct 17 19:15:07 2015 glastis
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/fa.h"

void	print_line(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '{' && str[i])
    {
      fprintf(stderr, "%c", str[i]);
      ++i;
    }
  fprintf(stderr, "\n");
}

int	is_func(char *str)
{
  int	i;
  int	open_p;
  int	close_p;

  open_p = 0;
  close_p = 0;
  i = 0;
  if (str[i] == '\n' || str[i] == ' ' || str[i] == '\0'  || str[i] == '\t' ||
      str[i] == '#' || str[i] == '/' || str[i] == '*' || is_matching(str, "static "))
    return (0);
  while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
    {
      if (str[i] == '(' || str[i] == ')' || str[i] == '{'  || str[i] == '}' ||
	  str[i] == '=' || str[i] == '+' || str[i] == '\'' || str[i] == '\"')
	return (0);
      ++i;
    }
  while (str[i] != '{' && str[i])
    {
      if (str[i] == '=' || str[i] == '+' || str[i] == '\'' || str[i] == '\"' || str[i] == ';')
	return (0);
      ++i;
    }
  --i;
  while ((str[i] == '\n' || str[i] == ' ' || str[i] == '\t') && i > 0)
    --i;
  while (((str[i] != '\t' && str[i] != ' ' && str[i] != '\n') || (open_p != close_p)) && i > 0)
    {
      if (str[i] == '(')
	++open_p;
      else if (str[i] == ')')
	--open_p;
      --i;
    }
  if ((i == 0 && open_p != 0) || str[i + 1] == '(')
    return (0);
  ++i;
  while (str[i] && str[i] != '{')
    {
      if (str[i] == ';' || str[i] == '=' || str[i] == '+' || str[i] == '"' || str[i] == '\'')
	return (0);
      else if (str[i] == '(')
	++open_p;
      else if (str[i] == ')')
	++close_p;
      ++i;
    }
  if (open_p == 0 || close_p == 0 || (close_p != open_p))
    return (0);
  /* print_line(str); */
  return (1);
}
