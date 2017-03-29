;Popoveniuc Mircea, gr. 911, 12.11.2015, homework for lab 6, problem 14

assume cs:code, ds:data

data segment
	s1 db '+', '4', '2', 'a', '8', '4', 'X', '5'
	len1 equ $-s1
	s2 db 'a', '4', '5'
	len2 equ $-s2
	d db len1/3+1+len2 dup(?)
	lend equ $-d
data ends

code segment
start:
	push data
	pop ds
	push data
	pop es
	
	; we need to put the positions multiple of 3 from s1 on d
	mov si, offset s1 ; set the source string on ds:si
	mov di, offset d  ; set the destination string on es:di
	
	; set the direction in a normal way (from left to right)
	cld
	
	; set the number of iterations
	mov cx, len1/3+1
	
	moveMultiplesOf3:
		; directly move the current byte in s1 to d
		movsb
		; because si was incremented by 1, increment it twice
		; (to move 3 by 3)
		add si, 2
		loop moveMultiplesOf3
	
	; we need to put the elements of s2 in reverse order on d
	; set the source string at the end of s2
	mov si, offset s2 + len2 - 1
	
	; set the direction in a reverse way (from right to left)
	std
	
	; set the number of iterations
	mov cx, len2
	
	moveReverse:
		; directly move the current by in s2 to d
		movsb
		; because di was decreasted by 1, increment it twice
		; (to advance on d by one position)
		add di, 2
		loop moveReverse
	
	mov ax, 4C00h
	int 21h
code ends
end start

