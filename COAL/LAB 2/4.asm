[org 0x100]
mov ax, [Array]
mov bx, [Array+2]
add ax, bx
mov bx, [Array+4]
add ax, bx
mov bx, [Array+6]
add ax, bx
mov bx, [Array +8]
add ax, bx
mov bx, [Array+10]
add ax, bx
mov bx, [Array+12]
add ax, bx
mov bx, [Array+14]
add ax, bx
mov bx, [Array+16]
add ax, bx
mov bx, [Array+18]
add ax, bx
mov bx, [Array+20]
add ax, bx
mov bx, [Array+22]
add ax, bx
mov [Array+24], ax
mov ax, 0x4c00
int 0x21
Array : dw 111,999,888,888,11,99,88,88,1,9,8,8,0