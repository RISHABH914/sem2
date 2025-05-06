.section .text
.global q1

#void solve(int n,int* res)
q1:
    movq $1,%r8 #r8 for current number in loop
    movq $0,%r9 #r9 for i in loop

.loop:
    cmpq %rdi,%r9
    jge .done

.checkfor2and7:
    movq $2,%rbx
    movq %r8,%rax
    cqto
    idivq %rbx
    cmpq $0,%rdx
    je .2then7

    movq %r8,%rax
    movq $7,%rbx
    cqto
    idivq %rbx
    cmpq $0,%rdx
    je .giveminus2

    movq %r8,(%rsi,%r9,8)
    jmp .increment

.giveminus2:
    movq $-2,(%rsi,%r9,8)
    jmp .increment

.2then7:
   movq %r8,%rax
   cqto
   movq $7,%rbx
   idivq %rbx
   cmpq $0,%rdx
   je .giveminus3

   movq $-1,(%rsi,%r9,8)
   jmp .increment

.giveminus3:
    movq $-3,(%rsi,%r9,8)
    jmp .increment

.increment:
    incq %r8
    incq %r9
    jmp .loop

.done:
    ret
