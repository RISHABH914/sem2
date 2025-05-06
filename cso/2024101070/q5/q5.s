.text
.global solve
solve:
    pushq %rbp               #saving the base pointer in the stack
    movq %rsp, %rbp         #set the base pointer to the current stack pointer
    
    movq $0, %r8            # left = 0
    movq %rsi, %r9          # right = n
    decq %r9                #right = n-1
    
.while_loop:
    cmpq %r9, %r8           # left < right
    jge .end_while          #if not then jump to .end_while
    
    movq %r9, %rax          # mid calculation
    subq %r8, %rax
    shrq $1, %rax
    addq %r8, %rax
    movq %rax, %rcx         # %rcx = mid
    
    cmpq $0, %rcx           # mid > 0?
    jle .check_left_edge    #if not then go to .check_left_edge
    
    cmpq %rsi, %rcx         # mid < n-1?
    jge .check_right_edge   #if not then go to .check_right_edge
    
    # Normal case
    movswq (%rdi,%rcx,2), %rdx    # arr[mid] to %rdx
    movswq -2(%rdi,%rcx,2), %rbx  # arr[mid-1] to %rbx
    movswq 2(%rdi,%rcx,2), %rax   # arr[mid+1] to %rax
    
    cmpq %rbx, %rdx         # arr[mid] > arr[mid-1]?
    jle .not_peak1          #if no, then not a peak
    cmpq %rax, %rdx         # arr[mid] > arr[mid+1]?
    jle .not_peak1          #if not then, not a peak
    
    movw %dx, %ax           # Return peak
    jmp .end_function

#for checking which side to go after confirming that its not a peak
.not_peak1:
    cmpq %rax, %rdx         # arr[mid] < arr[mid+1]?
    jl .go_right             # If yes, peak is on right
    movq %rcx, %r9          # Otherwise peak is on left
    jmp .while_loop         # loop over it

#to change left to mid+1
.go_right:
    leaq 1(%rcx), %r8       # left = mid + 1
    jmp .while_loop
    
#when mid==0 then check with mid+1 and if its smaller than mid then its a peak and dont acces mid-1
.check_left_edge:            # mid == 0 case
    movswq (%rdi), %rdx     # arr[0]
    movswq 2(%rdi), %rax    # arr[1]
    cmpq %rax, %rdx         # arr[0] > arr[1]?
    jg .return_left
    movw %ax, %ax           # Return arr[1] if it's greater
    jmp .end_function


.return_left:
    movw %dx, %ax           # Return arr[0]
    jmp .end_function
    
#for mid=n-1 check with mid-1 and dont aceess mid+1
.check_right_edge:           # mid == n-1 case
    movswq (%rdi,%rcx,2), %rdx    # arr[mid]
    movswq -2(%rdi,%rcx,2), %rbx  # arr[mid-1]
    cmpq %rbx, %rdx         # arr[mid] > arr[mid-1]?
    jle .end_while
    movw %dx, %ax
    jmp .end_function
    
#return arr left
.end_while:
    movswq (%rdi,%r8,2), %rax     # Load arr[left]
    movw %ax, %ax
    
.end_function:
    movq %rbp, %rsp
    popq %rbp
    ret