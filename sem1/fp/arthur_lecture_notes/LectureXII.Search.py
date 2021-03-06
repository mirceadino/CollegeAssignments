'''
1. Example of a class that overloads '==' operator.
This allows using Python's inbuilt 'in' syntax
'''

class IDObject:
    '''
    Base class that we use to demonstrate overloading '=='
    '''
    def __init__(self,id):
        self._id = id

    def getID(self):
        return self._id

    def __eq__(self,o):
        return type(o) == type(self) and o._id == self._id

class Car(IDObject):
    '''
    First derived class
    '''
    def __init__(self,id,make,model):
        IDObject.__init__(self,id)
        self._make = make
        self._model = model

    def __str__(self):
        return str(self._id) + " "+str(self._make)+" "+str(self._model)

    def __repr__(self):
        return str(self)

class Student(IDObject):
    '''
    Another derived class
    '''
    def __init__(self,id,name):
        IDObject.__init__(self,id)
        self._name = name

    def __str__(self):
        return str(self._id)+" "+self._name

    def __repr__(self):
        return str(self)

def testEquals():
    '''
    Short test to see what happens with '=='
    '''
    c1 = Car(1,"Dacia","Sandero")
    c2 = Car(1,"Dacia","Logan")
    c3 = Car(2,"Dacia","Lodgy")

    s1 = Student(1,"Anna")
    s2 = Student(1,"John")
    s3 = Student(2,"Maria")

    print(c1 == c1)
    print(s1 == s1)

    print(c1 == c2)
    print(c1 == c3)

    print(s1 == s2)
    print(s1 == s3)

    print(c1 == s1)
    print(c1 == s3)

def testIn():
    '''
    Short test for Python's 'in'
    '''
    c1 = Car(1,"Dacia","Sandero")
    c2 = Car(1,"Dacia","Logan")
    c3 = Car(2,"Dacia","Lodgy")

    s1 = Student(1,"Anna")
    s2 = Student(1,"John")
    s3 = Student(2,"Maria")

    list = [c1,c2,c3,s1]

    print(c1 in list)
    print(s2 in list)
    print(s3 in list)

#print("Test Equals")
#testEquals()

#print("Test Python 'in'")
#testIn()


'''
2. Example of an iterable class, a collection
'''
class MyCollection:
    def __init__(self):
        self._data = []

    def add(self, o):
        self._data.append(o)

    def __iter__(self):
        '''
        Return an iterator
        '''
        self._iterPoz = 0
        return self

    def __next__(self):
        '''
        Returns the next element of the iteration
        '''
        if self._iterPoz>=len(self._data):
            raise StopIteration()
        rez = self._data[self._iterPoz]
        self._iterPoz = self._iterPoz + 1
        return rez

def testInCollection():
    '''
    Short test for the collection class above
    '''
    c1 = Car(1,"Dacia","Sandero")
    c2 = Car(2,"Dacia","Logan")
    c3 = Car(3,"Dacia","Lodgy")

    c4 = Car(4,"Dacia","Duster")

    collection = MyCollection()
    collection.add(c1)
    collection.add(c2)
    collection.add(c3)

    '''
    This calls the __next__ method until StopIteration() is raised
    '''
    for c in collection:
        print (c)

    print(c3 in collection)
    print(c4 in collection)
    print("All of them")

testInCollection()
    



    
    
    
        
    
