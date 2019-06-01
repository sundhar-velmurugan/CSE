org 100h
mov bx, 3000h
mov ds, bx

start:mov si, 0100h
      mov ah, 00h
      int 16h
      mov ah, 02h
      mov dl, al
      int 21h
      mov dx, 0200h
      mov ah, 09h
      int 21h
      mov ah, 07h
      int 21h
      mov [si], al
      inc si
      mov ah, 07h
      int 21h
      mov [si], al
      inc si
      mov ah, 07h
      int 21h
      mov [si], al
      inc si
      mov [si], 24h
      mov dx, 100h
      mov ah, 09h
      int 21h
      jmp start