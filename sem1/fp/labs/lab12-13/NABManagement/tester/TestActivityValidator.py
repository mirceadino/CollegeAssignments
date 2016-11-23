import unittest
from domain.ActivityValidator import ActivityValidator


class ActivityValidatorTestCase(unittest.TestCase):

    def test_valid_date(self):
        self.assertFalse(ActivityValidator.valid_date([]))
        self.assertFalse(ActivityValidator.valid_date(424))
        self.assertTrue(ActivityValidator.valid_date("2014.05.10"))
        self.assertFalse(ActivityValidator.valid_date("10.05.2014"))
        self.assertFalse(ActivityValidator.valid_date("10.5.2014"))
        self.assertFalse(ActivityValidator.valid_date("2014:05.10"))
        self.assertTrue(ActivityValidator.valid_date("2014.02.24"))
        self.assertTrue(ActivityValidator.valid_date("2999.01.30"))
        self.assertFalse(ActivityValidator.valid_date("2015.13.01"))
        self.assertFalse(ActivityValidator.valid_date("1900.02.29"))
        self.assertTrue(ActivityValidator.valid_date("2000.02.29"))
        self.assertTrue(ActivityValidator.valid_date("2004.02.29"))
        self.assertFalse(ActivityValidator.valid_date("2014..02.29"))
        self.assertFalse(ActivityValidator.valid_date("2014.29"))
        self.assertFalse(ActivityValidator.valid_date("29.3.02...32..3232.2004"))
        self.assertFalse(ActivityValidator.valid_date("Banana"))


    def test_valid_time(self):
        self.assertFalse(ActivityValidator.valid_time([]))
        self.assertFalse(ActivityValidator.valid_time(424))
        self.assertTrue(ActivityValidator.valid_time("12:12"))
        self.assertFalse(ActivityValidator.valid_time("12:::12"))
        self.assertTrue(ActivityValidator.valid_time("00:00"))
        self.assertFalse(ActivityValidator.valid_time("0:0"))
        self.assertFalse(ActivityValidator.valid_time("51:12"))
        self.assertFalse(ActivityValidator.valid_time("banana"))
        self.assertFalse(ActivityValidator.valid_time("24.12.2015"))
        self.assertFalse(ActivityValidator.valid_time("23.59"))
        self.assertTrue(ActivityValidator.valid_time("23:59"))