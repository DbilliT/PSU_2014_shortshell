/*
** my_cd.c for my_cd in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Nov 30 15:13:28 2014 Pierre Bechade
** Last update Sun Nov 30 15:30:19 2014 Pierre Bechade
*/

#include "my.h"

int	my_cd_next(t_env **list, char *data)
{
  char	*str;
  char	*tab[3];
  int	i;

  i = 0;
  tab[0] = "vide";
  tab[2] = NULL;
  (data[0] == '.' && data[1] == '.' && data[2] == '\0') ?
    (data = "../") : (0);
  if (data[0] == '-' && data[1] == '\0')
    my_cd_dash(list);
  else if (data_test(data) == 0)
    {
      chdir("/");
      str = my_find_str(list, "PWD=");
      tab[1] = "PWD=/";
      my_setenv(tab, list);
      tab[1] = my_strcat_cd("OLD", str, 1);
      my_setenv(tab, list);
      return (i);
    }
  else
    (chdir(data) == 0) ?
      (my_switch_env(list, data)) : (my_aff_err(data), i = -1);
  return (i);
}

int	my_cd_home(t_env **list)
{
  char	*tab[3];
  char	*str;

  str = my_find_str(list, "PWD=");
  tab[0] = "vide";
  tab[2] = NULL;
  tab[1] = my_strcat_cd("OLD", str, 1);
  my_setenv(tab, list);
  str = my_find_str(list, "HOME=");
  tab[1] = my_strcat_cd("PWD", str + 4, 1);
  my_setenv(tab, list);
  chdir(str + 5);
  return (0);
}

int	my_cd(t_env **list, char **tab_dat)
{
  int	i;

  i = 1;
  if (tab_dat[1] == NULL)
    {
      my_cd_home(list);
    }
  else
    {
      while (tab_dat[i] != NULL)
	{
	  if (my_cd_next(list, tab_dat[i]) == -1)
	    return (-1);
	  i = i + 1;
	}
    }
  return (0);
}
