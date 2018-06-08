//
//  CodeLock.h
//
//  Created by github.com/foolsparadise on 17-8-20.
//
//

#ifndef CodeLock_h
#define CodeLock_h

#include <pthread.h>

#define CODELOCK        pthread_mutex_t

void CreateCodeLock(CODELOCK* pLock);

void DestoryCodeLock(CODELOCK* pLock);

void CodeLock(CODELOCK* pLock);

void CodeUnlock(CODELOCK* pLock);

#endif
