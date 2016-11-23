'''
Problem 2
Generate the first prime number larger than a given natural number n.
'''

n = int(input("Read n: "))

# Check the validity of the input:
# if n is natural, print the result;
# display an error message otherwise

if n >= 0:
    nrDivisors = 0
    initial_n = n

    # While the successor isn't prime (doesn't have only 2 divisors), get to the
    # next successor
                
    while nrDivisors != 2:
        n += 1

        nrDivisors = 0

        for i in range(1, n+1):
            if n % i == 0:
                nrDivisors += 1

    # Print result

    print("The first prime larger than {0} is {1}".format(initial_n, n))

else:
    print("Invalid input")
