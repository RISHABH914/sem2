.global q11

q11:
    movq $0,%r8
    movq $0,%r9     #r9 for stack

.loop:
    cmpq %r8,%rdi
    jle .done

    cmpq $0,%r9
    jle .giveminus1

    movq %r9,%r12
    decq %r12
    movq (%rdx,%r12,8),%r10
    cmpq %r10,(%rsi,%r8,8)
    jl .found

    decq %r9
    jmp .loop

.giveminus1:
    movq $-1,(%rcx,%r8,8)
    movq (%rsi,%r8,8),%r11
    movq %r11,(%rdx,%r9,8)
    incq %r9
    incq %r8
    jmp .loop

.found:
    movq %r10,(%rcx,%r8,8)
    movq (%rsi,%r8,8),%r10
    movq %r10,(%rdx,%r9,8);
    incq %r9
    incq %r8
    jmp .loop

.done:
    ret


