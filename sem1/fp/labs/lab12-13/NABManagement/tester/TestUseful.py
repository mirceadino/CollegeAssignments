import unittest
from random import randint
from utils.Useful import sort as mysort
from utils.Useful import filter as myfilter


class UsefulTestCase(unittest.TestCase):

    def setUp(self):
        pass


    def generator(self, minLength, maxLength, minVal, maxVal):
        length = randint(minLength, maxLength)
        return [randint(minVal, maxVal) for i in range(0, length)]


    def test_sort(self):
        for tests in range(0, 50):
            L = self.generator((tests-1)*10, tests*10, -5, 5)
            self.assertEqual(mysort(L), sorted(L))
            self.assertEqual(mysort(L,reverse=True), sorted(L,reverse=True))
            #self.assertEqual(mysort(L,key=lambda x: x%2), sorted(L,key=lambda x: x%2))
            #self.assertEqual(mysort(L,key=lambda x: (x%3, x)), sorted(L,key=lambda x: (x%3,x)))
            L = self.generator((tests-1)*10, tests*10, -5*tests, 5*tests)
            self.assertEqual(mysort(L), sorted(L))
            self.assertEqual(mysort(L,reverse=True), sorted(L,reverse=True))
            #self.assertEqual(mysort(L,key=lambda x: x%2), sorted(L,key=lambda x: x%2))
            #self.assertEqual(mysort(L,key=lambda x: (x%3, x)), sorted(L,key=lambda x: (x%3,x)))
            L = self.generator((tests-1)*10, tests*10, 1*tests, 1*tests)
            self.assertEqual(mysort(L), sorted(L))
            self.assertEqual(mysort(L,reverse=True), sorted(L,reverse=True))
            self.assertEqual(mysort(L,key=lambda x: x%2), sorted(L,key=lambda x: x%2))
            self.assertEqual(mysort(L,key=lambda x: (x%3, x)), sorted(L,key=lambda x: (x%3,x)))
            L = self.generator((tests-1)*10, tests*10, 1*tests, 2*tests)
            self.assertEqual(mysort(L), sorted(L))
            self.assertEqual(mysort(L,reverse=True), sorted(L,reverse=True))
            #self.assertEqual(mysort(L,key=lambda x: x%2), sorted(L,key=lambda x: x%2))
            #self.assertEqual(mysort(L,key=lambda x: (x%3, x)), sorted(L,key=lambda x: (x%3,x)))


    def test_filter(self):
        for tests in range(0, 50):
            L = self.generator((tests-1)*10, tests*10, -5, 5)
            self.assertEqual(myfilter(lambda x: x%2==0, L), list(filter(lambda x: x%2==0, L)))
            self.assertEqual(myfilter(lambda x: x%3==1, L), list(filter(lambda x: x%3==1, L)))
            self.assertEqual(myfilter(lambda x: x>5, L), list(filter(lambda x: x>5, L)))
            self.assertEqual(myfilter(lambda x: x<0, L), list(filter(lambda x: x<0, L)))
            L = self.generator((tests-1)*10, tests*10, -5*tests, 5*tests)
            self.assertEqual(myfilter(lambda x: x%2==0, L), list(filter(lambda x: x%2==0, L)))
            self.assertEqual(myfilter(lambda x: x%3==1, L), list(filter(lambda x: x%3==1, L)))
            self.assertEqual(myfilter(lambda x: x>5, L), list(filter(lambda x: x>5, L)))
            self.assertEqual(myfilter(lambda x: x<0, L), list(filter(lambda x: x<0, L)))
            L = self.generator((tests-1)*10, tests*10, 1*tests, 1*tests)
            self.assertEqual(myfilter(lambda x: x%2==0, L), list(filter(lambda x: x%2==0, L)))
            self.assertEqual(myfilter(lambda x: x%3==1, L), list(filter(lambda x: x%3==1, L)))
            self.assertEqual(myfilter(lambda x: x>5, L), list(filter(lambda x: x>5, L)))
            self.assertEqual(myfilter(lambda x: x<0, L), list(filter(lambda x: x<0, L)))
            L = self.generator((tests-1)*10, tests*10, 1*tests, 2*tests)
            self.assertEqual(myfilter(lambda x: x%2==0, L), list(filter(lambda x: x%2==0, L)))
            self.assertEqual(myfilter(lambda x: x%3==1, L), list(filter(lambda x: x%3==1, L)))
            self.assertEqual(myfilter(lambda x: x>5, L), list(filter(lambda x: x>5, L)))
            self.assertEqual(myfilter(lambda x: x<0, L), list(filter(lambda x: x<0, L)))