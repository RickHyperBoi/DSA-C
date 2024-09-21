#include <stdio.h>
#include <string.h>

#define MAX 1000

Char stack_arr[MAX]; 
Char result_arr[MAX]; 
Int top = -1; 
Int index1 = -1; 

Int isOperand(char c) {
    Return ( (c >= ‘a’ && c <= ‘z’) || (c >= ‘A’ && c <= ‘Z’) || (c >= ‘0’ && c <= ‘9’) );
}

Void push(char data) {
    If (index1 == MAX – 1) {
        Printf(“Stack overflow\n”);
    } else {
        Stack_arr[++index1] = data;
    }
}

Char pop() {
    If (index1 == -1) {
        Printf(“Stack underflow\n”);
        Return ‘\0’; 
    } else {
        Return stack_arr[index1--];
    }
}

Int precedence(char a) {
    If (a == ‘^’)             return 3;
    If (a == ‘*’ || a == ‘/’) return 2;
    If (a == ‘+’ || a == ‘-‘) return 1;
    Else                      return 0;
}

Void infixToPostfix(char ch[]) {
    Int len = strlen(ch);
    For (int I = 0; I < len; i++) {
        Char symbol = ch[i];

        If (isOperand(symbol)) 
        { 
            Result_arr[++top] = symbol;
        } 
        Else if (symbol == ‘(‘ || symbol == ‘[‘ || symbol == ‘{‘) 
        {
            Push(symbol);
        } 
        Else if (symbol == ‘)’ || symbol == ‘]’ || symbol == ‘}’) 
        {
            While (index1 != -1 && stack_arr[index1] != ‘(‘ && stack_arr[index1] != ‘[‘ && stack_arr[index1] != ‘{‘) 
            {
                Result_arr[++top] = pop();
            }
            If (index1 != -1) 
            {
                Pop(); 
            }
        } 
        Else 
        { 
            While (index1 != -1 && precedence(stack_arr[index1]) >= precedence(symbol)) 
            {
                Result_arr[++top] = pop();
            }
            Push(symbol);
        }
    }

 
    While (index1 != -1) {
        Result_arr[++top] = pop();
    }
    Result_arr[++top] = ‘\0’; 
}
Void display() {
    Printf(“Postfix expression: “);
    For (int I = 0; I <top; i++) 
    {
        Printf(“%c”, result_arr[i]);
    }
    Printf(“\n”);
}
void main() {
    char ch[MAX];
    printf(“Enter the infix expression: “);
    scanf(“%s”, ch);
    infixToPostfix(ch);
    display();
}

