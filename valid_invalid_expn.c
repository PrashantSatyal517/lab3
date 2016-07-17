/*To check if a mathematical expression is correct or not
* Author: Prashant Satyal
* Ref: Data structure using c and c++ (pearson) page 82-84
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
	int top;
	char items[MAX];
}stack;

void push(stack *,char);
char pop(stack*);
char opening(char);
int main()
{
	char a[MAX],topop,toopen;
	stack s;
	s.top=-1;
	int i,valid=1;
	
	printf("Enter an equation to check its validity:\n");
	scanf("%s",&a);
	
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='(' || a[i]=='{' || a[i]=='[')
		{
			push(&s,a[i]);
		}
		if (a[i]==')' || a[i]=='}' || a[i]==']')
		{	
			if(s.top==-1)
			{
			valid=0;
			}
			
			else
			{
			topop=pop(&s);
			toopen=opening(a[i]);
			
			
			if(topop!=toopen)
			{
			valid=0;
			}
			
			}
		
		}
		
	}
	
if(!(s.top==-1))
{
	valid=0;
}

if(valid==1)
{
	printf("expression is valid\n");
}

else
{
	printf("expression  is not valid\n");
}
}

void push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}

char pop(stack *s)
{
	return s->items[(s->top)--];
}

char opening(char c)
{
	if(c==')')
	{
		return'(';
	}
	else if(c=='}')
	{
		return'{';
	}
	else if(c==']')
	{
		return'[';
	}
}


