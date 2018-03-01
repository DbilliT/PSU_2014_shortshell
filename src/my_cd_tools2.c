/*
** my_cd_tools2.c for my_cd_tools2 in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Nov 30 15:29:10 2014 Pierre Bechade
** Last update Sun Nov 30 15:31:26 2014 Pierre Bechade
*/

#include "my.h"

char	*my_mv_pwd(char *pwd, char *chm,  int i, int j)
{
  int	r;
  int	k;

  k = 0;
  r = i - 1;
  while (chm[i] != '\0')
    {
      i = i + 1;
      k = k + 1;
    }
  i = my_strlen(pwd);
  while (j != 0 && i != 4)
    {
      (pwd[i] == '/') ? (j = j - 1) : (0);
      i = i - 1;
    }
  pwd[i + 1] = '\0';
  pwd = my_create_pwd(pwd, chm, k, r);
  return (pwd);
}

char	*my_catpwd(char *pwd, char *chm)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (chm[0] == '.' && chm[1] == '/')
    chm = chm + 2;
  if (chm[0] == '\0')
    return (pwd);
  while (chm[i] == '.' && chm[i + 1] == '.' && chm[i + 2] == '/')
    {
      j = j + 1;
      i = i + 3;
    }
  if (j == 0)
    pwd = my_strcat_cd(pwd, chm, 0);
  else
    pwd = my_mv_pwd(pwd, chm, i, j);
  return (pwd);
}

int	my_cd_dash(t_env **list)
{
  char	*tab[3];
  char	*tmp;
  char	*str;

  tab[0] = "vide";
  tab[2] = NULL;
  if ((str = my_find_str(list, "OLDPWD=")) == NULL)
    {
      my_putstr("bash: cd: OLDPWD not set\n");
      return (-1);
    }
  else
    {
      my_putstr(str + 7);
      write(1, "\n", 1);
      chdir(str + 7);
      tmp = str + 3;
      str = my_find_str(list, "PWD=");
      tab[1] = my_strcat_cd("OLD", str, 1);
      my_setenv(tab, list);
      tab[1] = tmp;
      my_setenv(tab, list);
    }
  return (0);
}

int	data_test(char *data)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ( data[i] != '\0')
    {
      if (data[i] != '/')
	j = j + 1;
      i = i + 1;
    }
  return (j);
}

void	my_switch_env(t_env **list, char *data)
{
  char	*str;
  char	*tab[3];

  str = my_find_str(list, "PWD=");
  tab[0] = "vide";
  tab[2] = NULL;
  tab[1] = my_strcat_cd("OLD", str, 1);
  my_setenv(tab, list);
  tab[1] = my_catpwd(str, data);
  my_setenv(tab, list);
}
