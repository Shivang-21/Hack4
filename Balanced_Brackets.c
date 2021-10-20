/** Problem Statement
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is balanced if the following conditions are met:

It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO. **/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define N 500
int main()
{
    int n,i,len,flag,top;
    scanf("%d",&n);
    while(n--)
    {
        flag=1,top=-1;
        char s[1000],stack[N],ch;
        scanf("%s",s);
        len=strlen(s);
        if(len%2!=0)
        flag=0;
        else
        {
            for(i=0;i<len;i++)
            {
                if(s[i]=='{' || s[i]=='(' || s[i]=='[')
                {
                    top+=1;
                    if(top==(len/2))
                    {
                        flag=0;
                        break;
                    }
                    stack[top]=s[i];
                }        
                else
                {
                    
                    if((stack[top]+1!=s[i]) && (stack[top]+2!=s[i]))
                    {
                        flag=0;
                        break;
                    }
                    top-=1;                    
                }    
            }    
        }        
        if(flag==0 || top!=-1)
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}
