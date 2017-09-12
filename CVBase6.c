#include<stdio.h>
#include<math.h>
int sumofdigit(int num)
{
    long digit, sum = 0;
    while (num > 0)
    {
        digit = num % 10;
        sum  = sum + digit;
        num /= 10;
    }
    return sum;
}

int inversion(int a[], int n)
{
  int i,j,c = 0;
  for (i = 0; i < n - 1; i++)
    for (j = i+1; j < n; j++)
      if (a[i] > a[j])
        c++;

  return c;
}
int baseSix(int a[],int b[],int n)
{
    int i,num,remainder,res,base;
    for(i=0;i<n;i++)
    {
        num=a[i];
        res=0;base=1;
        while (num > 0)
        {
            remainder = num % 6;
            res = res + remainder * base;
            num = num / 6;
            base = base * 10;
        }
        b[i]=sumofdigit(res);
    }
    printf("%d",inversion(b, n));
    return 0;
}
int main()
{
    int i,n, a[50], b[50];
    char ch;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%c",&a[i],&ch);
    }
    baseSix(a,b,n);
  return 0;
}
