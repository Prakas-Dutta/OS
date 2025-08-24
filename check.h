#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dirent.h>
int i,j;
char *uid,*passwd,*s4;
void check1(char *uid)
{
	int flag=0;
	i=0;
	s4=(char *)calloc(100,sizeof(char));
	FILE *p;
	p=fopen("uid.dtls","r");
	if(p==NULL)
	printf("No file found!!!");
	while(fgets(s4,100,p))
	{
		i++;
		if(!strcmp(uid,s4))
		{
			flag=1;
			free(s4);
			fclose(p);
			break;
		}
	}
	if(flag==0)
	i=-1;
	fclose(p);
}
void check2(char *pwd)
{
	int flag=0;
	j=0;
	s4=(char *)calloc(100,sizeof(char));
	FILE *p;
	p=fopen("passwd.dtls","r");
	if(p==NULL)
	printf("No file found!!!");
	while(fgets(s4,100,p))
	{
		j++;
		if(!strcmp(pwd,s4))
		{
			flag=1;
			free(s4);
			fclose(p);
			break;
		}
	}
	if(flag==0)
	j=-2;
	fclose(p);
}
void logup()
{
	char c;
	int i=0;
	uid=(char *)calloc(100,sizeof(char));
	printf("Set user id...");
	gets(uid);
	FILE *p;
	p=fopen("uid.dtls","a");
	while((c=uid[i++])!='\n' && c!='\0')
	putc(c,p);
	putc('\n', p);
	fclose(p);
	mkdir(uid);
	chdir(uid);
	s4=(char *)calloc(100,sizeof(char));
	printf("Set password for user id %s...",s4);
	gets(s4);
	i=0;
	p=fopen("..\\passwd.dtls","a");
	while((c=s4[i++])!='\n' && c!='\0')
	putc(c,p);
	putc('\n', p);
	fclose(p);
	free(s4);
}
void login()
{
	char c;
	uid=(char *)calloc(100,sizeof(char));
	passwd=(char *)calloc(100,sizeof(char));
	printf("Enter user id...");
	gets(uid);
	uid[strlen(uid)]='\n';
	if(!strcmp(uid,"logup\n"))
	{
		free(uid);
		logup();
		i=j=1;
	}
	else
	{
		printf("Enter password...");
		while((c=getch())!=10 && c!=13)
		{
			if(c==8)
			{
				i--;
				printf("\b \b",0);
				continue;
			}
			passwd[i++]=c;
			printf("*");
		}
		passwd[i]='\n';
		check1(uid);
		check2(passwd);
		uid[strlen(uid)-1]='\0';
		chdir(uid);
		free(passwd);
	}
}
