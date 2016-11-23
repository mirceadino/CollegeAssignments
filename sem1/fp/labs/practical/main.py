from domain.RouteValidator import RouteValidator
from repository.RouteRepository import RouteRepository
from controller.RouteController import RouteController
from ui.Console import Console


route_vali = RouteValidator()
repo = RouteRepository("storage/routes.txt", route_vali)
ctrl = RouteController(repo)
ui = Console(ctrl)

ui.run()