org 100h
mov bx, 2000h
mov ds, bx
mov si, 100h
mov al, [si]
add al, [si+2]
daa
mov cl, al
and al, 0fh
mov [si+4], al
and cl, 0f0h
ror cl, 4
mov ch, cl
mov al, [si+1] 
add al, ch
adc al, [si+3]
daa
mov cl, al
and al, 0fh
mov [si+5], al
and cl, 0f0h
ror cl, 4
mov [si+6], cl
hlt