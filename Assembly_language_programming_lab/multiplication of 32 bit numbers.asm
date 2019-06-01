org 100h
mov bx, 1000h
mov ds, bx
mov si, 100h

mov ax, [si]
mov cx, [si+4] 
mul cx

mov [si+08h], ax
mov bx, dx

mov ax, [si+2]
mul cx

add ax, bx
adc dx, 00h

mov [si+0ah], ax
mov [si+0ch], dx

mov ax, [si]
mov cx, [si+6]
mul cx

add ax, [si+0ch]
mov [si+0ch], ax
mov [si+0eh], dx
mov bx, dx

mov ax, [si+2]
mul cx

add ax, bx
adc dx, 00h

mov cx, [si+ 0ah]
adc cx, [si+0eh]
adc ax, [si+0ch]
adc dx, 00h

mov [si+0ah], cx
mov [si+0ch], ax
mov [si+0eh], dx

hlt