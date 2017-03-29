assume cs:code, ds:data
data segment public
	msg1 db 'Enter several binary numbers separated by whitespace.$'
	msg2 db 'The numbers should not exceed 16 digits.$'
	msg3 db 'The hexadecimal representation of the given numbers is: $'
	error_message db 'The input contains characters other than 0, 1, space or ENTER!$'
	max_len db 101
	real_len db (?)	
	buffer db 101 DUP (?)
	new_line db 13, 10, '$'
	number db 16 DUP (?)
data ends

code segment public
public number
extrn ConvertBase16:proc

start:
	mov ax, data
	mov ds, ax
	mov es, ax

	;macro for printing a new line on the screen	
	newline MACRO
		push dx
		push ax
		lea dx, new_line
		mov ah, 9
		int 21h
		pop ax
		pop dx
	ENDM

	lea dx, msg1
	mov ah, 9
	int 21h
	
	newline

	lea dx, msg2
	mov ah, 9
	int 21h
	
	newline

	lea dx, max_len
	mov ah, 10
	int 21h

	cld
	lea si, buffer
	newline

	lea dx, msg3
	mov ah, 9
	int 21h

	newline

separate_numbers:
	;we iterate through every character of the input string
	lea di, number
	get_number:
		lodsb
		;if the current character is the ASCII code of ENTER, we have reached the end of the input
		cmp al, 0dh
		jz got_the_number	

		;when encountering a whitespace, we interpretate it as a delimitator between binary numbers
		cmp al, ' '
		jz got_the_number
		
		;we verify that the input string contains only some allowed characters
		cmp al, '0'
		jz binary_digit
	
		cmp al, '1'
		jz binary_digit

		;in the case that the input contains invalid data, we output an error message
		jmp error_input

		binary_digit:
		stosb
		jmp get_number
	
	got_the_number:
		;if the number has no digits, we iterate the string till we find a valid binary number
		;this condition will become true in the case of multiple whitespaces between binary numbers
		cmp di, offset number
		jz separate_numbers
		
		;cx will contain the number of characters the binary number has in string representation
		mov cx, di
		sub cx, offset number
		
		call ConvertBase16
		newline
	
	;if the current character is ENTER, then we have reached the end of the string
	cmp al, 0dh
	jnz separate_numbers

	jmp end_program	

	error_input:
		mov ah, 9
		lea dx, error_message
		int 21h

	end_program:
	mov ax, 4c00h
	int 21h
code ends
end start
