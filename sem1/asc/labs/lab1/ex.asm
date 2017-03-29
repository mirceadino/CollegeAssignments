ASSUME cs: code, ds:data
   ;spunem asamblorului care sunt segmentele folosite de noi
data SEGMENT 
   ;data - segmentul de date in care vom defini variabilele
   a dw 1
   b dw 14
   c dw ?
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   ; .......
   ;aici avem instructiunile programului nostru
   mov ax,a
   add ax,b
   mov c,ax
   ;........
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start
