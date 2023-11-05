from random import randint
import sys

def randomgames(int1, int2):
    #generate a number 1-10
    #impuit form user
    if 0 < int1 < 11:
        if int1 == int2:
            print('you won')
            return True
    else:
        print('suck it')
        return False
    #check trhat input is a number 1-10
    if __name__ == '__main__':
        int2 = randint(1,10)
        while True:     
            try:
                int1 = int(input(f'Guess a number from {int1} to {int2}: '))
                if randomgames(int1, int2):
                    break
            except ValueError:
                print('oops')
                continue


randomgames(1,2)
# check if number is right guess otherwise as akagin
