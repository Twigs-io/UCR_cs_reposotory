from functools import reduce
def capitalizes(string):
    return string.upper()
#1 Capitalize all of the pet names and print the list
my_pets = ['sisi', 'bibi', 'titi', 'carla']
print(list(map(capitalizes, my_pets)))



#2 Zip the 2 lists into a list of tuples, but sort the numbers from lowest to highest.
my_strings = ['a', 'b', 'c', 'd', 'e']
my_numbers = [5,4,3,2,1]
my_numbers.sort()
print(list(zip(my_strings,my_numbers)))

def over(item):
    if item > 50:
        return item
#3 Filter the scores that pass over 50%
scores = [73, 20, 65, 19, 76, 100, 88]
print(list(filter(over,scores)))

def reduces(item1, item2):
    return item1 + item2

#4 Combine all of the numbers that are in a list on this file using reduce (my_numbers and scores). What is the total?
print(reduce(reduces,(my_numbers+ scores)))