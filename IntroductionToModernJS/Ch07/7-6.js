function binarySearch(x, a) {
  // x: key
  // a: sorted

  var n = a.length;
  var left = 0, right = n - 1;
  while (left < right) {
    var mid = Math.floor((left + right) / 2);
    if (x <= a[mid]) {
      right = mid;
    } else {
      left = middle + 1;
    }
  }
  if (x == a[right]) return right;
  return null;
}