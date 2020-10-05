import assert from "assert";

/** binary search of a SORTED list */
const indexOf = (query: number, items: number[]): number => {
  let left = 0;
  let right = items.length - 1;

  while (left <= right) {
    const cursor = Math.floor((left + right) / 2);
    const guess = items[cursor];

    if (guess === query) {
      // success, early exit
      return cursor;
    } else if (guess < query) {
      // query is on the right
      left = cursor + 1;
    } else {
      // query is on the left
      right = cursor;
    }
  }
  return -1;
};

// check it finds every element in an even length list
const list1 = [0, 1, 2, 3];
for (const i of list1) {
  assert.strictEqual(indexOf(i, list1), i);
}
assert.strictEqual(indexOf(99, list1), -1);

// check it finds every element in an odd length list
const list2 = [0, 1, 2, 3, 4];
for (const i of list2) {
  assert.strictEqual(indexOf(i, list2), i);
}
assert.strictEqual(indexOf(99, list2), -1);
