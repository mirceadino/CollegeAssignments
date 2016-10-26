class AddOperation:
    '''
    Class corresponding to storing an added object to a repository.
    '''

    def __init__(self, obj):
        self.__obj = obj

    def object(self):
        '''
        Returns the added object.
        '''
        return self.__obj


class RemoveOperation:
    '''
    Class corresponding to storing a removed object to a repository.
    '''

    def __init__(self, obj):
        '''
        Returns the removed object.
        '''
        self.__obj = obj

    def object(self):
        return self.__obj


class UpdateOperation:
    '''
    Class corresponding to storing an updated object from a repository.
    '''

    def __init__(self, oldVersion, newVersion):
        self.__oldObj = oldVersion
        self.__newObj = newVersion

    def old(self):
        '''
        Returns the old version of the object.
        '''
        return self.__oldObj

    def new(self):
        '''
        Returns the new version of the object.
        '''
        return self.__newObj