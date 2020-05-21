#include <stdlib.h>
#include <string.h>
#include <stdio.h>
      
void  copyReverseWord(const char *text, char *ret, int text_it, int ret_it)
{
  ret[text_it] = text[text_it];
  text_it--;
  while (!(text[text_it] == ' ' || text_it == -1))
    {
      ret[ret_it] = text[text_it];
      ret_it++;
      text_it--;
    }
}
      
char* reverseWords(const char* text) 
{
  int text_it;
  int ret_it;
  char *ret;
      
  if (!(ret = (char*)malloc(strlen(text) + 1)))
    return 0;
  text_it = 0;
  ret_it = 0;
  while (1)
    {
      if (text[text_it] == ' ')
	{
	  copyReverseWord(text, ret, text_it, ret_it);
	  ret_it = text_it + 1;
	}
      if (text[text_it] == '\0')
	{
	  copyReverseWord(text, ret, text_it, ret_it);
	  return (ret);
	}
      text_it++;
    }
}

int main()
{
  char *string = " a b c  moon river ";
  char *solution = reverseWords(string);

  printf("|%s|", solution);
}
