[org 0x0100]
jmp start

start:
mov ah,0
mov cx,0
mov bx,0
loop1:
    cmp bl,[size]
    je ter_loop1
   
    add ah,[array+bx]
    add bx,1
    jmp loop1
    ter_loop1:
        jmp loop2

loop2:
    cmp bl,0
    je ter_loop2
    cmp ah,[size]
    jb ter_loop2
    sub ah,[size]
    add cx,1
    sub bx,1
    jmp loop2
    ter_loop2:
        mov [mean],cx

mov ax,0x4c00
int 21h

array: db 1,2,2,3,1,3,2,3
size :db 8
mean 
