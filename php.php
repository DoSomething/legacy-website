<?php

$abc = FALSE;
if ($abc
  == false) {
 echo ":(";
}

function test($assertion) {
  if ($assertion == "cat") {
    return "banana";
  }

  return "dogs";
}
