#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;
void Push(char c)
{
    if(top==MAX-1)
    {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top]=c;
}

char Pop()
{
    if(top==-1)
    {
        printf("Stack underflow.\n");
        return -1;
    }
    return stack[top--];
}

char Peek()
{
    if(top==-1)
        return -1;
    return stack[top];
}

int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
         return 1;
        case '*':
        case '/':
         return 2;
        case '(':
        return 0;
    }
    return -1;
}

int associativity(char op)
{
    if(op=='^')
        return 1;
    return 0;
}

void infixTOPostfix(char infix[],char postfix[])
{
    int i,k=0;
    char c;
    for (i=0;infix[i]!='\0';i++)
    {
        c=infix[i];
        if(isalnum(c))
        {
            postfix[k++]=c;
        }
        else if(c=='(')
        {
            Push(c);
        }
        else if(c==')')
        {
            while (Peek()!='(')
            {
                postfix[k++]=Pop();
            }
            Pop();
        }
        else
        {
            while (top!=-1 && ((precedence(Peek())>precedence(c)) || (precedence(Peek())==precedence(c) &&associativity(c)==0)))
            {
                postfix[k++]=Pop();
            }  
        Push(c);
        }
    }
    while (top!=-1)
    {
        postfix[k++]=Pop();
    }
    postfix[k]='\0';
}

int main()
{
    char infix[MAX],postfix[MAX];
    printf("Enter a valid parenthesized infix expression:");
    scanf(" %s",infix);
    infixTOPostfix(infix,postfix);
    printf("Postfix expression: %s\n",postfix);
    return 0;
}