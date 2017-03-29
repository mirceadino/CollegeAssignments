assume cs:code, ds:data

data segment
	msg db "Press 0 for base 10 and 1 for base 2: $"
	errorMsg db "Invalid option.$"
	newline db 13, 10, '$'
	a dw 101010010b
	ten dw 10
	inverse db 6 dup(?)
	number db 6 dup(?)
	digit db ?
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	mov es, ax
	
get_preference:
	mov ah, 09h
	mov dx, offset msg
	int 21h
	
	mov ah, 01h
	int 21h
	
	mov ah, 09h
	mov dx, offset newline
	int 21h
	
	cmp al, '0'
	je base10
	
	cmp al, '1'
	je base2
	
	mov ah, 09h
	mov dx, offset errorMsg
	int 21h
	
	jmp end_of_program

; print the number in base 10
base10:
	; divide dx:ax successively by 10 in order to get the digits in reversed order (also add '0' at the same time to each digit)
	
	mov ax, a
	mov si, offset inverse
	
	divide_by_ten:
		mov dx, 0
		div ten
		mov [si], dl
		add byte ptr [si], '0'
		inc si
		cmp ax, 0
		jne divide_by_ten
	
	; reverse the digits and get the digits in actual order
	mov cx, si
	sub cx, offset inverse
	dec si
	mov di, offset number
	
	reverse_number:
		std
		lodsb
		cld
		stosb
		loop reverse_number
	
	; add the '$' at the end of the string representation of the number
	mov byte ptr [di], '$'
	
	; print the number	
	mov ah, 09h
	mov dx, offset number
	int 21h
	
	jmp end_of_program

; print the number in base 2
base2:
	mov cx, 16
	
	get_digit_by_digit:
		mov digit, '0'
		shl a, 1
		adc digit, 0
		
		; print digit
		mov ah, 02h
		mov dl, digit
		int 21h
		
		loop get_digit_by_digit
	
	jmp end_of_program
	
; end the execution of the program
end_of_program:
	mov ax, 4c00h
	int 21h
code ends
end start
