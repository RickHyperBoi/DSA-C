#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 100
struct stack{
	int top;
	int result[max];
}s;
int pwr(int a,int b)
{
	int k;
	for(k=1;k<=b;k++)
	{
		a=a*a;
	}
	return a;
}
void calc(char symbol)
{
	int a,b;
	b=pop();
	printf("first:%d\n",b);
	a=pop();
	printf("second:%d\n",a);
	printf("Symbol:%c\n",symbol);
	switch(symbol)
	{
		case '+':
		push(a+b);
		break;
		case '-':
		push(a-b);
		break;
		case '*':
		push(a*b);
		break;
		case '/':
		push(a/b);
		break;
		case '^':
		push(pwr(a,b));
		break;
		default:
		printf("Invalid");
	}
}
void postfixeval(char postf[])
{
	int i,len,n;
	len=strlen(postf);
	for(i=0;i<len;i++)
	{
	    printf("--%c--\n",postf[i]);
		if(postf[i]>='1' && postf[i]<='9')
		{
		    n=(int)postf[i];
		   // printf("before:%d",n);
           n=n-48;
           //printf("after:%d",n);
			push(n);
			continue;
		}
		else if(postf[i]=='+'||postf[i]=='-'||postf[i]=='*'||postf[i]=='/'||postf[i]=='^')
		{
			calc(postf[i]);
		}
		else
		printf("Invalid character");
	}
}
int isEmpty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}
int isFull()
{
	if(s.top==max-1)
	return 1;
	else
	return 0;
}
void push(int n)
{
	if(isFull()==0)
	{
		s.top++;
		s.result[s.top]=n;
		printf("Pushed %d\n",s.result[s.top]);
	}
	else
	printf("Stack full");
}
int pop()
{
	int n;
	if(isEmpty()==0)
	{
		n=s.result[s.top];
		s.top--;
		return n;
	}
	else
	printf("Stack empty");
}
void display()
{
	printf("%d",s.result[0]);
}
void main(){
	char postf[max];
	s.top=-1;
	printf("Enter the postfix expression: ");
	scanf("%s",postf);
	postfixeval(postf);
	display();
}
