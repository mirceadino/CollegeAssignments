assume cs:code, ds:data

data segment
	maxLenBuffer db 101
	lenBuffer db ?
	buffer db 101 dup(?)
	newline db 10, 13, '$'
	HEXTABLE db "0123456789ABCDEF"
	SIXTEEN dw 16
data ends

code segment

; print the value stored in AX in base 16
print16 proc
	push cx
	push dx
	
	mov cx, 0
	
	; repeatedly divide AX by 16 and push the digits into the stack
	divide16:
		mov dx, 0
		div SIXTEEN
		push dx
		inc cx
		cmp ax, 0
		jne divide16
	
	; pop from the stack all the digits, translate the digit and print it to the screen
	printNr:
		pop ax
		xlat HEXTABLE
		mov dl, al
		mov ah, 02h
		int 21h
		loop printNr
	
	pop dx
	pop cx
	
	ret
print16 endp

start:
	push data
	pop ds
	
	; read string
	mov ah, 0ah
	lea dx, maxLenBuffer
	int 21h
			
	; print a newline
	mov ah, 09h
	lea dx, newline
	int 21h
	
	; parse the string and count the number of digits in AX
	mov ax, 0
	mov ch, 0
	mov cl, lenBuffer
	lea si, buffer
	
	count:
		; check if current characters is below '0'
		mov dl, '0'
		cmp [si], dl
		jb repeat
		
		; check if current characters is above '9'
		mov dl, '9'
		cmp [si], dl
		ja repeat
		
		; we found a character, so increase AX
		inc ax
		
		; get to the next character in the string
		repeat:
		inc si
		loop count
	
	; in AX we have the number of digits from the string
	; print AX to the screen in base 16
	call print16
	
finish:
	mov ax, 4c00h
	int 21h
code ends
end start
