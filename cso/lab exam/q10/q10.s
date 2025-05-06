.section .text
.global q10

q10:
    movq $0,%r8
    movq $0,%r9

.loop:
    cmpq %r8,%rdi
    jle .done

    movzbq (%rsi,%r8,1),%r10
    cmpq $41,%r10
    je .closenormal

    cmpq $125,%r10
    je .closecurly

    cmpq $93,%r10
    je .closesquare

    movq %r10,(%rdx,%r9,8);
    incq %r8
    incq %r9
    jmp .loop

.closenormal:
    movq %r9,%r11
    decq %r11

    cmpq $0,%r11
    jl .return0

    cmpq $40,(%rdx,%r11,8)
    je .continue

    movq $0,%rax
    ret

.closecurly:
    movq %r9,%r11
    decq %r11

    cmpq $0,%r11
    jl .return0

    cmpq $123,(%rdx,%r11,8)
    je .continue

    movq $0,%rax
    ret

.closesquare:
    movq %r9,%r11
    decq %r11

    cmpq $0,%r11
    jl .return0

    cmpq $91,(%rdx,%r11,8)
    je .continue

    movq $0,%rax
    ret

.continue:
    decq %r9
    incq %r8
    jmp .loop

.done:
    cmpq $0,%r9
    jne .return0

    movq $1,%rax
    ret

.return0:
    movq $0,%rax
    ret

