assume cs:code, ds:data

data segment
	;a dd 11111111111111111111111111111111b
	a dd 1000101011101100010101000b
	;a dd 7FFF8h
	;a dd 0fffffh
	ones db ?
data ends

code segment
start:
	push data
	pop ds
	; here starts the program
	
	; set the initial number of '1' bits as 0
	mov ones, 0
	
	; set dx as 0 to mark that we didn't compute the number of bits for the high word
	mov dx, 0
	
	; count the numbers of '1' bits on the low word of a
	; move the low word of a on ax
	mov ax, word ptr a
	
	countBitsOfAX:
		; remove the least significant bit of ax by shifting to the right
		shr ax, 1
		
		; the bit will be in cf, so we add it to the 'ones' counter
		adc ones, 0
		
		; if there are still '1' bits left in ax, then ax will be different of 0
		cmp ax, 0
		jne countBitsOfAX
	
	cmp dx, 1
	je endOfCount
	
	; count the numbers of '1' bits on the high word of a
	; move the high word of a on ax
	mov ax, word ptr a+2
	
	; redo the same algorithm for the high word
	; also set dx as 1 to mark that we already computed the bits for the high word
	mov dx, 1
	jmp countBitsOfAX
	
	endOfCount:
	
	; a has 32 bits out of which ones are bits of '1' and 32-ones are bits of '0'
	; a has more bits of '1' than bits of '0' if it has more than 16 bits of '1'
	
	cmp ones, 16
	ja invertBits
	
	divideByFour:
		; divide by 2
		shr word ptr a+2, 1
		rcr word ptr a, 1 
		
		; divide by 2 again
		shr word ptr a+2, 1
		rcr word ptr a, 1 
		
		jmp finish
	
	invertBits:
		; separate and invert the 4th bit
		mov bx, 1
		mov cl, 4
		shl bx, cl
		xor word ptr a, bx
		
		; separate and invert the 6th bit
		mov bx, 1
		mov cl, 6
		shl bx, cl
		xor word ptr a, bx
		
		; separate and invert the 8th bit
		mov bx, 1
		mov cl, 8
		shl bx, cl
		xor word ptr a, bx
		
		; separate and invert the 25th bit
		; the 25th bit in a double word is the 25-16 = 9th bith in the high word
		mov bx, 1
		mov cl, 9
		shl bx, cl
		xor word ptr a+2, bx
		
		jmp finish
		
	finish:
	
	; here ends the program
	mov ax, 4C00h
	int 21h
code ends
end start
