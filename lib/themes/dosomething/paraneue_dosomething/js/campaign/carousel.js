module.exports = function() {

  // Show first image
  $("#slide0").addClass("visible");

  // Make carousel stateful
  var counter = 0;

  // Cache carousel buttons
  var $buttons = $("#prev, #next");

  // Decrement counter
  function decrementCounter() {
    // If first slide is shown, restart loop
    // Else, show previous slide
    counter === 0 ? counter = 2 : counter--;
  }

  // Increment counter
  function incrementCounter() {
    // If last slide is shown, restart loop
    // Else, show next slide
    counter === 2 ? counter = 0 : counter++;
  }

  // Toggle slide visibility
  function showCurrentSlide( direction ) {
    // Remove "visibile" class from the current slide
    $("#slide" + counter).removeClass("visible");

    // Increment or decrement slide position based on user"s request
    direction === "prev" ? decrementCounter() : incrementCounter();
     
    // Assign "visible" class to the requested slide 
    $("#slide" + counter).addClass("visible");
  }

  // Bind click event to carousel buttons
  $buttons.click(function() {
    showCurrentSlide( $(this).attr("id") );
  });

};
