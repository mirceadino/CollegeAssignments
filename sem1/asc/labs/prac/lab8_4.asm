ASSUME CS:CODE, DS:DATA

DATA SEGMENT
	buffer db 5 dup(?)
	newline db 10, 13, '$'
	dot db '.', '$'
	day0 db " Sunday$"
	day1 db " Monday$"
	day2 db " Tuesday$"
	day3 db " Wednesday$"
	day4 db " Thursday$"
	day5 db " Friday$"
	day6 db " Saturday$"
	TEN dw 10
DATA ENDS

CODE SEGMENT

print MACRO buffer
	push ax
	push dx
	mov ah, 09h
	lea dx, buffer
	int 21h
	pop dx
	pop ax
ENDM

println MACRO buffer
	print buffer
	print newline
ENDM

printday MACRO day
	print day$day$
ENDM

number_to_str MACRO number, buffer
	save_registers:
	push ax
	push bx
	push cx
	push dx
	push di
	
	mov ax, number
	mov cx, 1
	push '$'
	divide:
		mov dx, 0
		idiv TEN
		add dx, '0'
		push dx
		inc cx
		cmp ax, 0
		jne divide
	
	lea di, buffer

	remake:
		pop ax
		stosb
		loop remake
	
	restore_registers:
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
ENDM

start:
	mov ax, data
	mov ds, ax
	mov es, ax
	
get_date:
	mov ah, 2Ah
	int 21h
	
	mov ah, 0
	push ax
	
print_all_date:
	push cx
	mov ax, 0
	mov al, dh
	push ax
	mov al, dl
	push ax
	
	mov cx, 3
	
	print_date:
		pop ax
		number_to_str ax, buffer
		print buffer
		cmp cx, 1
		je reloop
		print dot
		reloop:
		loop print_date

print_day_of_week:
	pop ax
	
	cmp ax, 0
	je print_day0
	cmp ax, 1
	je print_day1
	cmp ax, 2
	je print_day2
	cmp ax, 3
	je print_day3
	cmp ax, 4
	je print_day4
	cmp ax, 5
	je print_day5
	cmp ax, 6
	je print_day6
	
print_day0:
	print day0
	jmp finish
	
print_day1:
	print day1
	jmp finish
	
print_day2:
	print day2
	jmp finish
	
print_day3:
	print day3
	jmp finish
	
print_day4:
	print day4
	jmp finish
	
print_day5:
	print day5
	jmp finish
	
print_day6:
	print day6
	jmp finish

finish:
	mov ax, 4C00h
	int 21h
	
CODE ENDS
END start
