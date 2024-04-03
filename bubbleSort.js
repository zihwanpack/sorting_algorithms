// 시간복잡도 모두 n^2 매우 느리다. 구현이 간단하다. stable하다.
// 버블 정렬은 in place 알고리즘이기 때문에 메모리가 절약된다는 장점이 있다.
// 여기서 "in place"라는 것은 자료를 정렬할 때 추가적인 메모리 공간이 필요한 것이 아니고
// 데이터가 저장된 그 공간 내에서 정렬을 한다는 뜻이다.

function bubbleSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 1; j < arr.length - i; j++) {
      if (arr[j - 1] > arr[j]) {
        [arr[j - 1], arr[j]] = [arr[j], arr[j - 1]];
      }
    }
  }
  return arr;
}
