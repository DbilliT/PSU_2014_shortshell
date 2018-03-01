/*
** my_echo_env.c for my_echo_env in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Nov 28 18:14:00 2014 Pierre Bechade
** Last update Sun Nov 30 15:05:52 2014 Pierre Bechade
*/

#include "my.h"

char	*my_value(char	*str)
{
  char	*new;
  int	i;
  int	j;

  new = my_xmalloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  j = 0;
  while (str[i] != '=')
    i++;
  i++;
  while (str[i])
    {
      new[j] = str[i];
      i++;
      j++;
    }
  new[j] = '\0';
  my_putstr(new);
  my_putchar('\n');
  return (new);
}

char	*find_env(char	*str)
{
  char	*new;
  int	i;

  new = my_xmalloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  while (str[i] != '=')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

void	my_aff_error_echo(char *str)
{
  my_putstr(str);
  my_putstr(": Undefined variable.\n");
}

int	my_echo_env(char **tab, t_env **envp)
{
  t_env	*cpy;
  char	*env;
  char	*value;
  int	i;
  int	j;

  cpy = *envp;
  value = my_xmalloc(sizeof(char) * my_strlen(tab[1]) + 1);
  i = 1;
  j = 0;
  while (tab[1][i])
    value[j++] = tab[1][i++];
  value[j] = '\0';
  while (cpy != NULL)
    {
      env = find_env(cpy->str);
      if (my_strcmp(env, value) == 0)
	{
	  my_value(cpy->str);
	  return (0);
	}
      cpy = cpy->next;
    }
  my_aff_error_echo(value);
  return (-1);
}
