// Done by
// Name: Dhruv Rajeshkumar Shah
// Registration number: 21BCE0611

// Q1. Stack Applications
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating a stack struct data type
struct Stack
{
    int top;
    int capacity;
    int *arr;
};

// Function for creating a stack object using the stack struct data type
struct Stack *create_stack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function for pushing an item onto the stack
void push(struct Stack *stack, int item)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function for popping an item off the stack
int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function for checking if a character is an operator
int is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

// Function for checking the precedence of an operator
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// 1. Infix to Postfix
char *infix_to_postfix(char *infix_expression)
{
    char *postfix_expression = (char *)malloc(sizeof(char) * 10);
    struct Stack *stack = create_stack(100);
    int i = 0, j = 0;
    while (infix_expression[i] != '\0')
    {
        if (infix_expression[i] == ' ')
        {
            i++;
            continue;
        }
        if (infix_expression[i] == '(')
        {
            push(stack, infix_expression[i]);
        }
        else if (infix_expression[i] == ')')
        {
            while (stack->arr[stack->top] != '(')
            {
                postfix_expression[j++] = pop(stack);
            }
            pop(stack);
        }
        else if (is_operator(infix_expression[i]))
        {
            if (stack->top == -1 || precedence(infix_expression[i]) > precedence(stack->arr[stack->top]))
            {
                push(stack, infix_expression[i]);
            }
            else
            {
                while (precedence(infix_expression[i]) <= precedence(stack->arr[stack->top]))
                {
                    postfix_expression[j++] = pop(stack);
                }
                push(stack, infix_expression[i]);
            }
        }
        else
        {
            postfix_expression[j++] = infix_expression[i];
        }
        i++;
    }
    while (stack->top != -1)
    {
        postfix_expression[j++] = pop(stack);
    }
    return postfix_expression;
}

// 2. Evaluate Postfix Expression
int evaluate_postfix(char *postfix_expression)
{
    struct Stack *stack = create_stack(100);
    int result;
    int i = 0;
    while (postfix_expression[i] != '\0')
    {
        if (is_operator(postfix_expression[i]))
        {
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            switch (postfix_expression[i])
            {
            case '*':
                result = operand2 * operand1;
                break;
            case '/':
                result = operand2 / operand1;
                break;
            case '+':
                result = operand2 + operand1;
                break;
            case '-':
                result = operand2 - operand1;
                break;
            }
            push(stack, result);
        }
        else
        {
            push(stack, postfix_expression[i] - '0');
        }
        i++;
    }
    return pop(stack);
}

// 3. Balancing symbols
int is_balanced(char *exp)
{
    struct Stack *stack = create_stack(100);
    int i = 0;
    while (exp[i] != '\0')
    {
        switch (exp[i])
        {
        case '(':
        case '[':
        case '{':
            push(stack, exp[i]);
            break;
        case ')':
            if (pop(stack) != '(')
            {
                return 0;
            }
            break;
        case ']':
            if (pop(stack) != '[')
            {
                return 0;
            }
            break;
        case '}':
            if (pop(stack) != '{')
            {
                return 0;
            }
            break;
        default:
            break;
        }
        i++;
    }
    if (stack->top != -1)
    {
        return 0;
    }
    return 1;
}

void menu(int opt)
{
    switch (opt)
    {
    // 1
    case 1:
        char *infix_expression = (char *)malloc(sizeof(char) * 100);
        printf("Enter an infix exp: ");
        scanf("%[^\n]%*c", infix_expression);
        char *postfix_expression_result = infix_to_postfix(infix_expression);
        printf("Postfix exp : %s\n", postfix_expression_result);
        break;

    // 2
    case 2:
        char *postfix_expression = (char *)malloc(sizeof(char) * 100);
        printf("Enter a postfix exp: ");
        scanf("%[^\n]%*c", postfix_expression);
        int result = evaluate_postfix(postfix_expression);
        printf("Result : %d\n", result);
        break;

    // 3
    case 3:
        char *exp = (char *)malloc(sizeof(char) * 100);
        printf("Enter an exp: ");
        scanf("%[^\n]%*c", exp);
        if (is_balanced(exp))
        {
            printf("Expression is balanced\n");
        }
        else
        {
            printf("Expression is not balanced\n");
        }
        break;
    }
}

// Main function for taking input and displaying output!
int main()
{
    int opt;
    printf("Select the option from the menu-\n");
    printf("1. Infix to Postfix\n");
    printf("2. Evaluation Postfix Expression\n");
    printf("3. Balancing symbols\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);
    getchar();
    menu(opt);
    return 0;
}