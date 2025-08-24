//This handles the function given by a command
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>
#include<stdalign.h>
#include<assert.h>
#include<ctype.h>
#include<errno.h>
#include<float.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
#include<setjmp.h>
#include<signal.h>
#include<stdarg.h>
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iso646.h>
#include<wchar.h>
#include<wctype.h>
#include<complex.h>
#include<fenv.h>
#include<inttypes.h>
#include<stdbool.h>
#include<stdint.h>
#include<tgmath.h>
#include<dirent.h>
#include<sched.h>
#include<semaphore.h>
char *s1,*s2,*s3;
void error(char*);
void oserror()
{
	printf("Error:Not support any argument!!!");
}
void trim1(int i, char *s)
{
	uint8_t flag=0;
	uint16_t j=0;
	uint16_t k;
	s1=(char *)calloc(100,sizeof(char));
	for(k=0;k<strlen(s);k++)
	{
			if(!flag && (isalnum(s[k])||s[k]=='.'||s[k]=='"'))
			flag=1;
			if(flag)
			{
				s1[j]=s[k];
				j++;
			}
	}
	for(j=0;i<strlen(s1);i++,j++)
	s1[j]=s1[i];
	s1[j]='\0';
}
void trim2(int i, char *s)
{
	trim1(i,s);
	uint8_t flag=0;
	uint16_t j=0;
	s2=(char *)calloc(100,sizeof(char));
	for(i=0;i<strlen(s1);i++)
	{
		if(!flag && (isalnum(s1[i])||s1[i]=='.'))
		flag=1;
		if(flag && (s1[i]!=' '|| s1[i+1]!=' '))
		{
			s2[j]=s1[i];
			j++;
		}
	}
	if(s2[j-1]==' ')
	j--;
	s2[j]='\0';
	free(s1);
}
void args(char *s)
{
	s2=(char *)calloc(100,sizeof(char));
	uint16_t i=0,j=0;
	while(s[i]!='"')
	i++;
	i++;
	while(s[i]!='"')
	s2[j++]=s[i++];
}
void ex(char *s)//to exit the terminal
{
	trim2(0,s);
	if(!strcmp(s2,"exit"))
	exit(0);
	else
	oserror();
	free(s2);
}
void echo(char *s)//to print message
{
	trim1(5,s);
//	uint16_t i=0;
//	while(s1[i]!='"' && s1[i]!='\0')
//	i++;
//	if(s1[i]=='"')
//	{
//		args(s1);
//		printf("%s",s2);
//	}
//	else
	puts(s1);
	free(s1);
//	free(s2);
}
//void print(char *s)//print a series of number
//{
//	int st,f;
//	st=atoi(&s[0]);
//	f=atoi(&s[strlen(s)-1]);
//	for(int i=st;i<=f;i++)
//	printf("%d",i);
//}
void ct(char *s)//get the current time
{
	trim2(0,s);
	if(!strcmp(s2,"ct"))
	{
		struct tm* ptr;
	    time_t t;
	    t = time(NULL);
	    ptr = localtime(&t);
	    printf("%s", asctime(ptr));
	}
	else
	oserror();
	free(s2);
}

//directory related function
void pwd(char *s)//says the absolute path
{
	trim2(0,s);
	if(!strcmp(s2,"pwd"))
	{
		char *cwd;
		cwd=(char *)calloc(256,sizeof(char));
		printf("%s",getcwd(cwd,sizeof(cwd)));
		free(cwd);
	}
	else
	oserror();
	free(s2);
}
void cd(char *s)//change directory
{
	trim1(3,s);
	int i=0;
	while(s1[i]!='"' && s1[i]!='\0')
	i++;
	if(s1[i]=='"')
	args(s1);
	else
	trim2(0,s1);
	if(chdir)
	if(chdir(s2)!=0)
	perror("Error");
	free(s2);
}
void md(char *s)//create directory
{
	trim2(6,s);
	mkdir(s2);
	free(s2);
}
void rd(char *s)//remove any directory
{
	trim2(6,s);
	rmdir(s2);
	free(s2);
}
void vi(char *s)//create file
{
	trim1(3,s);
	int i=0;
//	while(s1[i]!='"' && s1[i]!='\0')
//	i++;
//	if(s1[i]=='"')
//	args(s1);
//	else
	char c;
	trim2(0,s1);
	FILE *p;
	p=fopen(s2,"w");
	while((c=getchar())!=4)
	putc(c,p);
//	putc(c,p);
	fclose(p);
}
void cat(char *s)//show a file content
{
	trim2(4,s);
	FILE *f;
	f=fopen(s2,"r");
	char c;
	while((c=getc(f))!=EOF)
	{
		printf("%c",c);
		if(!strcmp(s2,"..\\about.dtls"))
		usleep(1500);
	}
	if(!strcmp(s2,"..\\about.dtls"))
	sleep(2);
	fclose(f);
	free(s2);
}
void rm(char *s)//remove any file
{
	trim2(3,s);
	if(remove(s2)!=0)
	printf("No such file exists");
	free(s2);
}
void rnm(char *s)//renmae a file or directory
{
	int i=0,j=0;
	trim2(4,s);
	s1=(char *)calloc(100,sizeof(char));
	s3=(char *)calloc(100,sizeof(char));
	while(s2[i]!=' ')
	s1[i]=s2[i++];
	s1[i]='\0';
	i++;
	while(s2[i]!='\0')
	s3[j++]=s2[i++];
	s3[j]='\0';
	if(rename(s1,s3)!=0)
	perror("Error");
	free(s1);
	free(s2);
	free(s3);
}
void mv(char *s)//move a file or directory
{
	trim2(3,s);
	s1=(char *)calloc(100,sizeof(char));
	s3=(char *)calloc(100,sizeof(char));
	int i=0,j=0;
	while(s1[i]!=' ')
	s2[j++]=s1[i++];
	i++,j=0;
	while(s1[i]!='\0')
	s3[j++]=s1[i++];
	FILE *p;
	
	p=fopen(s1,"r");
	free(s1);
	free(s3);
}
void touch(char *s)//create a null file
{
	trim2(6,s);
	FILE *p;
	p=fopen(s2,"w");
	fclose(p);
}
void ls(char *s) {
    char *s2 = strdup(s);  // Assuming trim2 modifies s2
    trim2(0, s2);          // You should define trim2 properly

    if (strcmp(s2, "ls") == 0) {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd failed");
            free(s2);
            return;
        }

        DIR *p = opendir(cwd);
        if (!p) {
            perror("opendir failed");
            free(s2);
            return;
        }

        struct dirent *d;
        int i = 1;
        while ((d = readdir(p)) != NULL) {
            printf("%d) %s\n", i++, d->d_name);
        }

        closedir(p);
    } else {
        oserror();  // Assuming this is defined elsewhere
    }

    free(s2);
}
void clear(char *s)//clear screen
{
	trim2(0,s);
	if(!strcmp(s2,"clear"))
	printf("\e[1;1H\e[2J");
	else
	oserror();
	free(s2);
}
void clr(char *s)//to set the font color of console
{
	trim2(4,s);
	int i=atoi(s2);
	if(i<=15 && i>=0)
	{
		if(i<=7)
		printf("\e[%dm",i+30);
		else
		printf("\e[%dm",i+82);
	}
	else
	printf("Enter a valid number");
	free(s2);
}
void bkclr(char *s)//it change the background color of the font
{
	trim2(6,s);
	int i=atoi(s2);
	if(i<=15 && i>=0)
	{
		if(i<=7)
		printf("\e[%dm",i+40);
		else
		printf("\e[%dm",i+92);
	}
	else
	printf("Enter a valid number");
	free(s2);
}
void bold(char *s)
{
	trim2(0,s);
	if(!strcmp(s2,"bold"))
	printf("\e[1m");
	else
	oserror();
	free(s2);
}
void italic(char *s)
{
	trim2(0,s);
	printf("%s",s2);
	if(!strcmp(s2,"italic"))
	printf("\e[3m");
	else
	oserror();
	free(s2);
}
void undrln(char *s)
{
	trim2(0,s);
	if(!strcmp(s2,"undrln"))
	printf("\e[4m");
	else
	oserror();
	free(s2);
}
void smpl(char *s)
{
	trim2(0,s);
	if(!strcmp(s2,"smpl"))
	printf("\e[0m");
	else
	oserror();
	free(s2);
}
void error(char *s)//error message, if no command is found
{
	int i=0;
	s1=(char *)calloc(100,sizeof(char));
	while(s[i]!=' ' && s[i]!='\0')
	s1[i]=s[i++];
	s1[i]='\0';
	printf("\a\'%s\' is not an internal or external command!!!\a",s1);
	free(s1);
}
void help()
{
	FILE *f;
	char c;
	f=fopen("..\\help.dtls", "r");
	while((c=getc(f))!=EOF)
	putc(c, stdout);
	fclose(f);
}
