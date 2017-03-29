ASSUME CS:CODE, DS:DATA

DATA SEGMENT
	readmsg db "Type filename: $"
	newline db 10, 13, '$'
	mfilename db 20
	lfilename db ?
	filename db 21 dup(?)
	attributesmsg db "Attributes are: $"
	normalmsg db "Normal$"
	readonlymsg db "Read-only$"
	hiddenmsg db "Hidden$"
	systemmsg db "System$"
	archivemsg db "Archive$"
	nofilemsg db "No file was found.$"
DATA ENDS

CODE SEGMENT

print MACRO str
	push ax
	push dx
	mov ah, 09h
	lea dx, str
	int 21h
	pop dx
	pop ax
ENDM

println MACRO str
	push ax
	push dx
	mov ah, 09h
	lea dx, str
	int 21h
	mov ah, 09h
	lea dx, newline
	int 21h
	pop dx
	pop ax
ENDM

read MACRO buffer
	push ax
	push dx
	mov ah, 0Ah
	lea dx, buffer
	int 21h
	pop dx
	pop ax
ENDM

start:
	mov ax, data
	mov ds, ax

read_file_name:
	print readmsg
	read mfilename
	print newline
	
make_asciiz:
	mov ah, 0
	mov al, lfilename
	mov si, ax
	mov filename[si], 0

get_attributes:
	mov ah, 43h
	mov al, 00h
	lea dx, filename
	int 21h
	
check_error:
	jnc print_readonly

nofile:
	print nofilemsg
	jmp finish
	
print_readonly:
	mov bx, cx
	and bx, 01h
	cmp bx, 0
	je print_hidden
	println readonlymsg
	
print_hidden:
	mov bx, cx
	and bx, 02h
	cmp bx, 0
	je print_system
	println hiddenmsg
	
print_system:
	mov bx, cx
	and bx, 04h
	cmp bx, 0
	je print_archive
	println systemmsg
	
print_archive:
	mov bx, cx
	and bx, 20h
	cmp bx, 0
	je print_normal
	println archivemsg
	
print_normal:
	mov bx, cx
	and bx, 00h
	cmp bx, 0
	je finish
	println normalmsg
	je finish

finish:
	mov ax, 4C00h
	int 21h

CODE ENDS
END start
