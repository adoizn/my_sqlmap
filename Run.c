/*
** ����: Xiaomo.wabzsy 
** �汾: v0.3 
** ����ʱ��: 2012/08/14 
** ��������빫��,�����������޸�,����. 
** �������Ϊ������ʲô��Ҫ�Ľ��ĵط��뷢 E-mail�� xiaomo@wabzsy.com ,лл.
*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
int main()
{
	//system("mode con cols=128 lines=32");
	int Last;
	char szFilePath[MAX_PATH],Cmd[MAX_PATH],Line[MAX_PATH];
	FILE * File;
	time_t t;
	while(1)
	{
		memset(Cmd,0,sizeof(Cmd));
		memset(Line,0,sizeof(Line));
		GetModuleFileName(NULL,szFilePath,MAX_PATH);
		Last=strrchr(szFilePath,'\\');
		szFilePath[Last-(int)szFilePath]='\0';
		GetShortPathName(szFilePath,Cmd,sizeof(Cmd));
		strcat(Cmd,"\\Bin\\SqlMap.exe ");
		printf("[root@Hacker~]# Sqlmap ");
		strcat(Cmd,gets(Line));
		time(&t);
		File=fopen(".\\Run.log","a");
		fprintf(File,"\n%sSqlmap %s\n",ctime(&t),Line);
		fclose(File);
		//printf("%s",Cmd);
		system(Cmd);
	}
	system("pause");
	return 0;
}
