#include<stdio.h>
#include<string.h>
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
                    top++;
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
                    top--;                    
                }    
            }    
        }        
        if(flag==0)
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}
