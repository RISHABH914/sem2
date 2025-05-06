.section .text
.global find_lonely_number
#for finding lonely people
# rdi = pointer to arr
# rsi = pointer to fre
# rdx = size of arr
#r8 is pointer to arr,r9 pointer to freq,r10 to size counter
find_lonely_number:

    movq %rdi, %r8              #storing r8 to point to arr
    movq %rsi, %r9              #stroing r9 to pointer to freq
    movq %rdx, %r10             #storing r10 as size of the remaining array

    # First Loop: make the frequency array
.build_freq:
    cmpq $0, %r10
    je .search_lonely    # If size == 0, move to .search_lonely

    movq (%r8), %rax    # storing arr[i] to rax
    leaq (%r9, %rax, 8), %rcx  # storing Address of freq[arr[i]] in rcx

    incq (%rcx)         # Increment frequency count at freq[arr[i]]

    addq $8, %r8        # Move to next element in arr
    decq %r10           # Decrement size counter
    jmp .build_freq

    # for finding the lonely number having frequency as 1
.search_lonely:
    movq $0, %r10       # Reset index counter

.find_loop:
    cmpq $10000, %r10
    jge .done           # If index >= 10000, stop since the size of frequeny array is only 10000 since the elements can't be bigger than this

    movq (%r9, %r10, 8), %rax   # storing freq[index] into rax
    cmpq $1, %rax                # Check if frequency is exactly 1
    jne .next_index               # If not, continue searching

    movq %r10, %rax   # Store lonely number in rax
    jmp .done         # Found it, exit

.next_index:
    incq %r10          # Move to next index
    jmp .find_loop

.done:
    ret

