/**
 * Get a specified segment from the pathname.
 *
 * @param  {String} pathname
 * @param  {Number} segment
 * @return {Bool}
 */
export function getPathnameSegment(pathname = window.location.pathname, segmentIndex = 0) {
  let segments = pathname.split('/');

  segments.splice(0,1);

  return segments[segmentIndex];
}
