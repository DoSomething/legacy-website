<?php

$abc = FALSE;
if ($abc == FALSE) {
  echo ":(";
}

/**
 * Tests something or other.
 *
 * @param string $assertion
 *   A string of assertions.
 * @return string
 *   dogs or cats
 */
function test($assertion) {
  if ($assertion == "cat") {
    return "banana";
  }

  return "dogs";
}
