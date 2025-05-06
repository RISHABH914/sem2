.section .text
.global q12

checkprime:

    cmpq $2,%rdi
    je .creturn1
   cmpq $3,%rdi
   je .creturn1 
    movq %rsi,%r13
    movq %rdi,%rax
    cqto
    movq $2,%rbx
    idivq %rbx
    movq %rax,%r14
    movq $2,%r12

.cloop:
    cmpq %r12,%r14
    jle .creturn1

    movq %rdi,%rax
    cqto 
    idivq %r12
    cmpq $0,%rdx
    je .creturn0

    incq %r12
    jmp .cloop

.creturn0:
    movq $0,%rax
    ret

.creturn1:
    movq $1,%rax
    ret

powerof10:
    movq $0,%r12
    movq $1,%rax

.ploop:
    cmpq %r12,%rdi
    jle .done
    imulq $10,%rax
    incq %r12
    jmp .ploop

.done:
    ret

q12:
    movq %rdi,%r8
    movq %rsi,%r9
    call powerof10

    movq %rax,%r10
    movq $0,%r11

.loop:
    cmpq %r11,%r9
    jle .return1

    movq %r10,%rsi
    call checkprime

    cmpq $1,%rax
    jne .return0

    movq %rdi,%rax
    cqto
    movq $10,%rbx
    idivq %rbx

    imulq %r10,%rdx
    addq %rdx,%rax

    movq %rax,%rdi
    incq %r11
    jmp .loop

.return0:
    movq $0,%rax
    ret
.return1:
    movq $1,%rax
    ret