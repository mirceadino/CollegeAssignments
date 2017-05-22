var last_filter_type = "type";
var last_filter_text = "";

function showDocuments() {
  var filter_type = $('input[name="filter_type"]:checked').val();
  var filter_text = $('input[name="filter_text"]').val();

  $.post(
    "get_documents.php",
    {
      filter_type: filter_type,
      filter_text: filter_text,
    },
    function(data, status) {
      $("#documents").html(data);
    });

  last_filter_type = filter_type;
  last_filter_text = filter_text;
};


function addDocument() {
  var author = $('input[name="author"]').val();
  var title = $('input[name="title"]').val();
  var num_pages = $('input[name="num_pages"]').val();
  var type = $('input[name="type"]').val();
  var format = $('input[name="format"]').val();
  $.post(
    "add_document.php",
    {
      author: author,
      title: title,
      num_pages: num_pages,
      type: type,
      format: format
    },
    function(data, status) {
      $("#message")
        .html(data);
      showDocuments();
    }
  );
}


function deleteDocument(id) {
  $.post(
    "delete_document.php",
    {
      id: id
    },
    function(data, status) {
      $("#message")
        .html(data);
      showDocuments();
    }
  );
}


function preUpdateDocument(id, author, title, num_pages, type, format) {
  $('input[name="id"]').prop("value", id);
  $('input[name="author"]').prop("value", author);
  $('input[name="title"]').prop("value", title);
  $('input[name="num_pages"]').prop("value", num_pages);
  $('input[name="type"]').prop("value", type);
  $('input[name="format"]').prop("value", format);
}


function updateDocument() {
  var id = $('input[name="id"]').val();
  var author = $('input[name="author"]').val();
  var title = $('input[name="title"]').val();
  var num_pages = $('input[name="num_pages"]').val();
  var type = $('input[name="type"]').val();
  var format = $('input[name="format"]').val();
  $.post(
    "update_document.php",
    {
      id: id,
      author: author,
      title: title,
      num_pages: num_pages,
      type: type,
      format: format
    },
    function(data, status) {
      $("#message")
        .html(data);
      showDocuments();
    }
  );
}


$(document).ready(function() {
  showDocuments();

  $('button[name="filter_button"]')
    .click(function() {
      $("#last_filter").html("Last filter: '" + last_filter_type + "', '" + last_filter_text + "'");

      showDocuments()

      var filter_type = $('input[name="filter_type"]:checked').val();
      var filter_text = $('input[name="filter_text"]').val();

      last_filter_type = filter_type;
      last_filter_text = filter_text;
    });

  var old_content;
  $('button[name="add_submit"]')
    .hover(function() {
      old_content = $('input[name="id"]').prop("value");
      $('input[name="id"]').prop("value", "automatic value");
    }, function() {
      $('input[name="id"]').prop("value", old_content);
    })
    .click(function() {
      addDocument();
    });

  $('button[name="update_submit"]')
    .click(function() {
      updateDocument();
    });
});
