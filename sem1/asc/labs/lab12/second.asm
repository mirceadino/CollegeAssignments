; Problem 14 - Secondary module

assume cs:code, ds:data

data segment public
data ends

code segment public
public suffix
suffix:
; input: bx - stores the near address of the first string
;        si - stores the near address of the second string
;        cx - the length of the first string
;        dx - the length of the second string
; output: ax - the length of the longest suffix of the two strings
; other registers are not altered
start:
	store_registers:
		push bx
		push cx
		push dx
		push si
		
	setup:
		add bx, cx ; get to the end of the first string
		dec bx
		add si, dx ; get to the end of the second string
		dec si
		mov ax, 0 ; store the length of the longest suffix
		
	repeat:
		; compare current characters in the strings
		push dx
		mov dl, byte ptr [bx]
		mov dh, byte ptr [si]
		cmp dl, dh
		pop dx
		jne restore_registers ; if they don't match, finish
		inc ax ; match was found, so increase ax
		dec bx 
		dec si
		dec cx
		dec dx
		cmp cx, 0
		je restore_registers ; if the first string ended, finish
		cmp dx, 0
		je restore_registers ; if the second string ended, finish
		jmp repeat
	
	restore_registers:
		pop si
		pop dx
		pop cx
		pop dx
ret

code ends
end start
