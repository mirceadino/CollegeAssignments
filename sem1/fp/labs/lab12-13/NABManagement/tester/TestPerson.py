import unittest
from domain.Person import Person
from domain.NABException import NABException


class PersonTestCase(unittest.TestCase):

    def setUp(self):
        self.x = Person(1, "James", "0741000111", "9")
        self.y = Person(1, "James", "0741000111", "9")
        self.z = Person(2, "James", "0741000111", "9")


    def test_getters(self):
        x = self.x

        self.assertEqual(x.id, 1)
        self.assertEqual(x.name, "James")
        self.assertEqual(x.phone, "0741000111")
        self.assertEqual(x.address, "9")


    def test_setters(self):
        x = self.x

        x.name = "Enoch"
        x.phone = "0750111000"
        x.address = "1"

        self.assertEqual(x.name, "Enoch")
        self.assertEqual(x.phone, "0750111000")
        self.assertEqual(x.address, "1")


    def test_eq(self):
        self.assertEqual(self.x, self.x)
        self.assertEqual(self.x, self.y)
        self.assertNotEqual(self.x, self.z)
        self.assertNotEqual(self.y, self.z)
        self.assertNotEqual(self.x, [])