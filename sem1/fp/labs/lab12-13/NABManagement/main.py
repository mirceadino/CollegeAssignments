from domain.Activity import Activity
from domain.Person import Person
from repository.PersonRepository import PersonRepository
from repository.PersonFileRepository import PersonFileRepository
from repository.ActivityRepository import ActivityRepository
from repository.ActivityFileRepository import ActivityFileRepository
from controller.PeopleController import PeopleController
from controller.ActivitiesController import ActivitiesController
from controller.StatsController import StatsController
from controller.UndoRedoController import UndoRedoController
from ui.Console import Console
from os import system


def __init(persRepo, actiRepo):
    p = Person(1, "Mike Johnson", "425-606-1234", "9 Baker Street")
    q = Person(3, "John Carpenter", "425-180-1000", "1 Main Street")
    r = Person(4, "Mary-Jane Jackson", "412-000-2323", "10 Baker's Street")
    s = Person(9, "Victoria-Mary Philips", "410-249-2494", "11 Jules Verne Alley")
    t = Person(10, "Charlie Philips", "515-515-5151", "11 Jules Verne Alley")
    w = Person(23, "Michael Newman", "515-515-5151", "7 Opera Boulevard")

    persRepo.add(p)
    persRepo.add(q)
    persRepo.add(r)
    persRepo.add(s)
    persRepo.add(t)
    persRepo.add(w)
    actiRepo.add(Activity(p, "2014.12.12", "12:12", "Swimming"))
    actiRepo.add(Activity(p, "2012.12.20", "10:12", "Reading"))
    actiRepo.add(Activity(p, "2000.01.01", "00:00", "Party at Michael's"))
    actiRepo.add(Activity(r, "2000.01.01", "00:00", "Party at Tiffany's"))
    actiRepo.add(Activity(q, "2000.01.01", "00:00", "Party at Tiffany's"))
    actiRepo.add(Activity(q, "2015.01.13", "20:22", "Dinner"))


def get_storage_preference():
    '''
    Prompts the user in order to see his preference about in-file storage for this session.
    :return: True - user prefers in-file, False - otherwise
    '''

    yes = ["yes", "y", "aye", "yea", "yeah"]
    no = ["no", "n", "nay", "nah"]

    answer = ""

    while not (answer in yes or answer in no):
        system("clear")

        answer = input("Do you want in-file storage? Type \"Yes\" if so or \"No\" otherwise: ")
        answer = answer.lower()
        answer = answer.strip()

    if answer.lower() in yes:
        return True
    else:
        return False


def main():
    in_file = get_storage_preference()

    # Set repositories.
    if in_file:
        personRepo = PersonFileRepository("storage/people.txt")
        activityRepo = ActivityFileRepository(personRepo, "storage/activities.txt")
    else:
        personRepo = PersonRepository()
        activityRepo = ActivityRepository()

    # Set controllers.
    peopleCtrl = PeopleController(personRepo)
    activitiesCtrl = ActivitiesController(personRepo, activityRepo)
    statsCtrl = StatsController(personRepo, activityRepo)
    undoRedoCtrl = UndoRedoController(peopleCtrl, activitiesCtrl)

    # Set console.
    ui = Console(peopleCtrl, activitiesCtrl, statsCtrl, undoRedoCtrl)

    # Run everything.
    ui.run()

    # Store to files
    if in_file:
        personRepo.store()
        activityRepo.store()


if __name__ == "__main__":
    main()