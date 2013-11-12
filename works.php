<?phpp

$abc = true;
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
function Testest($assertion) {
  if ($assertion == "cat") {
    return "banana";
  }

  return "dogs";
}

?>
