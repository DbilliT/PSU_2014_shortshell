/*
** tools3.c for tools3 in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Nov 21 17:53:45 2014 Pierre Bechade
** Last update Thu Nov 27 14:20:25 2014 Pierre Bechade
*/

#include "my.h"

void	*my_xmalloc(int size)
{
  void	*tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      write(2, "Error malloc\n", 13);
      exit(0);
    }
  return (tmp);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	size;

  i = 0;
  if (my_strlen(s1) > my_strlen(s2))
    size = my_strlen(s2);
  else
    size = my_strlen(s1);
  while (size >= 0)
    {
      if (s1[i] > s2[i] && s2[i] != '*')
	return (s1[i] - s2[i]);
      if (s1[i] < s2[i] && s2[i] != '*')
	return (s1[i] - s2[i]);
      i++;
      size--;
    }
  return (0);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  dest = my_xmalloc(sizeof(char) * (my_strlen(src) + 1));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
