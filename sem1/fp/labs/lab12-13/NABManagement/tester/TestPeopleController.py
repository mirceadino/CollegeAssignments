import unittest
from domain.Person import Person
from domain.NABException import NABException
from repository.PersonRepository import PersonRepository
from controller.PeopleController import PeopleController


class PeopleControllerTestCase(unittest.TestCase):

    def setUp(self):
        self.L = PeopleController(PersonRepository())
        self.p = Person(1, "John", "1", "A")
        self.q = Person(2, "Mary", "1", "B")

        self.L.add_person(self.p)
        self.L.add_person(self.q)


    def test_add_person(self):
        L = PeopleController(PersonRepository())

        L.add_person(self.p)
        self.assertEqual(L.number_of_people(), 1)
        self.assertEqual(L.find_person_by_id(1), self.p)

        self.assertRaises(NABException, L.add_person, self.p)
        self.assertEqual(L.number_of_people(), 1)

        L.add_person(self.q)
        self.assertEqual(L.number_of_people(), 2)
        self.assertEqual(L.find_person_by_id(2), self.q)


    def test_find_person_by_id(self):
        L = self.L
        p = self.p
        q = self.q

        self.assertEqual(L.find_person_by_id(1), p)
        self.assertRaises(NABException, L.find_person_by_id, 3)
        self.assertEqual(L.find_person_by_id(2), q)
        self.assertRaises(NABException, L.find_person_by_id, -1)


    def test_find_people_by_name(self):
        L = self.L
        p = self.p
        q = self.q

        P = L.find_people_by_name(p.name)
        self.assertEqual(len(P), 1)
        self.assertNotEqual(P.find(p.id), -1)


    def test_find_people_by_address(self):
        L = self.L
        p = self.p
        q = self.q

        P = L.find_people_by_address(p.address)
        self.assertEqual(len(P), 1)
        self.assertNotEqual(P.find(p.id), -1)


    def test_find_people_by_phone(self):
        L = self.L
        p = self.p
        q = self.q

        P = L.find_people_by_phone(p.phone)
        self.assertEqual(len(P), 2)
        self.assertNotEqual(P.find(p.id), -1)
        self.assertNotEqual(P.find(q.id), -1)


    def test_remove_person_by_id(self):
        L = self.L
        p = self.p
        q = self.q

        L.remove_person_by_id(1)
        self.assertEqual(L.number_of_people(), 1)

        L.remove_person_by_id(2)
        self.assertEqual(L.number_of_people(), 0)


