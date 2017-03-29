ASSUME CS:CODE, DS:DATA

DATA SEGMENT
	x db 1
	y db 1
	EXIT db 'p'
	UP db 'w'
	DOWN db 's'
	LEFT db 'a'
	RIGHT db 'd'
	rules db "== MEGA FUN GAME ==",10,13,10,13
		db "All you can do is move around.",10,13
	      db "Press 'p' to exit.",10,13
	      db "Press 'w' to move up;",10,13
	      db "      's' to move down;",10,13
	      db "      'a' to move left;",10,13
	      db "      'd' to move right.",10,13,10,13,'$'
	board db '*-----------------------------------*',10,13
	cols equ $-board-3
	      db '|                                   |',10,13
	      db '|                                   |',10,13
	      db '|                                   |',10,13
	      db '|                                   |',10,13
	      db '|                                   |',10,13
	      db '|                                   |',10,13
	      db '|                                   |',10,13
	      db '|                                   |',10,13
		db '*-----------------------------------*',10,13,'$'
	size_board equ $-board
	rows equ (size_board-1)/(cols+2)-1
	board_with_player db size_board dup(?)
	scoreboard db 10,13,"Score: 0",'$'
	newscreen db 10,13,10,13,10,13,'$'
DATA ENDS

CODE SEGMENT

copy MACRO a, n, b
	push si
	push di
	push cx
	lea si, a
	lea di, b
	mov cx, n
	rep movsb
	pop cx
	pop di
	pop si
ENDM

print MACRO buffer
	push ax
	push dx
	mov ah, 09h
	lea dx, buffer
	int 21h
	pop dx
	pop ax
ENDM

draw MACRO board, x, y, chr
	mov al, x
	mov ah, 0
	mov bl, cols
	add bl, 3
	imul bl
	add al, y
	adc ah, 0
	mov bx, ax
	mov board[bx], chr
ENDM

start:
	mov ax, data
	mov ds, ax
	mov es, ax
play:
set_player_on_board:
	copy board, size_board, board_with_player
	draw board_with_player, x, y, 'x'
	print rules
	print board_with_player
	print scoreboard
	print newscreen
get_option:
	mov ah, 07h
	int 21h
	cmp al, DOWN
	je go_down
	cmp al, UP
	je go_up
	cmp al, LEFT
	je go_left
	cmp al, RIGHT
	je go_right
	cmp al, EXIT
	je finish
	jmp get_option
	go_down:
		cmp x, rows-1
		je get_option
		inc x
		jmp check
	go_up:
		cmp x, 1
		je get_option
		dec x
		jmp check
	go_left:
		cmp y, 1
		je get_option
		dec y
		jmp check
	go_right:
		cmp y, cols-1
		je get_option
		inc y
		jmp check
check:
	jmp play
finish:
	mov ax, 4C00h
	int 21h
CODE ENDS
END start
