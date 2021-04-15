#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

TCHAR FileMappingName[] = TEXT("AIDA64_SensorValues");
LPSTR pBuf;

char* getData()
{
    HANDLE hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, FileMappingName);
    if (hMapFile == NULL)
    {
        printf("open error :(%d)", GetLastError());
        return NULL;
    }
    pBuf = (LPSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (pBuf == NULL)
    {
        printf("Could not map view of file :(%d)", GetLastError());
        CloseHandle(hMapFile);
        return NULL;
    }
    LPSTR pbuf1 = (LPSTR)malloc(strlen(pBuf)+1);
    if (pbuf1 == NULL) {
        printf("Could not allocate memory!");
        CloseHandle(hMapFile);
        UnmapViewOfFile(pBuf);
        return NULL;
    }
    strcpy_s(pbuf1, strlen(pBuf) + 1, pBuf);
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
    return pbuf1;
}
void freebuffer(char* data)
{
    free(data);
    return;
}