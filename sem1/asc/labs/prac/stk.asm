; PROBLEMA MIRCEA
ASSUME CS:CODE, DS:DATA, ES:DATA

DATA SEGMENT

    MAX_SIZE_BUFFER DB 100
    SIZE_BUFFER DB ?
    BUFFER DB 100 DUP(0)
    END_OF_BUFFER DW ?
    FILE_NAME DB 100 DUP(0)
    FILE_HANDLE DW ?
    TABLEA DB '0123456789ABCDEF'
    MESSAGE_FILE_NAME DB 'YOUR FILE: $'
    MESSAGE_RESULTS DB 'RESULTS: $'
    ERROR_FILE_NOT_FOUND DB 'ERROR FILE NOT FOUND! $'

DATA ENDS

CODE SEGMENT
START:

    SET_DATA_ADDRESS:
        PUSH DATA
        POP DS
        PUSH DATA
        POP ES

    LEA DX, MESSAGE_FILE_NAME
    CALL PRINT_STRING

    CALL READ_STRING

    LEA SI, BUFFER
    LEA DI, FILE_NAME
    MOV CL, SIZE_BUFFER
    MOV CH, 0
    CALL COPY_STRING

    MOV CL, SIZE_BUFFER
    MOV CH, 0
    LEA DI, FILE_NAME
    CALL PREPARE_STRING

    CALL OPEN_FILE
    JC PRINT_ERROR
    MOV FILE_HANDLE, AX

    CALL PRINT_NEW_LINE

    LEA DX, MESSAGE_RESULTS
    CALL PRINT_STRING

    READ_PROCESS:
        CALL READ_FILE
            PUSH AX
        LEA SI, BUFFER
        MOV CX, AX
        ADD SI, CX
        INC SI
        MOV END_OF_BUFFER, SI
        LEA SI, BUFFER
        GET_RESULT:
            MOV DX, 0
            CALL GET_HEXA ; DX - HEX NUMBER
            CALL CHECK_PRIME ; BX - 1 IF TRUE, 0 IF FALSE
            CMP BX, 1
            JE PRINT_DX
            JNE CONTINUE

            PRINT_DX:
                CALL PRINT_WORD
                CALL PRINT_SPACE
            JMP CONTINUE

            CONTINUE:
            CMP SI, END_OF_BUFFER
        JNE GET_RESULT

            POP AX
        CMP AX, 100
    JE READ_PROCESS

    JMP EXIT_PROGRAM

    PRINT_ERROR:
        CALL PRINT_NEW_LINE
        LEA DX, ERROR_FILE_NOT_FOUND
        CALL PRINT_STRING

    EXIT_PROGRAM:
        MOV AX, 4C00H
        INT 21H

    PRINT_SPACE PROC
            PUSH AX
            PUSH DX
        MOV AH, 02H
        MOV DL, ' '
        INT 21H
            POP DX
            POP AX
        RET
    PRINT_SPACE ENDP

    PRINT_NEW_LINE PROC
            PUSH AX
            PUSH DX
        MOV AH, 02H
        MOV DL, 0AH
        INT 21H
            POP DX
            POP AX
        RET
    PRINT_NEW_LINE ENDP

    PRINT_WORD PROC
    ; DX - WORD
        MOV CX, 4
        PRINT_HEXA_DIGIT:
                PUSH CX
            PUSH DX
            AND DX, 0F000H
            MOV CL, 12
            SHR DX, CL
            LEA BX, TABLEA
            XCHG DX, AX
            XLAT TABLEA
            XCHG AX, DX
            MOV AH, 02H
            INT 21H
            POP DX
            MOV CL, 4
            SHL DX, CL
                POP CX
        LOOP PRINT_HEXA_DIGIT

        RET
    PRINT_WORD ENDP

    PRINT_STRING PROC
    ; DX - POINTER STRING
            PUSH AX
        MOV AH, 09H
        INT 21H
            POP AX
        RET
    PRINT_STRING ENDP

    CHECK_PRIME PROC
    ; DX - NUMBER
            PUSH DX
        CMP DX, 2
        JE RETURN_TRUE
        MOV AX, DX
        MOV DX, 0
        MOV BX, 2
        START_CHECK_PRIME:
            MOV CX, AX
            DIV BX ; DX - REST ; AX - NUMBER
            CMP DX, 0
            JE RETURN_FALSE
            MOV AX, CX
            MOV DX, 0
            INC BX
            CMP AX, BX
            JE RETURN_TRUE
        JNE START_CHECK_PRIME
        RETURN_FALSE:
            MOV BX, 0
        JMP END_CHECK_PRIME
        RETURN_TRUE:
            MOV BX, 1
        JMP END_CHECK_PRIME
        END_CHECK_PRIME:
                POP DX
            RET
    CHECK_PRIME ENDP

    GET_HEXA PROC
    ; SI - POINTER TO START NUMBER
    ; CX - SIZE STRING
    ; DX - NUMBER
        GET_DIGIT:
            LODSB ; AL - CHR
            DEC CX
            CMP AL, ' '
            JE END_GET_HEXA
            CMP SI, END_OF_BUFFER
            JE END_GET_HEXA
            CMP AL, 'A'
            JE STORE_A
            CMP AL, 'B'
            JE STORE_B
            CMP AL, 'C'
            JE STORE_C
            CMP AL, 'D'
            JE STORE_D
            CMP AL, 'E'
            JE STORE_E
            CMP AL, 'F'
            JE STORE_F
            JMP STORE_DIGIT_NORMAL

        STORE_A:
            MOV AL, 0AH
        JMP STORE_DIGIT

        STORE_B:
            MOV AL, 0BH
        JMP STORE_DIGIT

        STORE_C:
            MOV AL, 0CH
        JMP STORE_DIGIT

        STORE_D:
            MOV AL, 0DH
        JMP STORE_DIGIT

        STORE_E:
            MOV AL, 0EH
        JMP STORE_DIGIT

        STORE_F:
            MOV AL, 0FH
        JMP STORE_DIGIT

        STORE_DIGIT_NORMAL:
            SUB AL, '0'
        JMP STORE_DIGIT

        STORE_DIGIT:
            MOV AH, 0
                PUSH CX
            XCHG AX, DX
            XCHG DX, CX
            MOV BX, 16
            MUL BX
            XCHG CX, DX
            XCHG DX, AX
                POP CX
            ADD DX, AX
        JMP GET_DIGIT

        END_GET_HEXA:
            RET

    GET_HEXA ENDP

    READ_FILE PROC
            PUSH BX
            PUSH CX
            PUSH DX
        MOV AH, 3FH
        MOV BX, FILE_HANDLE
        MOV CX, 100
        LEA DX, BUFFER
        INT 21H
            POP DX
            POP CX
            POP BX
        RET
    READ_FILE ENDP

    OPEN_FILE PROC
            PUSH DX
        MOV AH, 3DH
        MOV AL, 2
        LEA DX, FILE_NAME
        INT 21H
            POP DX
        RET
    OPEN_FILE ENDP

    PREPARE_STRING PROC
    ; DI - POINTER TO STRING
    ; CX - SIZE
            PUSH AX
            PUSH CX
            PUSH DI
        ADD DI, CX
        MOV AL, '$'
        STOSB
            POP DI
            POP CX
            POP AX
        RET
    PREPARE_STRING ENDP

    COPY_STRING PROC
    ; SI - SOURCE
    ; DI - DESTINATION
    ; CX - SIZE
        REP MOVSB
        RET
    COPY_STRING ENDP

    READ_STRING PROC
            PUSH AX
            PUSH DX
        MOV AH, 0AH
        LEA DX, MAX_SIZE_BUFFER
        INT 21H
            POP DX
            POP AX
        RET
    READ_STRING ENDP

CODE ENDS
END START
