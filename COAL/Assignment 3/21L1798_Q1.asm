[org 0x100]
jmp start

num1 :db 1515,1515
;=================================================
;                                                 
;  #####    #####   ##      ##  #####  #####    
;  ##  ##  ##   ##  ##      ##  ##     ##  ##   
;  #####   ##   ##  ##  ##  ##  #####  #####    
;  ##      ##   ##  ##  ##  ##  ##     ##  ##   
;  ##       #####    ###  ###   #####  ##   ##  
;                                                 
;=================================================

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




calculate_power:		
	push bp 		;this routine calculates power and returns the answer in dx
	mov bp,sp
	push ax
	push bx
	push cx

	mov dx,0
	mov bx, [bp+6]	;bp+6=base
	mov cx, 0
	mov ax,1
power_loop:
	cmp cx, [bp+4]	;bp+4 =index
	je t_power
	mul bx
	inc cx
	jmp power_loop
t_power:
	mov dx,ax
	pop cx
	pop bx
	pop ax
	pop bp
	ret 4


;===================================================
;                                                   
;         #####    ####  ######    ###    ##      
;        ##   ##  ##       ##     ## ##   ##      
;        ##   ##  ##       ##    ##   ##  ##      
;        ##   ##  ##       ##    #######  ##      
;         #####    ####    ##    ##   ##  ######  
;                                                   
;===================================================

octal_printer:


	push bp
	mov bp,sp
	sub sp,2

	mov bx,0
	mov cx,0
	mov [bp-2],bx
dec_loop:			;this converts the number into decimal 
	cmp bx,18
	je break_dec_loop
	shr al,1
	jnc skip
	push 2
	push cx
	call calculate_power
	add [bp-2],dx
skip:
	inc cx
	add bx,1
	cmp bx,9
	je update_byte
resume_update_byte:
	cmp cx,3
	jne continue
	mov cx,0
	mov si,[bp-2]
	add si ,0x30
	push si
	mov word[bp-2],0
continue:
	jmp dec_loop

update_byte:
	mov al,[num1+1]
	jmp resume_update_byte
break_dec_loop:
	call clrscr
	mov si,0x31
	push si
	mov ax,0xb800
	mov es,ax
	mov cx,7
printloop:
	
	pop dx
	mov dh ,0x07
	mov [es:di],dx
	add di,2
loop printloop
	
	mov sp,bp
	pop bp
	ret 2

start:

mov al, [num1]
mov ah, [num1+1]
push ax 
call octal_printer
mov bx ,0
mov ax , 4c00h
int 21h