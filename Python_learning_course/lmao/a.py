""" while True:
    try:
        age = int(input('What is your age? '))
        10/age
    except ValueError:
        print('Please enter a number')
    except ZeroDivisionError:
        print('Please enter age higher than 0')
    else:
        print('thank you')
        break
    finally:
        print('ok i am done') """


""" def make_list(num):
    result = []
    for i in range(num):
        result.append(i*2)
    return result


print(make_list(100)) """

from time import time

""" def performance(fn):
    def time_taken(*args, **kwargs):
        t1 = time()
        result = fn(*args,**kwargs)
        t2 = time()
        print(f'took {t2-t1} s')
        return result
    return time_taken

@performance
def generator_function(num):
    print('1')
    for i in range(num):
        i*5

@performance
def gen2(num):
    print("2")
    for i in list(range(num)):
        i*5

generator_function(100000000000)
gen2(100000000000) """

""" def fibinachi(num):
    number = 0
    number2 = 1
    for i in range(num):
        temp = number
        number = number2
        number2 = number2 + temp
 
        print(number)

fibinachi(10) """

