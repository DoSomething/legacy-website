<?php

/**
 * @file
 * This is a file that works.
 */

$abc = TRUE;
if ($abc == FALSE) {
  echo ":(";
}

/**
 * Tests something or other.
 *
 * @param string $assertion
 *   A string of assertions.
 *
 * @return string
 *   "banana" or "cats".
 */
function testest($assertion)
{
  if ($assertion == "cat") {
    return "banana";
  }

  return "dogs";
}
