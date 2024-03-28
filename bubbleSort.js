function bubbleSort(arr) {
  for (let x = 0; x < arr.length; x++) {
    for (let y = 1; y < arr.length - x; y++) {
      if (arr[y - 1] > arr[y]) {
        [arr[y - 1], arr[y]] = [arr[y], arr[y - 1]];
      }
    }
  }

  return arr;
}
