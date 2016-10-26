import unittest
from domain.Person import Person
from domain.Activity import Activity
from domain.NABException import NABException
from repository.PersonRepository import PersonRepository
from repository.ActivityRepository import ActivityRepository


class ActivityRepositoryTestCase(unittest.TestCase):

    def setUp(self):
        self.L = ActivityRepository()
        self.p = Person(1, "John", "1", "A")
        self.q = Person(2, "Mary", "1", "B")
        self.a1 = Activity(self.p, "2015.12.20", "12:12", "Swimming")
        self.a2 = Activity(self.p, "2016.01.20", "12:12", "Swimming")
        self.a3 = Activity(self.q, "2015.12.21", "12:12", "Swimming")
        self.a4 = Activity(self.q, "2015.12.20", "10:12", "Reading")
        self.L.add(self.a1)
        self.L.add(self.a2)
        self.L.add(self.a3)
        self.L.add(self.a4)


    def test_add(self):
        L = ActivityRepository()
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        self.assertEqual(len(L), 0)
        L.add(a1)
        self.assertEqual(len(L), 1)
        self.assertEqual(L.find(0), a1)
        L.add(a2)
        self.assertEqual(len(L), 2)
        self.assertEqual(L.find(0), a1)
        self.assertEqual(L.find(1), a2)
        L.add(a3)
        self.assertEqual(len(L), 3)
        self.assertEqual(L.find(0), a1)
        self.assertEqual(L.find(1), a3)
        self.assertEqual(L.find(2), a2)
        L.add(a4)
        self.assertEqual(len(L), 4)
        self.assertEqual(L.find(0), a4)
        self.assertEqual(L.find(1), a1)
        self.assertEqual(L.find(2), a3)
        self.assertEqual(L.find(3), a2)


    def test_find(self):
        L = self.L
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        self.assertEqual(L.find(0), a4)
        self.assertEqual(L.find(1), a1)
        self.assertEqual(L.find(2), a3)
        self.assertEqual(L.find(3), a2)


    def test_find_by_person_id(self):
        L = self.L
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        P = L.find_by_person_id(p.id)
        self.assertEqual(len(P), 2)
        self.assertEqual(P.find(0), a1)
        self.assertEqual(P.find(1), a2)

        P = L.find_by_person_id(q.id)
        self.assertEqual(len(P), 2)
        self.assertEqual(P.find(0), a4)
        self.assertEqual(P.find(1), a3)

        P = L.find_by_person_id(9)
        self.assertEqual(len(P), 0)


    def test_find_by_date(self):
        L = self.L
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        P = L.find_by_date("2015.12.20")
        self.assertEqual(len(P), 2)
        self.assertEqual(P.find(0), a4)
        self.assertEqual(P.find(1), a1)

        P = L.find_by_date("2015.12.21")
        self.assertEqual(len(P), 1)
        self.assertEqual(P.find(0), a3)

        P = L.find_by_date("2015.05.17")
        self.assertEqual(len(P), 0)


    def test_find_by_time(self):
        L = self.L
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        P = L.find_by_time("10:12")
        self.assertEqual(len(P), 1)
        self.assertEqual(P.find(0), a4)

        P = L.find_by_time("12:12")
        self.assertEqual(len(P), 3)
        self.assertEqual(P.find(0), a1)
        self.assertEqual(P.find(1), a3)
        self.assertEqual(P.find(2), a2)

        P = L.find_by_time("11:12")
        self.assertEqual(len(P), 0)


    def test_find_by_description(self):
        L = self.L
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        P = L.find_by_description("Reading")
        self.assertEqual(len(P), 1)
        self.assertEqual(P.find(0), a4)

        P = L.find_by_description("Swimming")
        self.assertEqual(len(P), 3)
        self.assertEqual(P.find(0), a1)
        self.assertEqual(P.find(1), a3)
        self.assertEqual(P.find(2), a2)

        P = L.find_by_description("11:12")
        self.assertEqual(len(P), 0)


    def test_remove(self):
        L = self.L
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        self.assertEqual(L.remove(0), a4)
        self.assertEqual(len(L), 3)

        self.assertEqual(L.remove(2), a2)
        self.assertEqual(len(L), 2)


    def test_remove_by_person_id(self):
        L = self.L
        p = self.p
        q = self.q
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        L.remove_by_person_id(1)
        self.assertEqual(len(L), 2)
        self.assertEqual(len(L.find_by_person_id(1)), 0)

        L.remove_by_person_id(1)
        self.assertEqual(len(L), 2)
        self.assertEqual(len(L.find_by_person_id(1)), 0)

        L.remove_by_person_id(2)
        self.assertEqual(len(L), 0)
        self.assertEqual(len(L.find_by_person_id(2)), 0)