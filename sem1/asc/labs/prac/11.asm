assume cs:code, ds:data
data segment
	msg db 'primul fisier: $'
	msg2 db 'al doiles fisier: $'
	msj db 'Ana are mere'
	l1 EQU $-msj
	maxFileName1 db 12
	lFileName1 db ?
	fileName db 12 dup(?)
	maxFileName2 db 12
	lFileName2 db ?
	fileName2 db 12 dup(?)
	newLine db 10,13,'$'
	buffer db 100 dup(?), '$'
	
	handle1 dw ?
	handle2 dw ?

data ends
code segment
start:
	mov ax,data
	mov ds,ax
	
	mov ah,09h
	mov dx, offset msg
	int 21h
	
	;read from the keyboard the name of the file unsing interrupt 21h, function 0ah
	mov ah, 0ah
	mov dx, offset maxFileName1
	int 21h
	; after the IHR is executed, the name of the file will ne stored in maxFileName+2= fileName
	;the byte from the offset maxFileName+1 = lFileNamewill store the lenght(in characers) of the fileName
	
	;we transform the file into ASCIIZ string(put a zero at the end)
	mov al, lFileName1
	xor ah, ah
	mov si, ax
	mov fileName[si], 0
	
	mov ah,09h
	mov dx, offset msg2
	int 21h
	
	;read from the keyboard the name of the file using interrupt 21h, function 0ah
	mov ah, 0ah
	mov dx, offset maxFileName2
	int 21h
	
	; we transform the file into ASCIIZ string(put a zero at the end)
	
	mov al, lFileName2
	xor ah,ah
	mov si, ax
	mov fileName2[si],0
	
	mov ah,3dh
	mov al,0
	mov dx,offset fileName
	int 21h
	
	mov handle1,ax
	
	mov ah,3dh
	mov al,1
	mov dx,offset fileName2
	int 21h
	
	mov handle2,ax
		
	
	goOn:
		mov ah,3fh
		mov bx,handle1
		mov cx,100
		mov dx,offset buffer
		int 21h
		
		mov si, ax	
		
		mov ah,40h
		mov bx,handle2
		mov cx,si
		mov dx,offset buffer
		int 21h
		
		cmp si,100
		je goOn
	
	mesaj:
		mov ah,40h
		mov bx,handle2
		mov cx,2
		mov dx,offset newLine
		int 21h	
			
		mov ah,40h
		mov bx,handle2
		mov cx,l1
		mov dx,offset msj
		int 21h
		
		mov ah, 3eh
		mov bx, handle1
		int 21h
		mov ah, 3eh
		mov bx, handle2
		int 21h
	
	mov ax,4C00h
	int 21h
	
code ends
end start

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
