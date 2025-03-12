.section .text
.global solve

#r8 for pointer of string,r9 for original size,r10 for i in loop
solve:
    movq %rdi,%r8
    movq %rsi,%r9
    decq %r9
    movq $0,%r10
    movq $1,%rax

.loop:
    cmpq %r10,%r9
    jl .done

    movb (%rdi,%r10,1),%r11b
    cmpb %r11b,(%rdi,%r9,1)
    je .continue

.false:
    movq $0,%rax
    ret
    
.continue:
    decq %r9
    incq %r10
    jmp .loop

.done:
    ret
