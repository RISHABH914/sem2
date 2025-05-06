.global q8

q8:
    movq $0,%r8
    movq %rdi,%r13
    decq %rdi

.loop:
    cmpq $0,%r8
    je .checkright

    cmpq %r8,%rdi
    je .checkforleft

    cmpq %r8,%r13
    jge .return

    movq %r8,%r9
    decq %r9
    movq (%rsi,%r8,8),%r10
    movq (%rsi,%r9,8),%r11
    cmpq %r10,%r11
    jg .swap

    movq %r8,%r9
    incq %r9
    movq (%rsi,%r8,8),%r10
    movq (%rsi,%r9,8),%r11
    cmpq %r10,%r11
    jg .swap

    addq $2,%r8
    jmp .loop

.swap:
    movq %r10,(%rsi,%r9,8)
    movq %r11,(%rsi,%r8,8)
    addq $2,%r8
    jmp .loop

.checkforleft:
    movq %r8,%r9
    decq %r9
    movq (%rsi,%r8,8),%r10
    movq (%rsi,%r9,8),%r11
    cmpq %r10,%r11
    jg .swap

   ret

.checkright:
    movq %r8,%r9
    incq %r9
    movq (%rsi,%r8,8),%r10
    movq (%rsi,%r9,8),%r11
    cmpq %r10,%r11
    jg .swap

    addq $2,%r8
    jmp .loop

.return:    
    ret

