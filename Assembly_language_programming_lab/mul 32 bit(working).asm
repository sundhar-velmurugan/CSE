org 100h
mov bx, 2000h
mov ds, bx
mov si, 100h
mov ax, [si]
mov cx, [si+4]
mul cx
mov [si+8], ax
mov bx, dx 
mov ax, [si]
mov cx, [si+6]
mul cx
add ax, bx
adc dx, 00h
mov [si+0ah], ax
mov [si+0ch], dx
mov ax, [si+2]
mov cx, [si+4]
mul cx
mov bx, dx
add ax, [si+0ah]
adc bx, [si+0ch]
adc dx, 00h
mov [si+0ah], ax
mov [si+0ch], bx
mov [si+0eh], dx 
mov ax, [si+2]
mov cx, [si+6]
mul cx   
add ax, [si+0ch] 
adc dx, 0h
mov [si+0ch], ax
mov [si+0eh], dx 
hlt