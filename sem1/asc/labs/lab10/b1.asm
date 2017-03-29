assume cs:code, ds:data

data segment
	maxLenBuffer db 6
	lenBuffer db ?
	buffer db 6 dup(?)
	newline db 10, 13, '$'
	DECTABLE db "0123456789"
	TEN dw 10
data ends

code segment

; print the value stored in AX in base 10
print10 proc
	push cx
	push dx
	
	mov cx, 0
	
	; repeatedly divide AX by 10 and push the digits into the stack
	divide10:
		mov dx, 0
		div TEN
		push dx
		inc cx
		cmp ax, 0
		jne divide10
	
	; pop from the stack all the digits, translate the digit and print it to the screen
	printNr:
		pop ax
		xlat DECTABLE
		mov dl, al
		mov ah, 02h
		int 21h
		loop printNr
	
	pop dx
	pop cx
	
	ret
print10 endp

; print a newline
endl macro
	push ax
	push dx
	
	mov ah, 09h
	lea dx, newline
	int 21h
	
	pop dx
	pop ax
endm

; reads a string and returns the integer value in AX
readInteger proc
	push bx
	push cx
	push dx
	
	mov ah, 0ah
	lea dx, maxLenBuffer
	int 21h
	
	mov bx, 0
	lea si, buffer
	mov ch, 0
	mov cl, lenBuffer
	
	repeat:
		lodsb
		mov ah, '0'
		sub al, ah
		push cx
		mov cl, al
		mov ax, bx
		mov dx, 0
		mul TEN
		add al, cl
		pop cx
		mov bx, ax
		loop repeat
	
	mov ax, bx
	
	pop dx
	pop cx
	pop bx
ret
readInteger endp

start:
	push data
	pop ds
	
	call readInteger
	endl
	call print10
	
finish:
	mov ax, 4c00h
	int 21h
code ends
end start
