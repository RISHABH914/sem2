.section .text
.global solve

#%r8 for original size,r9 for storing count of votes,r10 for storing the candidate
#r11 for i of the loop
solve:
    movq %rdi,%r8       #storing original n to r8 though this is unnecessary
    movq $0,%r9         #starting count of votes from 0
    movq $0,%r11        #starting from index 0
    movq $-1,%r10       #initialsing candidate with -1

.loop:
    cmpq %r8,%r11       #base case/stopping condition for the loop
    jge .check

    cmpq $0,%r9         #if count of votes==0 then current element is the new candidate
    je .newcandidate

    cmpq (%rsi,%r11,8),%r10     #if current element is equl to the candidate increase the count of votes
    je .increasecount

    decq %r9                #otherwise decrease the count of votes
    incq %r11               #increase i
    jmp .loop               #loop again

.newcandidate:
    movq (%rsi,%r11,8),%r10     #store current element as the candidate
    movq $1,%r9                 #reset count of votes as 1
    incq %r11                   #increase i
    jmp .loop                   #loop again

.increasecount:
    incq %r9                    #increase count of votes
    incq %r11                   #increase i
    jmp .loop                   #loop again

.check:
    movq $0,%r11        #resetting i to 0 to finally check the validity of the answer
    movq $0,%r9         #for storing count
    movq %rdi,%rax      #rax will be storing n
    sarq $1,%rax        #dividing n by 2 so that checking becomes easier for (n/2)


#basically finally finding the no of time candidate is coming and if it is greater than (n/2) then it is the answer
.checkloop:
    cmpq %rdi,%r11      #base case for checking loop
    jge .finaldone      #return the answer finally 

    cmpq %r10,(%rsi,%r11,8)     #compare candidate with current element
    je .increase                #if current element is equal to candidate go to increase

    incq %r11               #increase i
    jmp .checkloop          #loop again

.increase:
    incq %r9            #increase the count
    incq %r11           #increase i
    jmp .checkloop      #loop again

.finaldone:
    cmpq %rax,%r9       #comapre the total count of candidate to (n/2)
    jg .returncan       #if its greater than (n/2) then return the candidate

    movq $-1,%rax       #otherwise return -1
    ret

.returncan:
    movq %r10,%rax      #moving candidate variable value to rax to return it 
    ret


