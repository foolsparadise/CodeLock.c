## CodeLock.c 关于  
代码涉及 pthread_mutex_lock 线程互斥锁    
线程调用该函数让互斥锁上锁，如果该互斥锁已被另一个线程锁定和拥有，则调用该线程将阻塞，直到该互斥锁变为可用为止。    
使用场景：比如 基于链表的push和pop这类操作时，先锁接着你懂的然后解锁      
支持操作系统 Support Linux,Mac,iOS,Android System    
## Usage 使用方法  
```  
 init:  
    CODELOCK ListLock;   //链锁  
    CreateCodeLock(&ListLock);  
 and:  
 CodeLock(&ListLock);  
 //do something like 比如 基于链表的push和pop这类操作时，先锁接着你懂的然后解锁  
 CodeUnlock(&ListLock);  
```  
## MIT  
