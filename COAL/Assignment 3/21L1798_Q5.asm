[org 0x100]

jmp start
message1: db 'happy number' 
length1: dw 12 
message2: db 'Not a happy number' 
length2: dw 18



clrscr:		push es
			push ax
			push di

			mov ax, 0xb800
			mov es, ax					
			mov di, 0					

nextloc:	mov word [es:di], 0x0720	
			add di, 2					
			cmp di, 4000				
			jne nextloc					

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
			mov es, ax				
			mov di, 0				
									
			mov si, [bp+6]			
			mov cx, [bp+4]			
			mov ah, 0x07			
			
nextchar:	mov al, [si]			
			mov [es:di], ax			
			add di, 2				
			add si, 1				
			loop nextchar			
			
			pop di
			pop si
			pop cx
			pop ax
			pop es
			pop bp
			ret 4






happy_checker:
	push bp
	mov bp, sp
	sub sp,2
	sub sp,2

	push ax
	push bx
	push cx
	push dx
	push si
	push di

	mov word[bp-4],0
	mov di,[bp-4]
	mov ax, [bp+4]	

	mov cx,1
	mov bx,0
	mov si,10
loop_0:
	mov dx,0	
	div si
	mov word[bp-2],ax
	mov ax ,dx
	mul ax
	add bx,ax			;remainder in dl
	mov ax, [bp-2]
	cmp ax,0
	je finsih_0
	jmp loop_0
finsih_0:
	cmp bx,1
	jne update_ax
	mov di, 10
	jmp t_happy_checker
update_ax:
	cmp cx,256
	je t_happy_checker
	mov ax,bx
	mov bx , 0
	inc cx
	jmp loop_0
t_happy_checker:

	cmp di,10
	je printHappy
	push message2
	push word[length2]
	call printstr
	jmp terminate_function
printHappy:
	push message1
	push word[length1]
	call printstr
	jmp terminate_function
terminate_function:
	pop si
	pop dx 
	pop cx
	pop bx
	mov sp,bp
	pop bp

	ret 2


start:
	
	mov ax , 8
	push ax

	call clrscr
	call happy_checker




	mov ax , 0x4c00
	int 21h


