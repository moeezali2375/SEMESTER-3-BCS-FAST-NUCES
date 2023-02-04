[org 0x100]
mov ax,50
mov bx,7
mov cx,0
mov si,0

cmp ax,8
jae l3
l3:
sub ax,8
add si,1
cmp ax,8
jbe l4
l4:
mov cx,[num1+si]

mov ax,50

cmp ax,8
jae l1
l1:
sub ax,8
cmp ax,8
jbe l2
l2:

mov [mod1],ax
l9:
mov si,[mod]
shr [num1+cx],00000000b

l1:
mov ax,0
cmp [mod],1
je l9
cmp [mod],2
je l9
cmp [mod],3
je l9
cmp [mod],4
je l9
cmp [mod],5
je l9
cmp [mod],6
je l9
cmp [mod],7
je l9
cmp [mod],8
je l9

mov ax,8
sub ax,[mod]
cmp ax,8
jb l1

mov ax,50
mov bx,7

cmp bx,8
jae l5
add si,1
add cx,1
cmp si,1
ja l7
l7:
and [num1+cx],00000000b 
l5:
sub bx,8
cmp bx,8
jbe l6
l6:
mov [mod2],bx

sub ax,8
add ax,bx
and ax,00000000b


mov ax,0x4c00
int 21h

[num1]: db 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32
[num2]: db 0
[mod1]: db 0
[mod2]: db 0