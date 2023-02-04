[org 0x100]

mov si, 0

mov ax, [num]
mov bx, [num]

and ax, 0xF000
and bx, 0x000F

call checkPalindrome

cmp dx, 1
jnz terminate

mov ax, [num]
mov bx, [num]
and ax, 0x0F00
shl ax, 4
and bx, 0x00F0
shr bx, 4

call checkPalindrome

terminate:  mov ax, 0x4C00
            int 21h

num: dw 0xA425

checkPalindrome:     mov cx, 0

                    repeat:	shl ax, 1
                            jc l1
                            shr bx, 1
                            jc l3
                            mov dx, 1
                            inc cx
                            cmp cx, 4
                            jnz repeat
                            ret

                    l1:     shr bx, 1
                            jc l2
                            mov dx, 0
                            ret

                    l2:     mov dx, 1
                            inc cx
                            cmp cx, 4
                            jnz repeat
                            ret

                    l3:     mov dx, 0
                            ret