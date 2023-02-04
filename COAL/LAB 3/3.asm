[org 0x0100]
jmp start
num: dw 5
answer dw 0

factorial:
	push ax
	push bx
	push cx
	push dx
	mov ax, [num]
	mov bx, [num]
	mov dx,0
	mov cx, ax
	l1:
		cmp cx,0
		je t_l1
		mov dx,cx
		mov bx,ax
	l2:
		cmp dx,2
		jbe t_l2
		add ax,bx
		sub dx,1
		jmp l2
	t_l2:
		sub cx,1
		jmp l1
	t_l1:
	mov [answer], ax
		pop dx
		pop cx
		pop bx
		pop ax
	ret


start:
	call factorial
terminate:
	mov ax,0x4c00
	int 21h