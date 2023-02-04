[org 0x0100] 

 jmp start 

tickcount: dw 0 

printnum: push bp 
 mov bp, sp 
 push es 
 push ax 
 push bx 
 push cx 
 push dx 
 push di 
 mov ax, 0xb800 
 mov es, ax 
 mov ax, [bp+4] 
 mov bx, 10 
 mov cx, 0 

nextdigit: mov dx, 0  
 div bx 
 add dl, 0x30 
 push dx  
 inc cx  
 cmp ax, 0  
 jnz nextdigit 
 mov di, 140 

nextpos: pop dx  
 mov dh, 0x07 
 mov [es:di], dx 
 add di, 2  
 loop nextpos  
 pop di 
 pop dx 
 pop cx 
 pop bx 
 pop ax 
 pop es 
 pop bp 
 ret 2 


timer: push ax 

 inc word [cs:tickcount]
 push word [cs:tickcount] 
 call printnum 
 mov al, 0x20 
 out 0x20, al 
 pop ax 
 iret 


timee:
push cx
mov cx,0xFFFF
mov dx,3
l5:
loop l5
mov cx,0xFFFF
dec dx
cmp dx,0
jne l5
pop cx
ret

cls
push es
push ax
push cx
push di
mov ax, 0xb800
mov es, ax
xor di, di
mov ax, 0x0720
mov cx, 2000
cld
rep stosw
pop di
pop cx
pop ax
pop es
ret



start:
call cls
mov al,'*'
mov ah,0x07
mov di,0
mov dx,0xb800
mov es,dx
mov cx,78

loop1:
mov [es:di],ax
add di,2
call timee
loop loop1
sub di,2
mov cx,24

loop2:

mov [es:di],ax
add di,160
call timee
loop loop2

mov cx,78
loop3:
mov [es:di],ax
sub di,2
call timee
loop loop3

add di,2
mov cx,24
loop4:
mov [es:di],ax
sub di,160
call timee
loop loop4

end:
mov ax, 0x4c00
int 21h