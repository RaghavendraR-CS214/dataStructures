#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100
int top = -1;
int stack[SIZE];

void push(int item)
{
    if(top>=SIZE-1)
        printf("stack overflow");
    top++;
    stack[top]=item;
}

int pop()
{
    if(top==-1)
        printf("stack underflow");
        return -1;
    int item = stack[top];
    top--;
    return item;
}

int is_operator(char symbol)
{
    if(symbol=='+'|| symbol=='-'|| symbol=='*' || symbol=='/')
        return -1;
    return 0;
}

int evaluate(char *expression)
{
    int i=0;
    char symbol = expression[i];
    int operand1,operand2,result;
    
    while(symbol != '\0')
    {
        if(symbol>='0' && symbol<='9')
        {
            int num = symbol-'0';
            push(num);
        }
        else if(is_operator(symbol))
        {
            operand2=pop();
            operand1=pop();
            switch(symbol)
            {
                case '+' :result = operand1+operand2; break;
                case '-' :result = operand1-operand2; break;
                case '*' :result = operand1*operand2; break;
                case '/' :result = operand1/operand2; break;
            }
            push(result);
        }
        i++;
        symbol = expression[i];
    }
    result = pop();
    return result;
}

int main() {
    char postfixExp[SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfixExp);

    int result = evaluate(postfixExp);
    printf("Result after evaluation: %d\n", result);

    return 0;
}