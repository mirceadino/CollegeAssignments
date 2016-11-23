# Write a program that reads two strictly positive integers and computes
# their greatest common divisor using the Euclidian algorithm.

# Read input.
a = int(input("Read the first number: "))
b = int(input("Read the second number: "))

# Check validity (a, b should be strictly positive):
# if numbers are invalid, print an error message,
# print the gcd otherwise.
if a <= 0 or b <= 0:
    print("Invalid input")

else:
    r = a%b
    
    while r != 0:
        a,b = b,r
        r = a%b

    print("GCD is " + str(b))
