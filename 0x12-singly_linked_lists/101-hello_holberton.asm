section .data
    hello db "Hello, Holberton", 0
    format db "%s", 10, 0

section .text
    global main

main:
    ; Call printf with the message and format string
    mov rdi, format
    mov rsi, hello
    xor rax, rax ; Clear RAX for printf return value
    call printf

    ; Exit the program
    mov rax, 60 ; syscall number for exit
    xor rdi, rdi ; status code 0
    syscall

section .bss
    resb 8 ; Reserve space for printf return value
