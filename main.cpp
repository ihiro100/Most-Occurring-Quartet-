#include<stdio.h>
#define limit 1000000
struct para
{
    char word[100];
}s[limit];
struct quartet
{
    int count;
    char word1[50];
    char word2[50];
    char word3[50];
    char word4[50];
}q[limit];
int find(int,char [],char[],char [],char [],int);
void main()
{
    FILE *f;
    int i,j=0,k=0,l=0,m=0,c=0,pos;
    char ch,f_name[20];
    printf("Enter the filename : ");
    gets(f_name);
    f=fopen(f_name,"r");
    if(f==NULL)
    {
        printf("file was'nt detected");
        exit(0);
    }
    ch=fgetc(f);
    while(ch!=EOF)
    {
        if(ch!=' '&&ch!=','&&ch!='?'&&ch!='('&&ch!=')'&&ch!='!'&&ch!='.'&&ch!='['&&ch!=']'&&ch!='{'&&ch!='}'&&ch!=':'&&ch!=';'&&ch!='\n')
        s[j].word[k++]=tolower(ch);
        else
        {
            if(k!=0)
            {
                s[j].word[k]='\0';
                j++;
                k=0;
            }
        }
        ch=fgetc(f);
    }

    if(strcmp(s[j].word,"\0")!=0)
    j++;
    if(j<4)
    {
        printf("No Quartet found\n");
        exit(0);
    }

    for(i=0;i<j-3;i++)
    {
        int flag=0;
        if(m!=0)
        {
            for(k=0;k<m;k++)
            {
                if(strcmp(q[k].word1,s[i].word)==0&&strcmp(q[k].word2,s[i+1].word)==0&&strcmp(q[k].word3,s[i+2].word)==0&&strcmp(q[k].word4,s[i+3].word)==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            c=find(j,s[i].word,s[i+1].word,s[i+2].word,s[i+3].word,i+3);
            if(c>1)
            {
                strcpy(q[m].word1,s[i].word);
                strcpy(q[m].word2,s[i+1].word);
                strcpy(q[m].word3,s[i+2].word);
                strcpy(q[m].word4,s[i+3].word);
                q[m].count=c;
                m++;
            }
        }
    }
    if(m==0)
        printf("NONE OF THE QUARTET IS REPEATED");
    else
    {
        int max=0;
        for(i=0;i<m;i++)
        {
            if(q[i].count>max)
            {
                max=q[i].count;
                pos=i;
            }
        }
        while(l<m)
        {
            if(q[l].count==max)
                printf("%s %s %s %s\n",q[l].word1,q[l].word2,q[l].word3,q[l].word4);
            l++;
        }
    }

    fclose(f);
    getch();
}
int find(int size,char a[],char b[],char c[],char d[],int last_pos)
{
    int i=0,count=1;
    while(i<size-3)
    {
        if(i+3<last_pos-3||i>last_pos)
        {
            //printf("%d %d %d %d\n",i,i+1,i+2,i+3);
            if(strcmp(s[i].word,a)==0&&strcmp(s[i+1].word,b)==0&&strcmp(s[i+2].word,c)==0&&strcmp(s[i+3].word,d)==0)
            {
                count++;
                i=i+4;
            }
            else
                i++;
        }
        else
        i++;
    }
    return count;
}
