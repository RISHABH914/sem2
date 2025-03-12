# Write Answers for part 5 here
roll_no=2024101070

operation = lambda d:d in {0,2,3,4,6,8,9}

cnt=0
while roll_no>0:
    dig=roll_no%10
    roll_no//=10
    if(operation(dig)):
        cnt+=1
print(cnt)