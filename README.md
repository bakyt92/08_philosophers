# 08_philosophers

##### Ресурсы

Около 30 видео про создание threads, их использованию, отличию от процессов (главное найти плейлист целиком, а не первое видео)
_https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=2_

Книга 
head-first-c-o-reilly-david-grifffiths-dawn-griffiths.pdf (читать разделы про threads)

Видео https://youtu.be/IKG1P4rgm54
Кратко обсуждается, чем отличаются процессы от потоков. Внутри процесса можно сделать несколько потоков. 
При создании процесса - дублируются все переменные (но они не могут взаимодействовать между собой), при потоках - все потоки могут иметь доступ к общим переменным. 

Race Conditions - когда разные потоки работают с одними и теми же переменными, это приводит к определенным ошибкам - например второй поток получает 
доступ к тем же переменным, в то время как первый поток уже обработал их (например увеличил), в итоге второй поток считывает старую переменную и работает с ней.

##### Разбираемся с кодом

mutex - своего рода защита кода от исполнения другими потоками.

NAME
pthread_join -- wait for thread termination (ожидает завершения потока)

SYNOPSIS
\#include <pthread.h>

     int
     pthread_join(pthread_t thread, void **value_ptr);

DESCRIPTION
The pthread_join() function suspends execution of the calling thread
until the target thread terminates unless the target thread has already
terminated.

     On return from a successful pthread_join() call with a non-NULL value_ptr
     argument, the value passed to pthread_exit() by the terminating thread is
     stored in the location referenced by value_ptr.  When a pthread_join()
     returns successfully, the target thread has been terminated.  The results
     of multiple simultaneous calls to pthread_join() specifying the same tar-
     get thread are undefined.  If the thread calling pthread_join() is can-
     celled, then the target thread is not detached.

RETURN VALUES
If successful, the pthread_join() function will return zero.  Otherwise,
an error number will be returned to indicate the error.

     pthread_detach -- detach a thread

SYNOPSIS
\#include <pthread.h>

     int pthread_detach(pthread_t thread);

DESCRIPTION
The pthread_detach() function is used to indicate to the implementation that storage
for the thread thread can be reclaimed when the thread terminates.  If thread has not
terminated, pthread_detach() will not cause it to terminate.  The effect of multiple
pthread_detach() calls on the same target thread is unspecified.

Прим. Как правило, вызывается внутри функции.

RETURN VALUES
If successful, the pthread_detach() function will return zero.  Otherwise an error
number will be returned to indicate the error.  Note that the function does not
change the value of errno as it did for some drafts of the standard.  These early
drafts also passed a pointer to pthread_t as the argument.  Beware!

NAME
usleep -- suspend thread execution for an interval measured in microseconds

LIBRARY
Standard C Library (libc, -lc)

SYNOPSIS
\#include <unistd.h>

     int usleep(useconds_t microseconds);

DESCRIPTION
The usleep() function suspends execution of the calling thread until either
microseconds microseconds have elapsed or a signal is delivered to the thread and its
action is to invoke a signal-catching function or to terminate the process.  System
activity or limitations may lengthen the sleep by an indeterminate amount.

     This function is implemented using nanosleep(2) by pausing for microseconds microsec-
     onds or until a signal occurs.  Consequently, in this implementation, sleeping has no
     effect on the state of process timers, and there is no special handling for SIGALRM.
     Also, this implementation does not put a limit on the value of microseconds (other
     than that limited by the size of the useconds_t type); some other platforms require
     it to be less than one million.

NOTE
The usleep() function is obsolescent.  Use nanosleep(2) instead.

RETURN VALUES
The usleep() function returns the value 0 if successful; otherwise the value -1 is
returned and the global variable errno is set to indicate the error.

##### Видео Moscow EDU
https://www.youtube.com/watch?v=Bhv2ChKDeio&t=362s
Через pthread_join можно дождаться других потоков, что они выдадут. 
Они равноправные, без подчиненности. 
Проект philosophers - направлен на то, как пользоваться потоками.

