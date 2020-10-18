
mov EAX,12345678H

//将EAX的低十六位全部置0
MOV AX,0
SUB AX,AX   //substract
XOR AX,AX   //exclusive or
AND AX,0    //and

//将EAX的低8～15位全部置成1
MOV AH,0ffH

//将EAX的高十六位全部置0
AND EAX,0000ffffH


//ESI：源变址寄存器 Source Index
//EDI：目的变址寄存器 Destination Index
//ESP：堆栈寄存器 Stack Pointer
//EBP：堆栈基址寄存器 Base Pointer


//为什么要设置寄存器？
