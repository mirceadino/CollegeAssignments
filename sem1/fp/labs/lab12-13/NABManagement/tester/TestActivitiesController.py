import unittest
from domain.Person import Person
from domain.Activity import Activity
from domain.NABException import NABException
from repository.PersonRepository import PersonRepository
from repository.ActivityRepository import ActivityRepository
from controller.ActivitiesController import ActivitiesController


class ActivitiesControllerTestCase(unittest.TestCase):

    def setUp(self):
        pR = PersonRepository()
        self.L = ActivitiesController(pR, ActivityRepository())
        self.p = Person(1, "John", "1", "A")
        self.q = Person(2, "Mary", "1", "B")
        self.r = Person(3, "Carl", "1", "B")
        self.a1 = Activity(self.p, "2015.12.20", "12:12", "Swimming")
        self.a2 = Activity(self.p, "2016.01.20", "12:12", "Swimming")
        self.a3 = Activity(self.q, "2015.12.21", "12:12", "Swimming")
        self.a4 = Activity(self.q, "2015.12.20", "10:12", "Reading")

        pR.add(self.p)
        pR.add(self.q)
        self.L.add_activity(self.a1)
        self.L.add_activity(self.a2)
        self.L.add_activity(self.a3)
        self.L.add_activity(self.a4)


    def test_add_activity(self):
        pR = PersonRepository()
        L = ActivitiesController(pR, ActivityRepository())
        p = self.p
        q = self.q
        r = self.r
        pR.add(p)
        pR.add(q)

        L.add_activity(self.a1)
        self.assertEqual(L.number_of_activities(), 1)
        self.assertEqual(L.find_activity_by_position(0), self.a1)

        L.add_activity(self.a3)
        self.assertEqual(L.number_of_activities(), 2)
        self.assertEqual(L.find_activity_by_position(1), self.a3)

        self.assertRaises(NABException, L.add_activity, Activity(r, "2000.01.01", "12:12", "A"))


    def test_find_activity_by_position(self):
        L = self.L
        p = self.p
        q = self.q

        self.assertEqual(L.find_activity_by_position(0), self.a4)
        self.assertEqual(L.find_activity_by_position(1), self.a1)


    def test_find_activities_by_person_id(self):
        L = self.L
        p = self.p
        q = self.q

        P = L.find_activities_by_person_id(p.id)
        self.assertEqual(len(P), 2)
        self.assertEqual(P.find(0), self.a1)
        self.assertEqual(P.find(1), self.a2)


    def test_find_activities_by_date(self):
        L = self.L
        p = self.p
        q = self.q

        P = L.find_activities_by_date("2016.01.20")
        self.assertEqual(len(P), 1)
        self.assertEqual(P.find(0), self.a2)


    def test_find_activities_by_time(self):
        L = self.L
        p = self.p
        q = self.q

        P = L.find_activities_by_time("10:12")
        self.assertEqual(len(P), 1)
        self.assertEqual(P.find(0), self.a4)


    def test_find_activities_by_description(self):
        L = self.L
        p = self.p
        q = self.q

        P = L.find_activities_by_description("Swim")
        self.assertEqual(len(P), 3)
        self.assertEqual(P.find(0), self.a1)
        self.assertEqual(P.find(1), self.a3)
        self.assertEqual(P.find(2), self.a2)


    def test_remove_activity_by_position(self):
        L = self.L
        p = self.p
        q = self.q

        L.remove_activity_by_position(0)
        self.assertEqual(L.number_of_activities(), 3)
        self.assertNotEqual(L.find_activity_by_position(0), self.a4)

        L.remove_activity_by_position(0)
        self.assertEqual(L.number_of_activities(), 2)
        self.assertNotEqual(L.find_activity_by_position(0), self.a1)