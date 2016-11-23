import unittest
from domain.Activity import Activity
from domain.NABException import NABException
from domain.Person import Person
from domain.ActivityValidator import ActivityValidator
from repository.PersonRepository import PersonRepository
from repository.PersonFileRepository import PersonFileRepository
from repository.ActivityRepository import ActivityRepository
from repository.ActivityFileRepository import ActivityFileRepository
from controller.StatsController import StatsController


class StatsControllerTestCase(unittest.TestCase):

    def setUp(self):
        pR = PersonRepository()
        aR = ActivityRepository()
        self.L = StatsController(pR, aR)
        self.p = Person(1, "John", "1", "A")
        self.q = Person(2, "Mary", "1", "B")
        self.a1 = Activity(self.p, "2015.12.20", "12:12", "Swimming")
        self.a2 = Activity(self.p, "2016.01.20", "12:12", "Mapping")
        self.a3 = Activity(self.q, "2015.12.21", "12:12", "Swimming")
        self.a4 = Activity(self.q, "2015.12.20", "10:12", "Reading")

        pR.add(self.p)
        pR.add(self.q)
        aR.add(self.a1)
        aR.add(self.a2)
        aR.add(self.a3)
        aR.add(self.a4)


    def test_activities_for_person_alphabetically(self):
        L = self.L
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        assert L.activities_for_person_alphabetically(1) == [a2, a1]
        assert L.activities_for_person_alphabetically(2) == [a4, a3]
        assert L.activities_for_person_alphabetically(4) == []


    def test_activities_for_person_by_date(self):
        L = self.L
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        assert L.activities_for_person_by_date(1) == [a1, a2]
        assert L.activities_for_person_by_date(2) == [a4, a3]
        assert L.activities_for_person_by_date(4) == []


    def test_people_with_activities_in_interval(self):
        L = self.L
        p = self.p
        q = self.q

        assert L.people_with_activities_in_interval("2015.12.20", "2016.01.01") == [p, q]
        assert L.people_with_activities_in_interval("2000.01.01", "2010.01.01") == []
        assert L.people_with_activities_in_interval("2016.01.01", "2017.01.01") == [p]
        assert L.people_with_activities_in_interval("2015.12.21", "2015.12.21") == [q]


    def test_activities_in_interval_alphabetically(self):
        L = self.L
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        assert L.activities_in_interval_alphabetically("2015.12.20", "2016.01.01") == [a4, a1, a3]
        assert L.activities_in_interval_alphabetically("2000.01.01", "2010.01.01") == []
        assert L.activities_in_interval_alphabetically("2016.01.01", "2017.01.01") == [a2]
        assert L.activities_in_interval_alphabetically("2015.12.21", "2015.12.21") == [a3]


    def test_activities_in_interval_by_date(self):
        L = self.L
        a1 = self.a1
        a2 = self.a2
        a3 = self.a3
        a4 = self.a4

        assert L.activities_in_interval_by_date("2015.12.20", "2016.01.01") == [a4, a1, a3]
        assert L.activities_in_interval_by_date("2000.01.01", "2010.01.01") == []
        assert L.activities_in_interval_by_date("2016.01.01", "2017.01.01") == [a2]
        assert L.activities_in_interval_by_date("2015.12.21", "2015.12.21") == [a3]