#include"handler.h"
char *com;
char huid[100];
int is_root()
{
	char cwd[256];
	getcwd(cwd,sizeof(cwd));
	int i, j;
	for(i=strlen(huid), j=strlen(cwd); i>=0; i--, j--)
	if(cwd[j]!=huid[i])
	return 0;
	if(cwd[j]!='\\')
	return 0;
	return 1;
}
void command(char *s)
{
	com=(char *)calloc(100,sizeof(char));
	int i=0,j=0;
	while(s[i]==' ')i++;
	while(s[i]!=' ' && s[i]!='\0')
	com[j++]=s[i++];
}
void kernel(char *s)
{
	command(s);
	trim1(strlen(com)+1, s);
	if(strlen(s1)>1 && s1[0]=='.' && s1[1]=='.' && is_root())
	printf("You are in root directory!!!\n");
	else if(!strcmp(com, "help"))
	help();
	else if(!strcmp(com,"exit"))
	ex(s);
	else if(!strcmp(com,"vi"))
	vi(s);
	else if(!strcmp(com,"mkdir"))
	md(s);
	else if(!strcmp(com,"cat"))
	cat(s);
	else if(!strcmp(com,"rmdir"))
	rd(s);
	else if(!strcmp(com,"rm"))
	rm(s);
	else if(!strcmp(com,"ct"))
	ct(s);
	else if(!strcmp(com,"pwd"))
	pwd(s);
	else if(!strcmp(com,"cd"))
	cd(s);
	else if(!strcmp(com,"echo"))
	echo(s);
	else if(!strcmp(com,"rnm"))
	rnm(s);
	else if(!strcmp(com,"clear"))
	clear(s);
	else if(!strcmp(com,"mv"))
	mv(s);
	else if(!strcmp(com,"bkclr"))
	bkclr(s);
	else if(!strcmp(com,"clr"))
	clr(s);
	else if(!strcmp(com,"italic"))
	italic(s);
	else if(!strcmp(com,"bold"))
	bold(s);
	else if(!strcmp(com,"undrln"))
	undrln(s);
	else if(!strcmp(com,"smpl"))
	smpl(s);
	else if(!strcmp(com,"ls"))
	ls(s);
	else if(!strcmp(com,"touch"))
	touch(s);
	else
	error(s);
	free(com);
	printf("\n");
}
