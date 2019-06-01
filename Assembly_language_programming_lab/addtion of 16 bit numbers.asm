org 100h
mov bx, 1000h
mov ds, bx
mov si, 100h
mov cx, 10
mov ax, 0h ;not necessary

l1: add ax, [si]
    jnc skip
    inc dl
    
skip: inc si
      inc si
      loop l1
      mov [si], ax  
      mov [si+2], dl
      