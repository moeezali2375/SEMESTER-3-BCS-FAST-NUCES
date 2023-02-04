[org 0x100]

mov ax ,10
mov bx ,20
mov cx ,30

mov dx,cx
mov cx,bx
mov bx,ax
mov ax,dx

mov dx,cx
mov cx,bx
mov bx,ax
mov ax,dx

mov ax, 4c00h
int 21h