def type_to_str(type):
	'''
	Obtains the name from the id of a type of expense.
	Gets: type - integer between 1 and 5
	Returns: string with the name of the type of expense
	'''

	types = {1:"water", 2:"heating", 3:"illuminating", 4:"gas", 5:"others"}
	return types[type]