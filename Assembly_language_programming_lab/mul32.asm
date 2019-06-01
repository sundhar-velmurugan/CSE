
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov bx,8000h
mov ds,bx
mov si,1000h
mov ax,[si]
mov cx,[si+4]
mov ax,[si+2]
mov cx,[si+6]
mul cx
mov [si+0eh],ax
mov bx,dx
mov ax,[si+2]
mul cx
add ax,bx
adc dx,00h
mul cx
mov [si+08h],ax
mov bx,dx
add ax,bx
add dx,00h
mov [si+0ah],ax
mov [si+0ch],dx
mov cx,[si+0ah]
adc cx,[si+0eh]
adc ax,[si+0ch]
adc dx,00h
mov [si+0ah],cx
mov [si+0ch],ax
mov [si+0eh],dx
hlt




