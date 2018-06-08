//
//  CodeLock.c
//
//  Created by github.com/foolsparadise on 17-8-20.
//
//

#include "CodeLock.h"
#include <stdio.h>

/*
 
 如果互斥锁类型为 PTHREAD_MUTEX_NORMAL，则不提供死锁检测。尝试重新锁定互斥锁会导致死锁。如果某个线程尝试解除锁定的互斥锁不是由该线程锁定或未锁定，则将产生不确定的行为。
 如果互斥锁类型为 PTHREAD_MUTEX_ERRORCHECK，则会提供错误检查。如果某个线程尝试重新锁定的互斥锁已经由该线程锁定，则将返回错误。如果某个线程尝试解除锁定的互斥锁不是由该线程锁定或者未锁定，则将返回错误。
 如果互斥锁类型为 PTHREAD_MUTEX_RECURSIVE，则该互斥锁会保留锁定计数这一概念。线程首次成功获取互斥锁时，锁定计数会设置为 1。线程每重新锁定该互斥锁一次，锁定计数就增加 1。线程每解除锁定该互斥锁一次，锁定计数就减小 1。 锁定计数达到 0 时，该互斥锁即可供其他线程获取。如果某个线程尝试解除锁定的互斥锁不是由该线程锁定或者未锁定，则将返回错误。
 如果互斥锁类型是 PTHREAD_MUTEX_DEFAULT，则尝试以递归方式锁定该互斥锁将产生不确定的行为。对于不是由调用线程锁定的互斥锁，如果尝试解除对它的锁定，则会产生不确定的行为。如果尝试解除锁定尚未锁定的互斥锁，则会产生不确定的行为。
 
 各种Mutex的区别
 锁类型  初始化方式  加解锁特征  调度特征
 普通锁  PTHREAD_MUTEX_INITIALIZER  同一线程可重复加锁，解锁一次释放锁  先等待锁的进程先获得锁
 嵌套锁  PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP  同一线程可重复加锁，解锁同样次数才可释放锁  先等待锁的进程先获得锁
 纠错锁  PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP  同一线程不能重复加锁，加上的锁只能由本线程解锁  先等待锁的进程先获得锁
 自适应锁  PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP  同一线程可重加锁，解锁一次生效  所有等待锁的线程自由竞争
 
 windows
 只支持嵌套锁
 
 linux
 PTHREAD_MUTEX_FAST_NP  即 普通锁
 PTHREAD_MUTEX_RECURSIVE_NP  即嵌套锁
 PTHREAD_MUTEX_ERRORCHECK_NP  即纠错锁
 
 OS_APPLE || OS_S60 || OS_ANDROID
 PTHREAD_MUTEX_NORMAL  即普通锁
 PTHREAD_MUTEX_RECURSIVE  即嵌套锁
 PTHREAD_MUTEX_ERRORCHECK  即纠错锁
 
 */

#define PTHREAD_MUTEX_FAST_NP       PTHREAD_MUTEX_NORMAL
#define PTHREAD_MUTEX_RECURSIVE_NP  PTHREAD_MUTEX_RECURSIVE
#define PTHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK

void CreateCodeLock(CODELOCK* pLock)
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(pLock, &attr);
    pthread_mutexattr_destroy(&attr);
}

void DestoryCodeLock(CODELOCK* pLock)
{
    pthread_mutex_unlock(pLock);
    pthread_mutex_destroy(pLock);
}

void CodeLock(CODELOCK* pLock)
{
    pthread_mutex_lock(pLock);
}

void CodeUnlock(CODELOCK* pLock)
{
    pthread_mutex_unlock(pLock);
}
