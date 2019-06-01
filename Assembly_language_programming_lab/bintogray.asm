
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov bx,3000h
mov ds,bx
mov si,0000h
mov ax,[si]
mov bx,ax
shr bx,1
xor ax,bx
mov [si+2],ax
hlt

ret




