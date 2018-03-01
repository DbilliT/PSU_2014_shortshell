/*
** my_setenv.c for my_setenv in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Nov 22 16:29:03 2014 Pierre Bechade
** Last update Thu Nov 27 17:49:43 2014 Pierre Bechade
*/

#include "my.h"

int	is_env_exist(char **tab, t_env **envp)
{
  t_env	*cpy;
  char	*tmp;
  char	*cmp;
  int	i;

  i = -1;
  cpy = *envp;
  tmp = my_xmalloc(sizeof(char) * (my_strlen(tab[1]) + 1));
  while (tab[1][++i] != '=')
    tmp[i] = tab[1][i];
  (i != -2) ? tmp[i] = '\0', i = -1 : 0;
  while (cpy != NULL)
    {
      cmp = my_xmalloc(sizeof(char) * (my_strlen(cpy->str) + 1));
      while (cpy->str[++i] != '=')
	cmp[i] = cpy->str[i];
      (i != -3) ? cmp[i] = '\0', i = -1 : 0;
      if (my_strcmp(tmp, cmp) == 0)
	{
	  (*envp) = sub_env(*envp, cpy->str);
	  return (0);
	}
      cpy = cpy->next;
    }
  return (0);
}

int	my_setenv(char **tab, t_env **envp)
{
  int	i;
  int	tmp;

  i = 0;
  tmp = 0;
  if (tab[1] == NULL || tab[2] != NULL)
    {
      my_putstr("Fail setenv : Usage : setenv NAME=value\n");
      return (0);
    }
  while (tab[1][i] != '\0')
    {
      if (tab[1][i] == '=')
	tmp = 1;
      i++;
    }
  if (tmp == 0)
    {
      my_putstr("Bad env name : Usage : NAME=value\n");
      return (0);
    }
  is_env_exist(tab, envp);
  add_end(envp, tab[1]);
  return (0);
}
