# Write Answers for part 2 here
roll_no=2024101070

is_odd = lambda d:(d%2)

while roll_no>0:
    d=roll_no%10
    roll_no//=10
    if(is_odd(d)):
        print(d)