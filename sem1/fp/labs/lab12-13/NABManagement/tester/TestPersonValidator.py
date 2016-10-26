import unittest
from domain.PersonValidator import PersonValidator


class PersonValidatorTestCase(unittest.TestCase):

    def test_valid_id(self):
        self.assertTrue(PersonValidator.valid_id(34))
        self.assertTrue(PersonValidator.valid_id(3))
        self.assertTrue(PersonValidator.valid_id(1))
        self.assertFalse(PersonValidator.valid_id(0))
        self.assertFalse(PersonValidator.valid_id(-5))
        self.assertFalse(PersonValidator.valid_id(0.5))
        self.assertFalse(PersonValidator.valid_id(1.0))
        self.assertFalse(PersonValidator.valid_id("banana"))
        self.assertFalse(PersonValidator.valid_id([]))