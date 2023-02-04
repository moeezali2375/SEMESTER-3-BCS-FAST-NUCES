[org 0x100]
jmp start


clrscre:
		push es
		push ax
		push di

		mov ax,0xb800
		mov es,ax
		mov di,0
		mov cx ,12

nextloc4: mov word[es:di] , 0x3020
		add di,2
		cmp di,[h0]
		jne nextloc4
		sub cx,1	
		jne nextlc4
		jmp ex4

nextlc4:
		add di,160
		sub di,80
		add word [h0] , 160
		jmp nextloc4
ex4:
		pop di
		pop ax
		pop es
		ret 
;------------------------------------------------------------------
clrscre1:
		push es
		push ax
		push di

		mov ax,0xb800
		mov es,ax
		mov di,2000
		mov cx ,12

nextloc5: 

		mov word[es:di] , 0x4020
		add di,2
		cmp di,[h5]
		jne nextloc5
		sub cx,1	
		jne nextlc5
		jmp ex5

nextlc5:
		add di,160
		sub di,80
		add word [h5] , 160
		jmp nextloc5
ex5:
		pop di
		pop ax
		pop es
		ret 




clrscr1:
		push es
		push ax
		push di

		mov ax,0xb800
		mov es,ax
		mov di,0
		mov cx ,12

nextloc: mov word[es:di] , 0x4020
		add di,2
		cmp di,[h]
		jne nextloc
		sub cx,1	
		jne nextlc
		jmp ex

nextlc:
		add di,160
		sub di,80
		add word [h] , 160
		jmp nextloc
ex:
		pop di
		pop ax
		pop es
		ret 
;--------------------------------------------------
clrscr2:
		push es
		push ax
		push di

		mov ax,0xb800
		mov es,ax
		mov di,80
		mov cx ,12

nextloc1: mov word[es:di] , 0x1020
		add di,2
		cmp di,[h2]
		jne nextloc1
		sub cx,1	
		jne nextlc1
		jmp ex1

nextlc1:
		add di,160
		sub di,80
		add word [h2] , 160
		jmp nextloc1
ex1:
		pop di
		pop ax
		pop es
		ret 
;--------------------------------------------------
clrscr3:
		push es
		push ax
		push di

		mov ax,0xb800
		mov es,ax
		mov di,1920
		mov cx ,12

nextloc2: mov word[es:di] , 0x2020
		add di,2
		cmp di,[h3]
		jne nextloc2
		sub cx,1	
		jne nextlc2
		jmp ex1

nextlc2:
		add di,160
		sub di,80
		add word [h3] , 160
		jmp nextloc2
ex2:
		pop di
		pop ax
		pop es
		ret 
;--------------------------------------------------
clrscr4:
		push es
		push ax
		push di

		mov ax,0xb800
		mov es,ax
		mov di,2000
		mov cx ,12

nextloc3: 

		mov word[es:di] , 0x3020
		add di,2
		cmp di,[h4]
		jne nextloc3
		sub cx,1	
		jne nextlc3
		jmp ex3

nextlc3:
		add di,160
		sub di,80
		add word [h4] , 160
		jmp nextloc3
ex3:
		pop di
		pop ax
		pop es
		ret 
start:
		call clrscr1
		call clrscr2
		call clrscr3
		call clrscr4
 xor ax, ax 
 mov es, ax 
 mov ax, [es:9*4] 
 mov [oldisr], ax 
 mov ax, [es:9*4+2] 
 mov [oldisr+2], ax 
l1:
 mov ah, 0  
 int 0x16  
 cmp al, 27  
 call clrscre
 call clrscre1
 jne l1 
 mov ax, [oldisr]  
 mov bx, [oldisr+2]  
 cli 
 mov [es:9*4], ax 
 mov [es:9*4+2], bx 
 sti 
     




mov ax,0x4c00
int 21h
oldisr: dd 0
h0: dw 80
h: dw 80
h2: dw 160
h3: dw 2000
h4: dw 2080
h5: dw 2080