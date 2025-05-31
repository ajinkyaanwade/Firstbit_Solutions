#include <stdio.h>
void main()
{
  int start, end, sum = 0;
  printf("enter start number\n");
  scanf("%d", &start);
  printf("enter end number\n");
  scanf("%d", &end);
  for (int i = start; i <= end; i++)
  {
    int flag = 0;
    if (i == 1)
    {
      flag = 0;
    }
    else
    {
      for (int j = 2; j < i; j++)
      {
        if (i % j == 0)
        {
          flag = 1;
        }
      }
      if (flag == 0)
      {
        sum = sum + i;
      }
    }
  }
  printf("The sum of prime numbers between %d and %d is %d", start, end, sum);
}
// enter start number
// 1
// enter end number
// 10
// The sum of prime numbers between 1 and 10 is 17