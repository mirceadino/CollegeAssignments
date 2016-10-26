from domain.NABException import NABException


class UndoRedoController:
    '''
    Class used for handling undo/redo on the controllers.
    '''

    def __init__(self, peopleCtrl, activitiesCtrl):
        self.__peopleCtrl = peopleCtrl
        self.__activitiesCtrl = activitiesCtrl
        self.__ctrls = []
        self.__index = -1


    def do_people(self):
        '''
        PeopleCtrl is set to have been the lastly modified.
        '''

        self.__ctrls[:] = self.__ctrls[:self.__index+1]
        self.__ctrls.append([self.__peopleCtrl])
        self.__index += 1


    def do_activities(self):
        '''
        ActivitiesCtrl is set to have been the lastly modified.
        '''

        self.__ctrls[:] = self.__ctrls[:self.__index+1]
        self.__ctrls.append([self.__activitiesCtrl])
        self.__index += 1


    def do_both(self):
        '''
        PeopleCtrl and ActivitiesCtrl are set to have been the lastly modified simultaneously.
        '''

        self.__ctrls[:] = self.__ctrls[:self.__index+1]
        self.__ctrls.append([self.__peopleCtrl, self.__activitiesCtrl])
        self.__index += 1


    def undo(self):
        '''
        Undoes the last operation on the lastly modified controllers.
        '''

        if self.__index == -1:
            raise NABException("# There's nothing to undo.\n")

        for ctrl in self.__ctrls[self.__index]:
            ctrl.undo()

        self.__index -= 1


    def redo(self):
        '''
        Redoes the last undoes on the lastly undone controllers.
        '''

        if self.__index+1 == len(self.__ctrls):
            raise NABException("# There's nothing to redo.\n")

        self.__index += 1

        for ctrl in self.__ctrls[self.__index]:
            ctrl.redo()