assume cs:code, ds:data
data segment public
	sixteen dw 16
	tabHexa db '0123456789ABCDEF'
	extrn number:byte	
data ends

code segment public

public ConvertBase16

ConvertBase16:
	;converts a binary number given in its string representation 
	
	;we first save the general registers and the si register so that we can use them
	push ax	
	push bx
	push cx
	push dx
	push si

	mov ax, 0
	lea si, number

move_number_into_ax:
	shl ax, 1
	mov bl, byte PTR [si]
	sub bl, '0'
	mov bh, 0
	or ax, bx
	inc si
	loop move_number_into_ax
	
;we convert a number into base 16 by multiple divisions
convert_to_base_16:
	inc cx
	mov dx, 0
	div sixteen
	push dx
	mov dx, 0
	cmp ax, 0
	jz print_number
	jmp convert_to_base_16

;we print the number in base 16, character by character
print_number:
	pop ax
	lea bx, tabHexa
	xlat
	mov dl, al
	mov ah, 2
	int 21h
	loop print_number

	pop si
	pop dx
	pop cx
	pop bx
	pop ax

	ret

code ends
end
