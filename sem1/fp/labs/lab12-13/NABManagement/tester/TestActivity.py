import unittest
from domain.Person import Person
from domain.Activity import Activity
from domain.NABException import NABException


class ActivityTestCase(unittest.TestCase):

    def setUp(self):
        self.p = Person(1, "Jimmy", "911", "1 Main Street")
        self.r = Person(4, "Mike", "911", "2 Main Street")
        self.x = Activity(self.p, "2015.01.24", "23:59", "Swimming")


    def test_getters(self):
        p = self.p
        x = self.x

        self.assertEqual(x.person, p)
        self.assertEqual(x.date, "2015.01.24")
        self.assertEqual(x.time, "23:59")
        self.assertEqual(x.description, "Swimming")


    def test_setters(self):
        p = self.p
        r = self.r
        x = self.x

        x.person = r
        x.date = "2015.01.22"
        x.time = "10:30"
        x.description = "Reading"

        self.assertEqual(x.person, r)
        self.assertEqual(x.date, "2015.01.22")
        self.assertEqual(x.time, "10:30")
        self.assertEqual(x.description, "Reading")