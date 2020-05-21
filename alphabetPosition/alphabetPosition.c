#include <stdlib.h> // malloc
#include <stdio.h> // stdio
#include <string.h> // strdup

/*
** Given a string, replace every letter with its position in the alphabet.
** If anything in the text isn't a letter, ignore it and don't return it.
**
** CLARIFICATIONS
** 
*/

int	measure_textlen(char *text)
{
  int ret;

  ret = 0;
  while (*text != '\0')
    {
      if (('A' <= *text && *text <= 'Z') || ('a' <= *text && *text <= 'z'))
	{
	  ret += (((*text | 32) - 'a') > 9) ? 2 : 1;
	  ret++;
	}
      text++;
    }
  return (ret);
}

char	*alphabet_position(char *text)
{
  char	*text_cpy;
  int	len;
  int	it;
  int	letter_pos;

  if (!text)
    return (0);
  text_cpy = text;
  it = 0;
  len = measure_textlen(text_cpy);
  if (len == 0)
    {
      text = (char*)malloc(1);
      text[0] = '\0';
      return text;
    }
  if (!(text = (char*)malloc((len))))
    return (""); 
  while (len > (it + 1))
    {
      if (('A' <= *text_cpy && *text_cpy <= 'Z') ||
	  ('a' <= *text_cpy && *text_cpy <= 'z'))
	{	
	  letter_pos = (*text_cpy | 32) - ('a' - 1);
	  if (letter_pos > 9)
	    text[it++] = (letter_pos / 10) + '0';
	  text[it++] = (letter_pos % 10) + '0';
	  text[it] = (it == (len -1)) ? '\0' : ' ';
	  it++;
	}
      text_cpy++;
    }
  return text;
}

int	main()
{
  char *text = "a,b,c,d,... z";
  printf("|%s|", alphabet_position(text));
  return (0);
}
