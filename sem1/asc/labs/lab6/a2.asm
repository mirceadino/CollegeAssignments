assume cs:code, ds:data

data segment
	n db 7
	sol dw ?	
data ends

code segment
start:
	push data
	pop ds
	; here starts the program
	
	mov sol, 0
	mov cl, n
	mov ch, 0
	
	repeat:
		add sol, cx
		dec cx
		cmp cx, 0
		jg repeat
	
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
