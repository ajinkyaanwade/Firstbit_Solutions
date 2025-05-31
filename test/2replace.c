#include <stdio.h>
void main()
{
  char str[20];
  printf("enter string\n");
  gets(str);

  char ch, rep;

  printf("enter the character to be replaced\n");
  scanf("%c", &ch);

  fflush(stdin);

  printf("enter the special symbol to replace with\n");
  scanf("%c", &rep);

  for (int i = 0; i < sizeof(str); i++)
  {
    if (str[i] == ch)
    {
      str[i] = rep;
    }
  }
  printf("%s", str);
}
/*enter string
Ajinkya Anwade
enter the character to be replaced
A
enter the special symbol to replace with
@
@jinkya @nwade
*/