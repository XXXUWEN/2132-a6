//
//  main.c
//  2132 a6
//
//  Created by xuwen nie on 16/3/23.
//  Copyright © 2016年 xuwen nie. All rights reserved.
//

#include <stdio.h>

#define STACK_MAX 20
#define number 200


struct Stack {
    int data[STACK_MAX];
    int top;
}operand,operator;


void push(int item,struct Stack *p){
    if(p->top==SIZE_MAX){
        printf("full!");
    }else{
        p->data[++p->top] = item;
    }
}
int pop(struct Stack *p){
    if(p->top==0){
        printf("empty!");
        return 1;
    }else{
        return p->data[p->top--];
    }
}

int main(void){
    char operation[number];
    gets(operation);
    
    //operations push and pop and calculation
    for(int i=0;i<number;i++){
        
        if(operation[i]!='('&&operation[i]!='+'&&operation[i]!='-'&&operation[i]!='*'&&operation[i]!='/'&&operation[i]!=')'){
            struct Stack *p;
            p=&operand;
            int cc=operation[i]-'0';
            while(operation[i+1]>='0'&&operation[i+1]<='9'&&operation[i+1]!='('&&operation[i+1]!=')'){
                cc=cc*10+(operation[i+1]-'0');
                i++;
            }
            push(cc,p);
        }else if(operation[i]=='('||operation[i]==' '){
            
        }else if(operation[i]==')'){
            struct Stack *k;
            k=&operand;
            int a,b,c;
            a=pop(k);
            b=pop(k);
            
            
            struct Stack *j;
            j=&operator;
            int cc = pop(j);
            char ch=cc+'0';

            
            switch (ch) {
                case '+':
                    c=b+a;
                    break;
                case '-':
                    c=b-a;
                    break;
                case '*':
                    c=b*a;
                    break;
                case '/':
                    if(a==0){
                        printf("divisor is 0!");
                        break;
                    }
                    c=b/a;
                    break;
                    
               default:printf("not correct operator!");
                    break;
            }
            push(c,k);
           
        }else{
            struct Stack *p;
            p=&operator;
            int cc=operation[i]-'0';
            push(cc,p);
        }
        if(operation[i+1]==NULL){
            break;
        }
    }
    int answer;
    struct Stack *p;
    p=&operand;
    answer=pop(p);
    printf("%d",answer);
    
    return 0;
}


