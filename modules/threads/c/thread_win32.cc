#include <windows.h>
#include <stdlib.h>
#include <iostream>

DWORD WINAPI thread_call(void* data)
{
    void** datap = (void**)data;
    
    void*(*datafn)(void*) = (void*(*)(void*))datap[0];
    datafn(datap[1]);
    free(datap);
    return 0;
}

extern "C" {
void* create_thread(void *(*worker)(void *), void *data) {
    void** datap = (void**)malloc(sizeof(void*)*2);
    datap[0] = (void*)worker;
    datap[1] = (void*)data;
    DWORD tid;
    HANDLE* handle = (HANDLE*)malloc(sizeof(HANDLE));
    *handle = CreateThread(0, 0, thread_call, datap, 0, &tid);
    return handle;
}

void close_thread(void* th) {
    HANDLE* thandle = (HANDLE*)th;
    CloseHandle(*thandle);
}
}