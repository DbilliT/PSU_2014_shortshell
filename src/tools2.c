/*
** tools2.c for tool2 in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Nov 27 14:18:47 2014 Pierre Bechade
** Last update Thu Nov 27 16:50:10 2014 Pierre Bechade
*/

#include "my.h"

int	compt_word(char *str)
{
  int	i;
  int	compteur;

  i = 0;
  compteur = 0;
  while (str[i] == ' ')
    i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' && (str[i + 1] != ' ' || str[i + 1] == '\0'))
        {
          compteur = compteur + 1;
          i = i + 1;
        }
      i = i + 1;
    }
  return (compteur + 1);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && n > 0)
    {
      dest[i] = src[i];
      i++;
      n--;
    }
  if (n != 0)
    dest[i] = '\0';
  return (dest);
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  (1) ? i = 0, j = 0, k = 0 : 0;
  tab = my_xmalloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str[i])
    {
      while (str[i] == c && str[i] != '\0')
        i++;
      if (str[i] != c && str[i] != '\0')
        {
          j = i;
          while (str[i] != c && str[i] != '\0')
            i++;
          tab[k] = my_xmalloc(sizeof(char) * (my_strlen(str) + 1));
          my_strncpy(tab[k], &str[j], (i - j));
          k++;
        }
      else
        i++;
    }
  tab[k] = NULL;
  return (tab);
}

int	compt_path(char *str)
{
  int	i;
  int	compteur;

  i = 0;
  compteur = 0;
  while (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' ||
	 str[i] == 'H' || str[i] == '=')
    i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] == ':' && (str[i + 1] != ':' || str[i + 1] == '\0'))
        {
          compteur = compteur + 1;
          i = i + 1;
        }
      i = i + 1;
    }
  return (compteur);
}

char	**my_path_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  (1) ? i = 5, j = 0, k = 0 : 0;
  tab = my_xmalloc(sizeof(char *) * (compt_path(str) + 2));
  while (str[i])
    {
      while (str[i] == ':' && str[i] != '\0')
        i++;
      if (str[i] != ':' && str[i] != '\0')
        {
          j = i;
          while (str[i] != ':' && str[i] != '\0')
            i = i + 1;
          tab[k] = my_xmalloc(sizeof(char) * (i - j));
          my_strncpy(tab[k], &str[j], (i - j));
          k++;
        }
      else
        i++;
    }
  tab[k] = NULL;
  return (tab);
}
