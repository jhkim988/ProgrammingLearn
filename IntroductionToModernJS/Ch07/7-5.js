function linearSearch(x, a) {
  // key: x
  // a: sorted array
  var i = 0;
  var n = a.length;
  while (i < n && x > a[i]) i++;
  if (x == a[i]) return i;
  return null;
}