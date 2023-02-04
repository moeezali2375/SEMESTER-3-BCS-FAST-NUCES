[org 0x100]
jmp start
array: dw 111, 999, 888, 888, 11, 99, 88, 88, 1, 9, 8, 8
size: dw 12
max: dw 0


maximum: 
	push ax
	push bx
	push cx
	push dx
	push si
	mov ax,[size]
	shl ax,1
	mov [size],ax
	mov bx,0
	mov cx,0
	mov dx,0
	mov si,0
	mov ax,[array+0]

l2: 
	cmp dx, [size]
	je t_l2
	cmp ax ,[array+si]
	jb update
resume:
	add dx,2
	add si,2 
	jmp l2
update:
	mov ax,[array+si]
	jmp resume

t_l2:
	mov [max],ax 
	mov ax,[size]
	shr ax,1
	mov [size],ax
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret
start:
call maximum
terminate:
mov ax, 0x4c00
int 21h