#include"kernel.h"
#include"check.h"
void env()
{
	char cwd[256];
	printf("%s>",getcwd(cwd,sizeof(cwd)));
}
main()
{
	printf("You can log in with the user id and password.\nIf you are new to the system then you can type \"logup\" in user id to set your user id and the password.\n\n");
	login();
	passwd=(char *)calloc(100,sizeof(char));
	strcpy(huid, uid);
	free(uid);
	strcpy(passwd,"cat ..\\about.dtls");
	if(i==j)
	{
		printf("\nLogin successful...\n");
		cat(passwd);
		free(passwd);
		while(true)
		{
			char *s;
			s=(char *)calloc(100,sizeof(char));
			env();
			gets(s);
			if(strcmp(s, ""))
			kernel(s);
			free(s);
		}
	}
	else
	printf("\nSorry, you're not an user of this system!!!\n\
You don't have permission to access this operating system...");
	getch();
}
