[org 0x100]

jmp start

str1: db "The alignment-check exception can also be used by interpreters to flag some pointers as special by misaligning the pointer.",0
length dw 124
row: dw 3
col: dw 40
str2: db "align"
size2: db 5





clrscr:		push es
			push ax
			push di

			mov ax, 0xb800
			mov es, ax					; point es to video base
			mov di, 0					; point di to top left column

nextloc:	mov word [es:di], 0x0720	; clear next char on screen
			add di, 2					; move to next screen location
			cmp di, 4000				; has the whole screen cleared
			jne nextloc					; if no clear next position

			pop di
			pop ax
			pop es
			ret

printstr:	push bp
			mov bp, sp
			push es
			push ax
			push cx
			push si
			push di

			mov ax, 0xb800
			mov es, ax				; point es to video base
			mov di, 0				; point di to top left column
									; es:di --> b800:0000
			mov si, [bp+6]			; point si to string
			mov cx, [bp+4]			; load length of string in cx
			mov ah, 0x07			; normal attribute fixed in al
			
nextchar:	mov al, [si]			; load next char of string
			mov [es:di], ax			; show this char on screen
			add di, 2				; move to next screen location
			add si, 1				; move to next char in string			
			loop nextchar			; repeat the operation cx times
			
			pop di
			pop si
			pop cx
			pop ax
			pop es
			pop bp
			ret 4

Trimmer:
		mov ds,ax
		push bp
		mov bp,sp
		push ax
		push di
		push si
		push cx
		push bx

mov si,0
mov di,0
mov cx,1

l1:	mov ax,[str1 + si]
		mov bx,[str1 + di]
		add si,2
		add di,2
		mov cx,1
		cmp ax,bx
		jz l1
		jnz	addi
		cmp ax,0
		jz end

jmp end

addi:	add si,2
			add di,0
			mov cx,0
			cmp ax,0
			jz end


		pop di
			pop si
			pop cx
			pop ax
			pop es
			pop bp 

;[bp+4]=size of str1(bx)
;[bp+6]=[col]
;[bp+8]=[row]

mov cx,[bp+4]

mov ax,80
mov di,0
mul byte [bp+8]
add ax,[bp+6]
shl ax,1
mov si,ax

rep movsw 


ret 6

start: 
call clrscr

mov ax, str1
push ax				
push word [length]	
call printstr		
push word [row]
push word [col]
push bx
call Trimmer

mov ax, str1
push ax				
push word [length]	
call printstr
end:
mov ax,0x4c00
int 21h