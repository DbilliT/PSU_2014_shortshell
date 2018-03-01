/*
** my_unsetenv.c for my_unsetenv in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Nov 22 14:36:06 2014 Pierre Bechade
** Last update Sun Nov 30 15:10:30 2014 Pierre Bechade
*/

#include "my.h"

t_env	*sub_env(t_env *list, char *valeur)
{
  t_env	*tmp;
  t_env	*previous;

  if (list == NULL)
    return (list);
  previous = list;
  if (my_strcmp(previous->str, valeur) == 0)
    {
      list = previous->next;
      free(previous);
      return (list);
    }
  tmp = previous->next;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->str, valeur) == 0)
	{
	  previous->next = tmp->next;
	  free(tmp);
	  return (list);
	}
      previous = tmp;
      tmp = tmp->next;
    }
  return (list);
}

int	check_unsetenv(char **tab)
{
  if (tab[1] == NULL || tab[2] != NULL)
    {
      my_putstr("Fail to unsetenv : Usage : unsetenv env\n");
      return (-1);
    }
  return (0);
}

int	my_unsetenv(char **tab, t_env **envp)
{
  char	*cmp;
  int	i;
  t_env	**unset;

  i = -1;
  unset = envp;
  if (check_unsetenv(tab) == -1)
    return (0);
  while (*unset != NULL)
    {
      cmp = my_xmalloc(sizeof(char) * 4096);
      while ((*unset)->str[++i] != '=')
	cmp[i] = (*unset)->str[i];
      cmp[i] = '\0';
      i = -1;
      if (my_strcmp(cmp, tab[1]) == 0)
	{
	  (*envp) = sub_env((*envp), (*unset)->str);
	  return (0);
	}
      free(cmp);
      unset = &(*unset)->next;
    }
  my_putstr("Can't unset, that env doesn't exist\n");
  return (0);
}
