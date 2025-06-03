global _start

section .text

_start:
    mov rax, 60         ; System call number for exit
    xor rdi, 2          ; Exit code (0)
    syscall             ; Make the system call
