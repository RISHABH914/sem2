.section .text
.global solve

# Recursive function to compute (n-r)! / r!
# %rdi = n, %rsi = r
solve:
    cmpq $0, %rsi         # if r == 0, return 1
    je .base_case        

    pushq %rdi            # Save n on stack
    pushq %rsi            # Save r on stack

    decq %rdi             # n = n - 1
    decq %rsi             # r = r - 1
    call solve            # solve(n-1, r-1)

    popq %r9             # Restore r and save to r9
    popq %r10            # Restore n and save to r10

    cmpq $0, %r9         # Ensure r is not zero before division
    je .done              # If r == 0, skip division

    imulq %r10, %rax      # Multiply result by n
    cqto
    idivq %r9           # Divide by r

.done:
    ret

.base_case:
    movq $1, %rax         # Base case: return 1
    ret
