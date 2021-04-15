#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib, "..\\cppmmap\\x64\\Debug\\cppmmap.lib")
extern char* getData();
extern void freebuffer(char* data);
int main()
{
	while (1) {
		char* resdata = getData();
		if (resdata != NULL) {
			printf("%s\r\n", resdata);
			freebuffer(resdata);
		}
		else{
			printf("null??\r\n");
		}
	}
	system("pause");
}
