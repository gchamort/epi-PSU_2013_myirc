/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sat Apr 12 17:28:23 2014 CHAUCHET Alan
** Last update Sat Apr 12 17:28:24 2014 CHAUCHET Alan
*/

#include <stdio.h>
#include <stdlib.h>

int	count_word(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 32 && str[i] < 127
	  && (str[i + 1] <= 32 || str[i + 1] > 126))
	count++;
      i++;
    }
  return (count);
}

int	size_word(char *str, int nb)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  while (nb > 0 && str[i] != '\0')
    {
      if (str[i] > 32 && str[i] < 127
	  && (str[i + 1] <= 32 || str[i + 1] >= 127))
	nb--;
      i++;
    }
  while ((str[i] <= 32 || str[i] > 126) && str[i] != '\0')
    i++;
  while (str[i] > 32 && str[i] < 127 && str[i] != '\0')
    {
      size++;
      i++;
    }
  return (size);
}

char	*my_fill_tab(char *word, int *a, int *b, char *str)
{
  while ((str[*b] <= 32 || str[*b] > 126) && str[*b] != '\0')
    *b = *b + 1;
  while (str[*b] > 32 && str[*b] < 127 && str[*b] != '\0')
    {
      word[*a] = str[*b];
      *a = *a + 1;
      *b = *b + 1;
    }
  word[*a] = '\0';
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	a;
  int	b;
  int	nb_word;
  char	**word_tab;

  i = 0;
  b = 0;
  nb_word = count_word(str);
  if ((word_tab = malloc(sizeof(char *) * (nb_word + 1))) == NULL)
    return (NULL);
  while (i < nb_word)
    {
      a = 0;
      if ((word_tab[i] = malloc(sizeof(char)
				* (size_word(str, i) + 1))) == NULL)
	return (NULL);
      word_tab[i] = my_fill_tab(word_tab[i], &a, &b, str);
      i++;
    }
  word_tab[i] = NULL;
  return (word_tab);
}
