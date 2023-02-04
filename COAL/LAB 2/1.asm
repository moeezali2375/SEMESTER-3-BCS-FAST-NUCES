[org 0x0100]
mov ax,25h
mov dx,ax
mov bx,5
mov ax,bx
mov bx,dx
mov cx,[0x270]
mov ax,0
mov bx,num
mov al, [bx]
add bx,1
mov al, [bx]
add bx,1
mov al, [bx]
add bx,1


mov ax,0x4c00
int 21h

num:db 12,25,10