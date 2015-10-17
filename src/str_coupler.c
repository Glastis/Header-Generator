/*
** str_coupler.c for hmake
**
** Made by glastis
**
** Last update Sat Oct 17 19:13:38 2015 glastis
*/

#include <string.h>
#include <stdlib.h>
#include "../include/fa.h"

char	*str_coupler(char *str1, char *str2)
{
  char	*newstr;
  int	i;
  int	ii;

  i = 0;
  ii = 0;
  if ((newstr = malloc((strlen(str1) + strlen(str2)) + 1 * sizeof(char)))
      == NULL)
    malloc_error();
  while (str1 != NULL && str1[i] != '\0')
    {
      newstr[i] = str1[i];
      i = i + 1;
    }
  while (str2 != NULL && str2[ii] != '\0')
    {
      newstr[i] = str2[ii];
      i = i + 1;
      ii = ii + 1;
    }
  newstr[i] = '\0';
  return (newstr);
}
