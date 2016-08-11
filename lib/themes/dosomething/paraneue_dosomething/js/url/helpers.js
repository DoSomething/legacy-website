/**
 * Get a specified segment from the pathname.
 *
 * @param  {String} pathname
 * @param  {Number} segment
 * @return {Boolean}
 */
export function getPathnameSegment(pathname = window.location.pathname, segmentIndex = 0) {
  let segments = pathname.split('/');
  segmentIndex++;

  return segments[segmentIndex];
}
