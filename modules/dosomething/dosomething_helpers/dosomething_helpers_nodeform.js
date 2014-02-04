(function ($) {
  $(document).ready(function(){
    $('.node-form [type=text], .node-form textarea').keyup(function(){
      charCount($(this));
    });
    $('.node-form [type=text], .node-form textarea').change(function(){
      charCount($(this));
    });
    $('#edit-fact, .form-textarea').keyup(function(){
      charCount($(this));
    });
  });

  function charCount(field) {
    if( field.parent('div').find('.char_count').length == 0 ) {
      field.parent('div').append('<span class="char_count"></span>');
    }
    field.parent('div').find('.char_count').html(
      field.val().length
    );
   }

}(jQuery));