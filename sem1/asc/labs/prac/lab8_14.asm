ASSUME CS:CODE, DS:DATA

DATA SEGMENT
	msgreaddir1 db "Read first directory: $"
	msgreaddir2 db "Read second directory: $"
	msgdone db "Done!$"
	maxlen equ 20
	mdirname db maxlen
	ldirname db ?
	dirname db maxlen dup(?)
	dir1 db maxlen dup(?)
	dir2 db maxlen dup(?)
	newline db 10, 13, '$'
	root db "..",0
DATA ENDS

CODE SEGMENT

printproc PROC
	; procedure to print a string
	; DS:DX = points to the message to be printed
	push ax
	mov ah, 09h
	int 21h
	pop ax
RET
ENDP

print MACRO buffer
	lea dx, buffer
	call printproc
ENDM

println MACRO buffer
	print buffer
	print newline
ENDM

read MACRO buffer
	mov ah, 0Ah
	lea dx, buffer
	int 21h
ENDM

copy MACRO a, b, n
	mov ch, 0
	mov cl, n
	lea si, a
	lea di, b
	rep movsb
ENDM

read_directory MACRO msgdir, dir
	print msgdir
	read mdirname
	print newline
	mov bh, 0
	mov bl, ldirname
	mov dirname[bx], 0
	copy dirname, dir, ldirname
ENDM

create_directory MACRO dir
	mov ah, 39h
	lea dx, dir
	int 21h
ENDM

start:
	mov ax, data
	mov ds, ax
	mov es, ax
	
read_directories:
	read_directory msgreaddir1, dir1
	read_directory msgreaddir2, dir2

create_directories:
	create_directory dir1
	mov ah, 3Bh
	lea dx, dir1
	int 21h
	create_directory dir2
	
return_to_root:
	mov ah, 3Bh
	lea dx, root
	int 21h
	print msgdone

finish:
	mov ax, 4C00h
	int 21h
CODE ENDS
END start
