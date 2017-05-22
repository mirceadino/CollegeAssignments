var pageWidth;
var thumbnailWidthSum;
var speed = 200;

function initThumbnails() {
  var left = 0;
  var padding = 3;
  var margin = 1;
  var width = 100;
  $(".thumbnail")
    .each(function() {
      $(this).css("left", left);
      left += width + 2*(padding+margin);
    });
  thumbnailWidthSum = left - width - 2*(padding+margin);
}

function slideThumbnails() {
  $(".thumbnail")
    .each(function() {
      var left = $(this).offset().left;
      if(left >= pageWidth) {
        left -= thumbnailWidthSum;
      }
      $(this).css("left", left);
    })
    .animate({"left": "+=60"}, speed, "linear", slideThumbnails);
}

$(document).ready(function() {
  pageWidth = $("body").width();

  initThumbnails();
  slideThumbnails();

  $(".thumbnail")
    .on("click", function() {
      var url = $(this).attr("src");
      $(".thumbnail")
        .css("opacity", "0.4")
        .stop(true);
      $("#large")
        .css("display", "block")
        .prop("src", url);
    });

  $("#large")
    .on("click", function() {
      slideThumbnails();
      $(".thumbnail")
        .css("opacity", "1");
      $(this)
        .css("display", "none");
    });
});
