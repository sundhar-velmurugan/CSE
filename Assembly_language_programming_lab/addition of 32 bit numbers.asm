; did not solve many issues like where carry goes

org 200h
mov bx, 2000h
mov ds, bx
mov si, 150h

mov ax, [si]
mov bx, [si+2]
add ax, bx  
mov [si+8], ax 

mov ax, [si+4]
mov bx, [si+6]
add ax, bx  
mov [si+10], ax  

jc skip

skip:   mov dl, 0h
        inc dl

mov [si+12], dl