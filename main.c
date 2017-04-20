#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define toDigit(c) (c-'0')
#define toChar(c) (c+'0')

int n1, n2,prodlen;
char number1[6000000];
char sum[6000000];
char power[6000000];
char product[6000000];

int groupDigits(char *num);
void printNumber(char* number, int nrOfDigits);
void interchange(char *num1,char *num2, int nrOfDigits);
int addition(char *num1,char *num2, int len1, int len2);
void multiplication(char* num1,char* num2);
void substractOne(char number, int length);
void setZero();
int my_power(char* num1, int p);

int main()
{
    int i,p=2,j;
    char number2[1];
    power[0]=number1[0]=number2[0]=1;
    for(i=1;i<=25;i++)
    {
        printf("%d: ",i);
        if(i==1)
        {
            printf("1\n");
        }
        else
        {
            my_power(number1,p);
            j=addition(power,number2,prodlen,0);
            printNumber(sum,j);
            n2=j;
            printf("\n");
            for(;j>=0;j--)
            {
                number1[j]=sum[j];
            }
            power[0]=1;
            n1=0;
        }
    }
    return 0;
}
int groupDigits(char *number)
{
    int i;
    int j;
    int n;
    n=strlen(number);
    if(n%2==0)
    {
        i=0;
    }
    else
    {
        i=1;
        number[0]-='0';
    }
    for(j=i;i<n-1;i+=2,j++)
    {
        number[j]=(toDigit(number[i])*10)+toDigit(number[i+1]);
    }
    for(i=j;i<n;i++)
    {
        number[i]=0;
    }
    return j-1;
}

int addition(char *num1, char *num2, int len1, int len2)
{
    char carry=0;
    int aux;
    int i1=len1;
    int i2=len2;
    int k;
    int n;
    if(i1>=i2)
    {
        k=i1;
    }
    else
    {
        if(i2>i1)
        {
            k=i2;
        }
    }
    n=k;
    for(;i1>=0 && i2>=0;i1--,i2--,k--)
    {
        aux=num1[i1]+num2[i2]+carry;
        if(aux>=100)
        {
            sum[k]=aux%100;
            carry=aux/100;
        }
        else{
            sum[k]=aux;
            carry=0;
        }
    }
    while(i1>=0)
    {
        sum[k]=num1[i1]+carry;
        if(sum[k]>=100)
        {
            carry=sum[k]/100;
            sum[k]%=100;
        }
        else{
            carry=0;
        }
        i1--;
        k--;
    }
    while(i2>=0)
    {
        sum[k]=num2[i2]+carry;
        if(sum[k]>=100)
        {
            carry=sum[k]/100;
            sum[k]%=100;
        }
        else{
            carry=0;
        }
        i2--;
        k--;
    }
    if(carry!=0)
    {
        sum[k]=carry;
        n--;
    }
    return n;
}

void printNumber(char* number, int nrOfDigits)
{
    int i;
    for(i=0;i<=nrOfDigits;i++)
    {
        if(i!=0 && number[i]<10)
        {
            printf("0");
        }
        printf("%d",number[i]);
    }
}

void interchange(char *num1,char *num2, int nrOfDigits)
{
    char aux;
    int i;
    for(i=0;i<=nrOfDigits;i++)
    {
        aux=num1[i];
        num1[i]=num2[i];
        num2[i]=aux;
    }
}

void multiplication (char* num1,char* num2)
{
   char carry=0;
   char auxProduct[6000000];
   int aux;
   int i1;
   int i2;
   int x=0;
   int k;
   int k1;
   setZero();
   prodlen=n1+n2+2;
   for(i2=n2;i2>=0;i2--)
   {
       k=prodlen-x;
       for(k1=0;k1<prodlen-n1;k1++)
       {
           auxProduct[k1]=0;
       }
       carry=0;
       for(i1=n1;i1>=0;i1--)
       {
           aux=num1[i1]*num2[i2]+carry;
           if(aux>=100)
           {
                auxProduct[k]=aux%100;
                carry=aux/100;
                k--;
           }
           else
           {
               carry=0;
               auxProduct[k]=aux;
               k--;
           }
       }
       if(carry!=0)
       {
           auxProduct[k]=carry;
       }
       addition(product,auxProduct,prodlen,prodlen);
       x++;
       interchange(sum,product,prodlen);
       for(i1=prodlen,k1=0;k1<x;k1++,i1--)
       {
           auxProduct[i1]=0;
       }
   }
   for(i1=0;product[i1]==0;i1++);
   interchange(product+i1,product,prodlen);
   prodlen-=i1;

}

int my_power(char* number1, int p)
{
    int i;
    strset(product,0);
    if(p>0)
    {
        multiplication(power,number1);
        for(i=0;i<=prodlen;i++)
        {
            power[i]=product[i];
        }
        n1=prodlen;
        my_power(number1,p-1);
    }
    return 0;
}

void setZero()
{
    int i;
    for(i=0;i<=prodlen;i++)
    {
        product[i]=0;
    }
}


