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

