assume ds:data, cs:code

data segment
	n db 7
	s dw ?
data ends
z
code segment
start:
	mov ax, data
	mov ds, ax
	; here starts the program
	
	; try to read smth
	
	validread:
		mov ah, 01h
		int 21h
		mov n, al
		
		cmp n, '0'
		jb validread
		
		cmp n, '9'
		ja validread
		
		mov al, n
		sub al, '0'
		mov n, al
	
	; solution
	
	mov al, n
	cbw
	mov cx, ax
	mov s, 0
	
	repeat:
		add s, cx
		dec cx
		cmp cx, 0
		ja repeat
		
	; here ends the program
	mov ax, 4C00h
	int 21h
code ends
end start
