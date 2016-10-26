import unittest
from domain.Person import Person
from domain.NABException import NABException
from repository.PersonRepository import PersonRepository


class PersonRepositoryTestCase(unittest.TestCase):

    def setUp(self):
        self.L = PersonRepository()
        self.p = {}
        self.p[1] = Person(1, "John", "1", "A")
        self.p[2] = Person(2, "Mary", "1", "B")
        self.p[5] = Person(5, "Mike", "3", "B")
        self.p[7] = Person(7, "Mike", "4", "C")
        self.L.add(self.p[1])
        self.L.add(self.p[2])
        self.L.add(self.p[5])
        self.L.add(self.p[7])


    def test_add(self):
        L = PersonRepository()

        self.assertEqual(len(L), 0)
        L.add(self.p[1])
        self.assertEqual(len(L), 1)
        self.assertEqual(L.find_by_id(1), self.p[1])
        L.add(self.p[2])
        self.assertEqual(len(L), 2)
        self.assertEqual(L.find_by_id(2), self.p[2])
        L.add(self.p[5])
        self.assertEqual(len(L), 3)
        self.assertEqual(L.find_by_id(5), self.p[5])
        self.assertRaises(NABException, L.find_by_id, self.p[1])


    def test_find(self):
        L = self.L

        self.assertEqual(L.find(1), 0)
        self.assertEqual(L.find(3), -1)
        self.assertEqual(L.find(2), 1)
        self.assertEqual(L.find(5), 2)
        self.assertEqual(L.find(7), 3)
        self.assertRaises(NABException, L.find, -1)


    def test_find_by_id(self):
        L = self.L

        self.assertEqual(L.find_by_id(1), self.p[1])
        self.assertEqual(L.find_by_id(5), self.p[5])
        self.assertRaises(NABException, L.find_by_id, 3)
        self.assertRaises(NABException, L.find_by_id, -1)


    def test_find_by_name(self):
        L = self.L

        P = L.find_by_name("Mike")
        self.assertEqual(len(P), 2)
        self.assertNotEqual(P.find(5), -1)
        self.assertNotEqual(P.find(7), -1)

        P = L.find_by_name("Mary")
        self.assertEqual(len(P), 1)
        self.assertNotEqual(P.find(2), -1)

        P = L.find_by_name("Sophie")
        self.assertEqual(len(P), 0)


    def test_find_by_phone(self):
        L = self.L

        P = L.find_by_phone("1")
        self.assertEqual(len(P), 2)
        self.assertNotEqual(P.find(1), -1)
        self.assertNotEqual(P.find(2), -1)

        P = L.find_by_phone("3")
        self.assertEqual(len(P), 1)
        self.assertNotEqual(P.find(5), -1)

        P = L.find_by_phone("9")
        self.assertEqual(len(P), 0)


    def test_find_by_address(self):
        L = self.L

        P = L.find_by_address("B")
        self.assertEqual(len(P), 2)
        self.assertNotEqual(P.find(2), -1)
        self.assertNotEqual(P.find(5), -1)

        P = L.find_by_address("A")
        self.assertEqual(len(P), 1)
        self.assertNotEqual(P.find(1), -1)

        P = L.find_by_address("D")
        self.assertEqual(len(P), 0)


    def test_remove(self):
        L = self.L

        self.assertEqual(L.remove(2), self.p[5])
        self.assertEqual(len(L), 3)
        self.assertEqual(L.find(5), -1)

        self.assertEqual(L.remove(0), self.p[1])
        self.assertEqual(len(L), 2)
        self.assertEqual(L.find(1), -1)

        self.assertRaises(NABException, L.remove, 3)


    def test_remove_by_id(self):
        L = self.L

        L.remove_by_id(5)
        self.assertEqual(len(L), 3)
        self.assertEqual(L.find(5), -1)

        L.remove_by_id(1)
        self.assertEqual(len(L), 2)
        self.assertEqual(L.find(1), -1)

        self.assertRaises(NABException, L.remove_by_id, 3)