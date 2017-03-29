;Popoveniuc Mircea, gr. 911, 19.11.2015, homework for lab 7, problem 15
assume cs:code, ds:data

data segment
	s dw 1234h, 5678h, 3333h, 0ff19h
	len equ ($-s)/2
	s1 db len dup(?)
	s2 db len dup(?)
data ends

code segment
start:
	; setup segment address
	mov ax, data
	mov ds, ax
	
	; setup loop and iterating through s
	mov si, offset s ; [si] points to the current word in s
	mov cx, len ; number of iterations
	mov di, 0 ; index of the byte in the destination strings
	
	repeat:
		; load the current word from s in ax; copy it to dx to count the bits in the bytes
		lodsw
		mov dx, ax
		
		; count the bits in al; use bl as counter and dl as the low byte
		mov bl, 0
		count_low:
			shr dl, 1 ; put the least significant bit in cf
			adc bl, 0 ; increment the counter if cf is '1'
			cmp dl, 0 ; check if there are '1' bits left
			ja count_low
		
		; count the bits in ah; use bh as counter and dh as the high byte
		mov bh, 0
		count_high:
			shr dh, 1 ; put the least significant bit in cf
			adc bh, 0 ; increment the counter if cf is '1'
			cmp dh, 0 ; check if there are '1' bits left
			ja count_high
			
		; compare the number of bits in the bytes and jump to the corresponding part
		cmp bh, bl
		ja above
		
		cmp bh, bl
		je equal
		
		cmp bh, bl
		jb below
		
		; number of '1' bits is larger in the high byte than in the low byte
		; move in s1 the high byte and in s2 the low byte
		above:
			mov s1[di], ah
			mov s2[di], al
			jmp continue
		
		; number of '1' bits is equal in the high byte than in the low byte
		; move in s1 the number of bits and in s2 zero
		equal:
			mov s1[di], bl
			mov s2[di], 0
			jmp continue
		
		; number of '1' bits is less in the high byte than in the low byte
		; move in s1 the low byte and in s2 the high byte
		below:
			mov s1[di], al
			mov s2[di], ah
			jmp continue
		
		; relooping
		continue:
		inc di
		loop repeat
	
	; interrupt the program
	mov ax, 4c00h
	int 21h
code ends
end start
