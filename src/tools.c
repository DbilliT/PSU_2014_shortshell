/*
** tools.c for tools in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Nov 27 14:21:02 2014 Pierre Bechade
** Last update Thu Nov 27 14:21:03 2014 Pierre Bechade
*/

#include "my.h"

int	is_path(char *env)
{
  int	i;
  char	*path;

  path = "PATH=";
  i = 0;
  while (env[i] == path[i] && path[i] != '\0')
    i++;
  if (path[i] == '\0')
    return (1);
  else
    return (0);
}

char	*get_path(t_env *env)
{
  while (env != NULL && is_path(env->str) == 0)
    env = env->next;
  if (env == NULL)
    {
      my_putstr_e("No path found\n");
      return (NULL);
    }
  return (env->str);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
