[org 0x0100]

jmp start


lets_flip:
	push ax
	push bx
	push es
	push di
	push si

	mov di,0
	mov ax,0xb800
	mov si,4000
	mov es,ax
	
flip_loop:
	mov bx,[es:di]
	mov [es:si],bx
	add di,2
	sub si,2
	cmp di,2000
	jz terminate_loop
	jmp flip_loop

terminate_loop:
	pop si
	pop di
	pop es
	pop bx
	pop ax

	ret


start:
	call lets_flip
	jmp finish

finish:	
	mov ax,0x4c00
	int 21h



