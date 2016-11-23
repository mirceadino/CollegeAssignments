"""
Problem 13
Determine the n-th element of the sequence 1,2,3,2,5,2,3,7,2,3,2,5,... obtained from the
sequence of natural numbers by replacing composed numbers with their prime divisors,
without memorizing the elements of the sequence

Input: n - natural number, greater than zero, which represents the position of the 
required number
Output: prints a corresponding message if the input is not a natural number greater 
than zero, or the nth element in the sequence otherwise
"""

def is_prime(n):
    '''
    Description: checks whether a natural number is prime or not
    Input: n - natural number, the number to check for primality
    Output: True - if n is prime; False - otherwise
    '''

    # Return False for some tricky cases

    if n <= 1:
        return False

    # Check for divisors less than the number; if a divisor is found, then the number isn't
    # prime and return False

    for i in range(2, n):
        if n%i == 0:
            return False

    # There's no reason to believe the number isn't prime, so return True

    return True

def find_nth_element(n):
    '''
    Description: finds the nth element of the given sequence
    Input: n - natural number greater than zero, ...
    Output: the value of the nth element of the sequence
    '''
    
    # We consider 1 as the first number of the given sequence

    lastNumberIndex = 1 # the index of the reached termen in the given sequence
    currentNumber = 2   # the reached number in the simple sequence of natural numbers
    lastNumber = 1      # the last number of the given sequence

    # If necessary, we go to the next number, count the prime divisors if it's composite,
    # or the number itself if it's prime; we stop when we counted enough numbers

    while lastNumberIndex != n:
        # Check if currentNumber is composite; if it is, decompose it, else simply count it
        
        if not is_prime(currentNumber):
            # Number is composite, so iterate through the numbers below to find the prime
            # divisors

            for divisor in range(2, currentNumber):
                if currentNumber%divisor == 0 and is_prime(divisor):
                    # Count a prime divisor
                    
                    lastNumberIndex += 1
                    lastNumber = divisor

                    if lastNumberIndex == n:
                        break
                    
        else:
            # Number is prime, so count the number itself
            
            lastNumberIndex += 1
            lastNumber = currentNumber

        # Go to the next number in the sequence

        currentNumber += 1

    return lastNumber

def main():
    '''
    Description: main program which reads input, solves the problem, prints output
    '''
    
    # Read input
    
    n = int(input("Enter n: "))

    # Check validity of the input and try to read the number again if n is invalid

    while n < 1:
        # The input is invalid, so print a corresponding message

        print("The number is invalid")
    
        n = int(input("Enter n: "))

    # The number passed the validity check, so find and print the solution

    solution = find_nth_element(n)

    print("The solution is {0}".format(solution))

main()

"""
Tests:
-3 > The number is invalid + Enter n: 
-1 > The number is invalid + Enter n:
 0 > The number is invalid + Enter n:
 1 > The solution is 1
 2 > The solution is 2
 3 > The solution is 3
 4 > The solution is 2
 5 > The solution is 5
 6 > The solution is 2
 7 > The solution is 3
 8 > The solution is 7
 9 > The solution is 2
10 > The solution is 3
11 > The solution is 2
12 > The solution is 5
13 > The solution is 11
"""
