[org 0x0100]
jmp start
num: db 5
square: db 0
start: 
	mov cx,0
	mov ax,0
	l1:
		cmp cx,[num]
		je t_l1
		add al,[num]
		inc cx
		jmp l1
	t_l1:
		mov [square],al
		jmp terminate
terminate:
	mov ax, 0x4c00
	int 21h