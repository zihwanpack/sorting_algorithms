// UnStable
// 선택 정렬은 데이터가 중복된 경우 위치가 바뀔 수 있기 때문에 Unstable한 정렬이다.

function selectionSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    let minIdx = i;

    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }

    if (minIdx !== i) {
      let tmp = arr[minIdx];
      arr[minIdx] = arr[i];
      arr[i] = tmp;
    }
    console.log(`${i}회전: ${arr}`);
  }
  return arr;
}
