class ActivityValidator:
    """
    Class used for validating various parameters and data about activities.
    """

    @staticmethod
    def valid_date(date):
        '''
        Checks if a string represents a valid date of format dateFormat() between minDate() and maxDate().
        :param date: string - date to check
        :return: True - date is valid and respects the desired format; False - otherwise
        '''

        # Splits the elements composing a date (3 elements, corresponding to dd, mm and yyyy, are expected).
        try:
            numbers = date.split(".")
            if len(numbers) != 3:
                return False
        except AttributeError:
            return False

        # Checks if the third element (dd) is an integer and gets its "dd" string representation if true.
        try:
            day = int(numbers[2])
            if day < 10: dayStr = "0" + str(day)
            else: dayStr = str(day)
        except ValueError:
            return False

        # Checks if the second element (mm) is an integer and gets its "mm" string representation if true.
        try:
            month = int(numbers[1])
            if month < 10: monthStr = "0" + str(month)
            else: monthStr = str(month)
        except ValueError:
            return False

        # Checks if the first element (yyyy) is an integer and gets its "yyyy" string representation if true.
        try:
            year = int(numbers[0])
            yearStr = str(year)
            if len(yearStr) != 4:
                return False
        except ValueError:
            return False

        # Checks if the date respects the "yy.mm.dddd" format.
        if date != (yearStr + "." + monthStr + "." + dayStr):
            return False

        # Checks if the day is valid in general.
        if day < 1 or day > 31:
            return False

        # Checks if the month is valid in general.
        if month < 1 or month > 12:
            return False

        # Checks if the whole date is within bounds.
        if date < ActivityValidator.minDate() or date > ActivityValidator.maxDate():
            return False

        # Checks if the day is valid for April, June, September and November.
        if month in [4, 6, 9, 11]:
            if day == 31:
                return False

        # Checks if the day is valid for February in leap and common years.
        if month == 2:
            if day > 29:
                return False
            elif day == 29 and not ((year%4 == 0 and year%100 !=0) or (year%400 == 0)):
                return False

        # Everything is alright, so returns True.
        return True


    @staticmethod
    def valid_time(time):
        '''
        Checks if a string represents a valid time of format timeFormat() between minTime() and maxTime().
        :param date: string - time to check
        :return: True - time is valid and respects the desired format; False - otherwise
        '''

        # Splits the elements composing a time (2 elements, corresponding to hh and mm, are expected).
        try:
            numbers = time.split(":")
            if len(numbers) != 2:
                return False
        except AttributeError:
            return False

        # Checks if the first element (hh) is an integer and gets its "hh" string representation if true.
        try:
            hour = int(numbers[0])
            if hour < 10: hourStr = "0" + str(hour)
            else: hourStr = str(hour)
        except ValueError:
            return False

        # Checks if the second element (mm) is an integer and gets its "mm" string representation if true.
        try:
            minute = int(numbers[1])
            if minute < 10: minuteStr = "0" + str(minute)
            else: minuteStr = str(minute)
        except ValueError:
            return False

        # Checks if the time respects the hh:mm" format.
        if time != (hourStr + ":" + minuteStr):
            return False

        # Checks if the hour is valid.
        if hour < 0 or hour > 23:
            return False

        # Checks if the minute is valid.
        if minute < 0 or minute > 59:
            return False

        # Checks if the whole time is withing bounds.
        if time < ActivityValidator.minTime() or time > ActivityValidator.maxTime():
            return False

        # Everything is alright, so returns True.
        return True


    @staticmethod
    def minDate():
        return "2000.01.01"

    @staticmethod
    def maxDate():
        return "2999.12.31"

    @staticmethod
    def dateFormat():
        return "yyyy.mm.dd"

    @staticmethod
    def minTime():
        return "00:00"

    @staticmethod
    def maxTime():
        return "23:59"

    @staticmethod
    def timeFormat():
        return "hh:mm"


def __test_valid_date():
    assert ActivityValidator.valid_date([]) == False
    assert ActivityValidator.valid_date(424) == False
    assert ActivityValidator.valid_date("2014.05.10") == True
    assert ActivityValidator.valid_date("10.05.2014") == False
    assert ActivityValidator.valid_date("10.5.2014") == False
    assert ActivityValidator.valid_date("2014:05.10") == False
    assert ActivityValidator.valid_date("2014.02.24") == True
    assert ActivityValidator.valid_date("2999.01.30") == True
    assert ActivityValidator.valid_date("2015.13.01") == False
    assert ActivityValidator.valid_date("1900.02.29") == False
    assert ActivityValidator.valid_date("2000.02.29") == True
    assert ActivityValidator.valid_date("2004.02.29") == True
    assert ActivityValidator.valid_date("2014..02.29") == False
    assert ActivityValidator.valid_date("2014.29") == False
    assert ActivityValidator.valid_date("29.3.02...32..3232.2004") == False
    assert ActivityValidator.valid_date("Banana") == False


def __test_valid_time():
    assert ActivityValidator.valid_time([]) == False
    assert ActivityValidator.valid_time(424) == False
    assert ActivityValidator.valid_time("12:12") == True
    assert ActivityValidator.valid_time("12:::12") == False
    assert ActivityValidator.valid_time("00:00") == True
    assert ActivityValidator.valid_time("0:0") == False
    assert ActivityValidator.valid_time("51:12") == False
    assert ActivityValidator.valid_time("banana") == False
    assert ActivityValidator.valid_time("24.12.2015") == False
    assert ActivityValidator.valid_time("23.59") == False
    assert ActivityValidator.valid_time("23:59") == True


if __name__ == "__main__":
    __test_valid_date()
    __test_valid_time()