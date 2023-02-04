[org 0x100]
mov ax, [n1]
add [sum], ax
mov ax, [n2]
add [sum],ax
mov ax, [n3]
add [sum], ax
mov ax, [n4]
add [sum], ax
mov ax, [n5]
add [sum], ax
mov ax, [sum]
mov ax, 0x4c00
int 0x21
n1: dw 10
n2: dw 20
n3: dw 30
n4: dw 40
n5: dw 50
sum: dw 0;