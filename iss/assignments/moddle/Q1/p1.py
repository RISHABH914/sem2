# Write Answers for part 1 here
roll_no=2024101070
is_prime = lambda d:d in {2,3,5,7}

while roll_no>0:
    d=roll_no%10
    roll_no//=10        # // is used for integer division otherwise it converts to float
    if(is_prime(d)):
        print(d)



