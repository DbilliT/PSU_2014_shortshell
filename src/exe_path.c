/*
** exe_path.c for exe_path in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Nov 27 14:13:28 2014 Pierre Bechade
** Last update Thu Nov 27 16:53:19 2014 Pierre Bechade
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  j = 0;
  new = my_xmalloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i++;
    }
  new[i] = '/';
  i++;
  while (src[j] != '\0')
    {
      new[i] = src[j];
      j++;
      i++;
    }
  new[i] = '\0';
  return (new);
}

char	*check_path(char **tpath, char **exec)
{
  int	i;
  char	*path;

  i = 0;
  if (exec[0] == NULL)
    return (NULL);
  if (tpath == NULL)
    return (NULL);
  if (access(exec[0], F_OK) == 0)
    return (exec[0]);
  while (tpath[i] != NULL)
    {
      path = my_strcat(tpath[i], exec[0]);
      if (access(path, F_OK) == 0)
	return (path);
      i++;
      free(path);
    }
  return (NULL);
}
