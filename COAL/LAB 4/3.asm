




[org 0x0100]

jmp start
roll_no: dw 1798
mask1: dw 0x0F0F
mask2: dw 0xF0F0

swap1:
push ax
push bx
push cx
push dx

mov ax,[roll_no]
mov bx,[roll_no]
and ax,[mask1]
shl ax,4
and bx,[mask2]
shr bx,4


or ax,bx


pop dx
pop cx
pop bx
pop ax


ret


start: 
call swap1

mov ax,0x4c00
int 21h


