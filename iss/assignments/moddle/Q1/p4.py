# Write Answers for part 4 here
roll_no=2024101070

cnt=0
is_zero = lambda d:(d==0)
while roll_no>0:
    d=roll_no%10
    roll_no//=10
    if(is_zero(d)):
        cnt+=1

print(cnt)

