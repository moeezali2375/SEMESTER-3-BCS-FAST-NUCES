[org 0x0100]
        jmp start
        msg: db 'Score: '
        randNum: db 0
        oldisr: dd 0

clrscr:
        push cx
        push es
        push di

        mov cx, 0xb800
        mov es, cx
        mov di, 0
        mov cx, 2000

 c1:
        mov word[es:di], 0x0720
        add di, 2
        loop c1

        pop di
        pop es
        pop cx
        ret

                                        ;;              ;;              ;;              ;;      

randGen:
        push bp
        mov bp, sp
        push cx
        push dx
        push ax
        rdtsc                   ;getting a random number in ax dx
        xor dx,dx               ;making dx 0
        mov cx, [bp + 4]
        div cx                  ;dividing by 'Paramter' to get numbers from 0 - Parameter
        mov [randNum], dl      ;moving the random number in variable
        pop ax
        pop dx
        pop cx
        pop bp

        ret 2

                                        ;;              ;;              ;;              ;;          

genGreen:                                       ;Randomize and place green box on board at empty space
        push ax
        push bx
        push cx
        push dx
        push es
        push si
        push di

        repGreen:
                mov ax, 25
                push ax
                call randGen
                xor bx, bx
                mov bl, [randNum]
        ;        add bl, 3
                mov ax, 80
                push ax
                call randGen
                xor cx, cx
                mov cl, [randNum]
        ;        add cl, 5

                mov ax, 80
                mul bx
                add ax, cx
                mov di, 2

                mul di

                mov si, ax
                mov ax, 0xb800
                mov es, ax

                mov ax, si
        
                div di
                cmp dx, 1
                je addOneGreen

        drawGreen:
                cmp word[es:si], 0x0720                         ;If apple spawns on snake
                jne repGreen                                      ;Repeat the randomization process
                mov word[es:si], 0x2020                         ;Else place the apple

                pop di
                pop si
                pop es
                pop dx
                pop cx
                pop bx
                pop ax

                ret

        addOneGreen:
        add si, 1
        jmp drawGreen
        
                                        ;;              ;;              ;;              ;;   
                                        
genRed:                                       ;Randomize and place red box on board at empty space
        push ax
        push bx
        push cx
        push dx
        push es
        push si
        push di

        repRed:
                mov ax, 25
                push ax
                call randGen
                xor bx, bx
                mov bl, [randNum]
        ;        add bl, 3
                mov ax, 80
                push ax
                call randGen
                xor cx, cx
                mov cl, [randNum]
        ;        add cl, 5

                mov ax, 80
                mul bx
                add ax, cx
                mov di, 2

                mul di

                mov si, ax
                mov ax, 0xb800
                mov es, ax

                mov ax, si
        
                div di
                cmp dx, 1
                je addOneRed

        drawRed:
                cmp word[es:si], 0x0720                         ;If apple spawns on snake
                jne repRed                                      ;Repeat the randomization process
                mov word[es:si], 0x4020                         ;Else place the apple

                pop di
                pop si
                pop es
                pop dx
                pop cx
                pop bx
                pop ax

                ret

        addOneRed:
        add si, 1
        jmp drawRed
        
                                        ;;              ;;              ;;              ;;     

printScore:                     ;Print string "Score: " in middle of second row
        push es
        push ax
        push cx
        push di
        push si

        mov ax, 0xb800
        mov es, ax
        mov di, 230 
        mov cx, 7
        
        mov si, 0
        mov ah, 0x0D

        nextChar:
        mov al, [msg + si]
        mov [es:di], ax
        add di, 2
        inc si
        loop nextChar

        pop si
        pop di
        pop cx
        pop ax
        pop es

        ret

                                        ;;              ;;              ;;              ;;    

updateScore:                            ;Print current score in middle of sencond row (in front of string)
        push bp
        mov bp, sp
        push es
        push ax
        push bx
        push cx
        push dx
        push di

        mov ax, 0xb800
        mov es, ax
        
        mov ax, [bp + 4]
        mov bx, 10
        mov cx, 0
        nextDig:
                mov dx, 0
                div bx
                add dl, 0x30
                push dx
                inc cx
                cmp ax, 0
                jnz nextDig

                mov di, 244
        nextPos:
        pop dx
        mov dh, 0x0D
        mov [es:di], dx
        add di, 2
        loop nextPos
        
        pop di
        pop dx
        pop cx
        pop bx
        pop ax
        pop es
        pop bp

        ret 2
        
                                        ;;              ;;              ;;              ;;    
                                        
delay:
        push cx
        push ax
        mov cx, 0xffff
        mov ax, 0
        d1:
                add ax, 1
                loop d1

                mov cx, 0xffff
                mov ax, 0
        d2:
                add ax, 1
                loop d2

                mov cx, 0xffff
                mov ax, 0
        d3:
        add ax, 1
        loop d3

        pop ax
        pop cx
        ret
delay1:
mov     cx, 0FH
mov     dx, 4240H
mov     ah, 86H
int     15h
ret
                             ;;              ;;              ;;              ;;      

printBoard:                             ;Called once to print the green and red boxes
        push ax
        push bx
        push cx
        push dx
        push es
        push si
        push di

        mov ax, 0xb800
        mov es, ax

        mov cx, 10
        g1:
                call genGreen
                call delay
                call delay
                loop g1
        
        mov cx, 10
        r1:
                call genRed
                call delay
                call delay
                loop r1

                pop di
                pop si
                pop es
                pop dx
                pop cx
                pop bx
                pop ax

                ret

                                        ;;              ;;              ;;              ;;   

controlGame:                   
        push ax
        push bx
        push cx
        push dx
        push es
        push si
        push di

        xor ax, ax
        xor bx, bx
        xor cx, cx
        xor dx, dx
        xor si, si
        xor di, di

        mov ax, 0xb800
        mov es, ax

        mov di, 0

        mov word[es:0], 0x072A
        call printBoard

        mov cx, 0                   ; Holds Score 
        mov bx, 1                   ; BX = 1 -> Right, 2 ->Left, 3 -> Down, 4 -> Up
        inputAgain:
                call delay1
                mov word[es:di], 0x072A

                jmp nextMove
        end:
                pop di
                pop si
                pop es
                pop dx
                pop cx
                pop bx
                pop ax

                ret

        nextMove:
                mov word[es:di], 0x0720
                cmp bx, 1
                je rightMov

                cmp bx, 2
                je leftMov

                cmp bx, 3
                je downMov

                cmp bx, 4
                je upMov

        rightMov:
                add di, 2
                jmp updateSnake

        leftMov:
                sub di, 2
                jmp updateSnake

        downMov:
                add di, 160
                jmp updateSnake

        upMov:
                sub di, 160
                jmp updateSnake

        updateSnake:
                mov ax, [es:di]
                cmp ax, 0x4020
                je death
                cmp ax, 0x2020
                je newScore

                mov word[es:di], 0x072A

                jmp inputAgain

        newScore:
                inc cx                      ; Keeping track of score
                cmp cx, 10
                je death
                mov word[es:di], 0x072A
                jmp inputAgain

        death:
                call clrscr
                call printScore
                push cx
                call updateScore
                jmp end

                ;       ////    ///     ////    ///     ////    ///

kbisr:
        push bx
        mov bl, 1
        in al, 0x60
        pop bx

        cmp al, 0x48
        je up
        cmp al, 0x4B
        je left
        cmp al, 0x4D
        je right
        cmp al, 0x50
        je down

        jmp far [cs:oldisr]

        up:
                mov bx, 4
                jmp far [cs:oldisr]

        down:
                mov bx, 3
                jmp far [cs:oldisr]

        right:
                mov bx, 1
                jmp far [cs:oldisr]

        left:
                mov bx, 2
                jmp far [cs:oldisr]



start:

        xor ax, ax                      ;Hooking Interrupt
	mov es, ax
	mov ax, [es:9 * 4]
        mov [oldisr], ax
	mov ax, [es:9 * 4 + 2]
	mov [oldisr + 2], ax
	
        cli
	mov word[es:9 * 4], kbisr
	mov [es:9 * 4 + 2], cs
   
	sti

        call clrscr
        call controlGame

        xor ax, ax                      ;Unhooking Interrupt
	mov es, ax
        mov ax, [oldisr]
	mov bx, [oldisr + 2]

	cli
	mov [es:9 * 4], ax
	mov [es:9 * 4 + 2], bx
	sti

        mov ax, 0x4c00
        int 0x21

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

