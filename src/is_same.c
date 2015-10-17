/*
** is_same.c for hmake
**
** Made by glastis
**
** Last update Sat Oct 17 19:14:11 2015 glastis
*/

#include <string.h>
#include "../include/fa.h"

int	is_same(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (strlen(str1) != strlen(str2))
    return (0);
  while (str1[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (0);
      i = i + 1;
    }
  return (1);
}

int	is_matching(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' && str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (0);
      i = i + 1;
    }
  return (1);
}
