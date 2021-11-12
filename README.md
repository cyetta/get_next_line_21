# get_next_line_21
Еще один GNL в рамках учебной программы Школы 21 10 волна

Реализованы основная и бонусная часть

Буфер, кол-во считанных данных, дескриптор хранится в струтуре, которая динамически создается
при первом вызове и уничтожается когда прочитан последний символ потока в последнюю строку.

В основной части есть место для оптимизации. Остаток буфера для следуещего вызова GNL
я копирую в начало, это не оптимально. Вместо копирования можно добавить индекс 
текущего указателя в буфере и работать с ним.

В бонусной части для хранения фаловых дескрипторов используется список структур из основной части.
При первом вызове ищется структура с подходящим дескриптором или создается и добавляется в начало,
если не будет найдена. Аналогично как и в основной части при чтении последнего символа в последнюю 
строку структура удаляется из списка. Голова списка хранится в статик переменной GNL.