#include <iostream>

using namespace std;
void getarray();
void push(char p);
void pop(char po);
int oprand(char o);
int opr(char op);
int hipre(char h);
void display();
void inpost();
const int size=25;
char a[size];
char sta[size];
char postexp[size];
int top=0;
int p=0;
int s;
int main()
{
    getarray();
    display();
    inpost();
    display();
    return 0;
}
void getarray()
{
    cout<<"\nEnter the size of your Infix equation  ";
    cin>>s;
    for(int i=0; i<s; i++)
    {
        cout<<"\nEnter the "<<i<<" expresion of your infix ";
        cin>>a[i];
    }
        a[s+1]=')';
    sta[0]='(';
}
void display()
{
    cout<<"\nthe expression is    ";
    for(int i=0; i<=(s+1); i++)
    {
        cout<<a[i];
    }
    cout<<"\nThe post exp    ";
    for(int i=0; i<=(s+1); i++)
    {
        cout<<postexp[i];
    }
    /*cout<<"\nThe stack exp     ";
    for(int i=0; i<=(s+1); i++)
    {
        cout<<sta[i];
    }*/
}

void inpost()
{

    int temp;
    int j;
    for(int i=0; i<=(s+1); i++)
    {
        if(oprand(a[i]))
        {
            postexp[p]=a[i];
            p++;
        }
        if(a[i]=='(')
        {
            push(a[i]);
        }
        if(opr(a[i]))
        {
            if(opr(sta[top]))
            {
                if(hipre(sta[top])>=hipre(a[i]))
                {
                    postexp[p]=sta[top];
                    sta[top]=a[i];
                    p++;
                }
                else
                {
                    push(a[i]);
                }
            }
            else
            {
                push(a[i]);
            }
        }
        if(a[i]==')')
        {
            temp=1;
            for(j=top;temp>0;j--){
                if(sta[j]=='(')
                   {
                       temp=0;
                }
                   else{
                         postexp[p]=sta[j];
                         sta[j]=' ';
                         top=top-1;
                        p++;
                   }
                }

            if(sta[j]=='(')
            {
                sta[top]=' ';
                top=top-1;
            }
        }
    }
}
void push(char p)
{
    top=top+1;
    sta[top]=p;

}
int oprand(char o)
{
    if((o>='a'&&o<='z')||(o>='0'&&o<='9')||(o>='A'&&o<='Z'))
    {
        return 1;
    }
    return 0;

}
int opr(char op)
{
    if(op=='+'||op=='/'||op=='^'||op=='*'||op=='-'||op=='^')
    {
        return 1;
    }
    return 0;
}
void pop(char po)
{


}
int hipre(char h)
{

    if(h=='^')
    {
        return 3;
    }
    else if(h=='*'||h=='/')
    {
        return 2;
    }
    else if(h=='-'||h=='+')
    {

        return 1;
    }


}
