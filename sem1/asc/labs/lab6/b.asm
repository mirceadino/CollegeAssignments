assume cs:code, ds:data

data segment
	sol dw ?
data ends

code segment
start:
	push data
	pop ds
	; here starts the program
	
	; set initial solution to 0
	mov sol, 0 
	
	; set the first 2 fib terms in ax and bx
	mov ax, 1
	mov bx, 1
	
	; set the number of iterations
	mov cx, 15-2
	; 15-2 because we've already computed the first 2 terms
	
	; add the first 2 fib terms to the sum
	add sol, ax
	add sol, bx
	
	repeat:
		; compute the next fib term
		mov dx, ax ; dx = ax
		add dx, bx ; dx = ax + bx
		; so ax, bx, dx correspond to 3 consecutive fib terms
		
		; add the newly computed term to the sum
		add sol, dx
		
		; advance by a position with the fib terms
		mov ax, bx
		mov bx, dx
		loop repeat
	
	; here ends the program
	mov ax, 4C00h
	int 21h
code ends
end start
