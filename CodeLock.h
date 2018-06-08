//
//  CodeLock.h
//
//  Created by github.com/foolsparadise on 17-8-20.
//
//

#ifndef CodeLock_h
#define CodeLock_h

#include <pthread.h>

/*
 usage:
 init:
    CODELOCK ListLock;   //链锁
    CreateCodeLock(&ListLock);
 and:
 CodeLock(&ListLock);
 //do something like 比如 基于链表的push和pop这类操作
 CodeUnlock(&ListLock);
 */

#define CODELOCK        pthread_mutex_t

void CreateCodeLock(CODELOCK* pLock);

void DestoryCodeLock(CODELOCK* pLock);

void CodeLock(CODELOCK* pLock);

void CodeUnlock(CODELOCK* pLock);

#endif
