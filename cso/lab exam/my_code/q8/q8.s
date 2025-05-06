.global q8

q8:
    movq $0,%r8
    movq %rdi,%r12
    decq %r12

.loop:
    cmpq $0,%r8
    je .checkforright

    cmpq %r8,%r12
    je .checkforleft

    cmpq %r8,%rdi
    jle .shoudlnotcome

    movq %r8,%r9
    decq %r9
    movq (%rsi,%r8,8),%r10
    cmpq (%rsi,%r9,8),%r10
    jl .swap

    movq %r8,%r9
    incq %r9
    movq (%rsi,%r8,8),%r10
    cmpq (%rsi,%r9,8),%r10
    jl .swap

    addq $2,%r8
    jmp .loop

.checkforright:
    movq %r8,%r9
    incq %r9
    movq (%rsi,%r8,8),%r10
    cmpq (%rsi,%r9,8),%r10
    jl .swap

    addq $2,%r8
    jmp .loop

.checkforleft:
    movq %r8,%r9
    decq %r9
    movq (%rsi,%r8,8),%r10
    cmpq (%rsi,%r9,8),%r10
    jge .shoudlnotcome

    movq (%rsi,%r9,8),%r11
    movq %r10,(%rsi,%r9,8)
    movq %r11,(%rsi,%r8,8)
    ret

.swap:
    movq (%rsi,%r9,8),%r11
    movq %r10,(%rsi,%r9,8)
    movq %r11,(%rsi,%r8,8)
    addq $2,%r8
    jmp .loop


.shoudlnotcome:
    ret




