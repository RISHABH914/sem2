# Write Answers for part 3 here
roll_no=2024101070

is_even=lambda d:(d+1)%2

while roll_no>0:
    dig=roll_no%10
    roll_no//=10
    if(is_even(dig)):
        print(dig)