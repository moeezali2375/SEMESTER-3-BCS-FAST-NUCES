[org 0x0100]

jmp start

oldisr : dd 0

clscr :
 mov ax, 0xb800
 mov es, ax
 mov di, 0

 l1 :
  mov word[es : di], 0x0720
  add di, 2
  cmp di, 4000
  jne l1

ret

copy :
 mov ax, 0xb800
 mov es, ax
 mov di, 0
 mov si, 4000

 l2 :
  mov bx, [es : di]
  mov word[es : si], bx
  add si, 2
  add di, 2
  cmp si, 7998
  jne l2

ret

hazoor :
 push ax
 push es
 
 mov ax, 0xb800
 mov es, ax
 in al, 0x60
 cmp al, 0x2a
 jne c
 call copy
 call clscr
 jmp exit

 c:
  cmp al,0xaa
  jne no

 mov ax, 0xb800
 mov es, ax
 mov si, 0
 mov di, 4000

 l3 :
  mov bx, [es : di]
  mov word[es : si], bx
  add si, 2
  add di, 2
  cmp si, 7998
  jne l3


 no:
  pop es
  pop ax
  jmp far[cs:oldisr]

exit:
 mov al,0x20
 out 0x20,al

pop es
pop ax

iret

start :
 xor ax, ax
 mov es, ax 
 
 mov ax, [es:9*4]
 mov [oldisr], ax
 mov ax, [es:9*4+2]
 mov [oldisr+2], ax

 cli
 mov word [es:9*4], hazoor
 mov [es:9*4+2], cs
 sti
 mov dx, start
 add dx, 15
 mov cl, 2
 shr dx, cl

mov ax, 0x3100
int 0x21