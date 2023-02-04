[org 0x100]
jmp start
array: dw 1, 9, 9,9, 8, 8,8, 8, 8,8, 1, 1, 9, 9, 8, 8, 8, 8, 1, 9, 8, 8
size: dw 22
frequency: dw 0
num: dw 9

frequency_calculator:
	push ax
	push bx
	push cx
	push dx
	push si
	mov ax,[num]
	mov bx,0
	mov cx,0
	mov dx,[size]
	shl dx,1
	mov si,0
	l1:
		cmp cx,dx
		je t_l1
		cmp ax,[array+si]
		je update
	resume:
		add cx,2
		add si,2
		jmp l1
	update:
		inc bx
		jmp resume
	t_l1:
		mov [frequency],bx

	pop si
	pop dx
	pop cx
	pop bx 
	pop ax 
	ret 

start:
	mov ax,0
	call frequency_calculator
terminate:
	mov ax, 0x4c00
	int 21hf