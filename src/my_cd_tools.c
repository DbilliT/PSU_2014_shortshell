/*
** my_cd_tools.c for my_cd_tools.c in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Nov 30 15:27:39 2014 Pierre Bechade
** Last update Sun Nov 30 15:39:09 2014 Pierre Bechade
*/

#include "my.h"

char	*my_strcat_cd(char *dest, char *src, int k)
{
  int	i;
  int	j;
  char	*new;

  (1) ?((void)k, i = 0, j = 0) : (0);
  new = my_xmalloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i = i + 1;
    }
  if (k == 0)
    {
      new[i] = '/';
      i = i + 1;
    }
  while (src[j] != '\0')
    {
      new[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  new[i] = '\0';
  return (new);
}

int	my_env_cmp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && j == 0)
    {
      if (s1[i] != s2[i])
        j = 1;
      i = i + 1;
    }
  if (j != 0)
    return (-1);
  else
    return (0);
}

char	*my_find_str(t_env **list, char *str)
{
  t_env	*cpy;

  cpy = *list;
  while ((my_env_cmp(str, cpy->str)) != 0 && cpy->next != NULL)
    {
      cpy = cpy->next;
    }
  if (my_env_cmp(str, cpy->str) != 0)
    return (NULL);
  return (cpy->str);
}

char	*my_create_pwd(char *pwd, char *chm, int k, int r)
{
  int	i;
  char	*tmp;

  tmp = my_xmalloc(sizeof(char) * (my_strlen(pwd) + k ) + 1);
  tmp[my_strlen(pwd) + k] = '\0';
  i = 0;
  while (pwd[i] != '\0')
    {
      tmp[i] = pwd[i];
      i = i + 1;
    }
  while (chm[r] != '\0')
    {
      tmp[i] = chm[r];
      i = i + 1;
      r = r + 1;
    }
  return (tmp);
}

int	my_aff_err(char *data)
{
  my_putstr(data);
  my_putstr(": No such file or directory\n");
  return (0);
}
