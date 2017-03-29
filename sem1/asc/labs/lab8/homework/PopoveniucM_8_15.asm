;Popoveniuc Mircea, gr. 911, 26.11.2015, homework for lab 8, problem 15
assume cs:code, ds:data

data segment
	readFileMsg db "Type the name of the file: $"
	newline db 13, 10, '$'
	cantFindFileMsg db "Can't find the file.", 13, 10, '$'
	mult13Msg db "Size is a multiple of 13.", 13, 10, '$'
	notMult13Msg db "Size is not a multiple of 13.", 13, 10,"Inserting zero bytes.", 13, 10, '$'
	maxLenFileName db 21
	lenFileName db ?
	fileName db 20 dup(?)
	fileSize dw ?
	lenBuffer db 100
	buffer db 100 dup(?)
	addedChars db 13 dup(0)
data ends

code segment
start:
	push data
	pop ds
	
read:
	; print readFileMsg
	mov ah, 09h
	lea dx, readFileMsg
	int 21h
	
	; read file's name
	mov ah, 0Ah
	lea dx, maxLenFileName
	int 21h
	
	; print a newline after reading
	mov ah, 09h
	lea dx, newline
	int 21h
	
make_ASCIIZ:
	; make fileName an ASCIIZ string
	mov al, lenFileName
	cbw
	lea si, fileName
	add si, ax
	mov byte ptr [si], 0

open_file:
	; open file
	mov ax, 3D02h
	lea dx, fileName
	int 21h
	
	jc error_cant_open
	
get_size:
	; read the file
	; if opening was successful, in 'ax' we have the handle of the file
	; we move the handle in 'bx' in order to use 'ax' for other purposes
	mov bx, ax
	mov fileSize, 0 ; we use it to retain the size of the file
	
	repeat:
		; get the content of the file in a buffer
		mov ah, 3Fh
		mov cl, lenBuffer
		mov ch, 0
		lea dx, buffer
		int 21h
		
		; count the number of read characters
		add fileSize, ax
		
		; if the buffer is full, repeat; otherwise, we're at the end of the file
		cmp al, lenBuffer
		je repeat
	
check_multiple_13:
	; divide size by 13 and retain the remainder
	mov ax, fileSize
	cwd
	mov cx, 13
	div cx
	
	; compare the remainder
	cmp dx, 0
	jne add_null_bytes
	
	; print mult13Msg if the remainder is 0 and exit the program
	mov ah, 09h
	lea dx, mult13Msg
	int 21h	
	
	jmp finish
	
add_null_bytes:
	; put the needed characters to add in 'cx'
	mov cx, 13
	sub cx, dx
	
	; print notMult13Msg
	mov ah, 09h
	lea dx, notMult13Msg
	int 21h
	
	; add the null bytes - only the first 'cx' characters from addedChars are added
	lea dx, addedChars
	mov ah, 40h
	int 21h
	
	jmp finish

error_cant_open:
	; print readFileMsg
	mov ah, 09h
	lea dx, cantFindFileMsg
	int 21h
	
	jmp finish

finish:
	mov ax, 4C00h
	int 21h
code ends
end start
