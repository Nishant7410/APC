#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char ch[30];
cin.getline(ch,30);
int k=-1;
int c=0;
int flag=0;
for(int i=0;ch[i]!='\0';i++)
{
    if(ch[i]==32)
    {

       flag=0;
    }
    else{

        if(flag==0)
            c++;
        flag=1;

    }
}
flag=0;
int p=0;
for(int i=0;ch[i]!='\0';i++)
{
    if(ch[i]==32||ch[i+1]=='\0')
    {

       if(flag==1)
       {p++;
       if(p==c&&ch[i+1]=='\0')
        ch[++k]=ch[i];
        else if(ch[i]==32&&p==c)
            flag=0;
       else
       {
           int space=0;
           for(int z=i;ch[z]!='\0';z++)
           {
            if(ch[z]!=32)
                break;
            space++;}

            if(space<4)
            {
        for(int z=0;z<4-space;z++)
        {
          char temp;
          int count=strlen(ch);
          temp=ch[count];
          for(int q=strlen(ch);q>i+space+z;q--)
                ch[q]=ch[q-1];
          ch[count+1]=temp;
        }
            ch[++k]='0';
           ch[++k]='x';
           ch[++k]='2';
           ch[++k]='0';
           i=i+3;
            }
            else
            {
                ch[++k]='0';
           ch[++k]='x';
           ch[++k]='2';
           ch[++k]='0';
           i=i+space-1;
            }

       }

       }
       flag=0;
    }
    else{

      ch[++k]=ch[i];
        flag=1;

    }
}
ch[++k]='\0';
cout<<ch;
}
