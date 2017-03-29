;7. Write a program which reads the name of a file from the keyboard and then it prints on the screen the even lines from this file.
ASSUME CS:code, DS: data
data SEGMENT
        buffer db 11, ?, 12 dup('$')
        newline db 10, 13, '$'
data ENDS
code SEGMENT
start:
 
        mov ax, data
        mov ds, ax
 
        mov ah, 0ah
        mov dx, offset buffer
        int 21h
       
        mov ah, 09h
        mov dx, offset newline
        int 21h
       
        mov ah, 09h
        mov dx, offset buffer + 2
        int 21h
       
        mov ax, 4C00h
        int 21h
 
code ENDS
END start
