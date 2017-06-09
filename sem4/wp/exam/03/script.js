function showGrid() {
  $.get(
    "get_grid.php",
    {},
    function(data, status) {
      $("#grid").html(data);
    });

}

function showChangeGrid() {
  $.get(
    "get_change_grid.php",
    {},
    function(data, status) {
      $("#change_grid").html(data);
    });
}

function showAverage() {
  $.get(
    "get_average.php",
    {},
    function(data, status) {
      $("#average_pic").html(data);
    });
}

var prev_x = -1;
var prev_y = -1;
var prev_id = -1;
function interchange(x, y, id) {
  if(prev_x == -1) {
    prev_x = x;
    prev_y = y;
    prev_id = id;

  } else {
    var content_1 = $("#cell-" + prev_x + "-" + prev_y).html();
    var vote_1 =
      Number($("input[name=vote-" + prev_id + "]").val()) +
      Number($("input[name=x-" + id + "]").val()) +
      Number($("input[name=y-" + id + "]").val()) + 2;
    var content_2 = $("#cell-" + x + "-" + y).html();
    var vote_2 =
      Number($("input[name=vote-" + id + "]").val()) +
      Number($("input[name=x-" + prev_id + "]").val()) +
      Number($("input[name=y-" + prev_id + "]").val()) + 2;

    $("#cell-" + prev_x + "-" + prev_y).html(content_2);
    $("input[name=vote-" + prev_id + "]").val(vote_1);
    $("input[name=x-" + prev_id + "]").val(x);
    $("input[name=y-" + prev_id + "]").val(y);
    $("#cell-" + x + "-" + y).html(content_1);
    $("input[name=vote-" + id + "]").val(vote_2);
    $("input[name=x-" + id + "]").val(prev_x);
    $("input[name=y-" + id + "]").val(prev_y);

    prev_x = -1;
    prev_y = -1;
    prev_id = -1;
  }
}

$(document).ready(function() {
  showGrid();
  showChangeGrid();
  showAverage();
});

