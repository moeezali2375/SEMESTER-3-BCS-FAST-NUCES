[org 0x100]

jmp start
minimum_calculator:
	push bp
	mov bp, sp


	push bx
	push cx
	push dx
	push si

	mov ax , 0

	mov cx , [bp+4] ;counter value
	mov si , 6

	mov ax , [bp+si] ;	last value 
	add si,2
	dec cx
l1:
	mov dx , [bp+si] ;
	cmp ax,dx
	ja update

resume:
	add si,2
	dec cx
	cmp cx,0
	je t_f1
	jmp l1

update:
	mov ax,dx
	jmp resume

t_f1:
	pop si
	pop dx 
	pop cx
	pop bx
	pop bp
	ret 12


start:
	push 5
	push 1
	push 3 
	push 10
	push 4
	push 5
	call minimum_calculator

	mov ax , 0x4c00
	int 21h


