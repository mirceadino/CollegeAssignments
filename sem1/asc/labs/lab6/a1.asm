assume cs:code, ds:data

data segment
	n db 0
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
	
	jcxz finish
	
	repeat:
		add sol, cx
		loop repeat
		
	finish:
	
	; here ends the program
	mov ax,4C00h
	int 21h
code ends
end start
