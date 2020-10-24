import 'dart:math';

import 'package:flutter/foundation.dart';

class Password extends ChangeNotifier {
  List parent = [
    [
      "A",
      "B",
      "C",
      "D",
      "E",
      "F",
      "G",
      "H",
      "I",
      "J",
      "K",
      "L",
      "M",
      "N",
      "O",
      "P",
      "Q",
      "R",
      "S",
      "T",
      "U",
      "V",
      "W",
      "X",
      "Y",
      "Z"
    ],
    [
      "a",
      "b",
      "c",
      "d",
      "e",
      "f",
      "g",
      "h",
      "i",
      "j",
      "k",
      "l",
      "m",
      "n",
      "o",
      "p",
      "q",
      "r",
      "s",
      "t",
      "u",
      "v",
      "w",
      "x",
      "y",
      "z"
    ],
    [0, 1, 2, 3, 5, 6, 7, 8, 9],
    ["!", "@", "&", "%", "^", "*", "(", ")", "_", "-", "+", "=", "+"]
  ];
  List result = [];
  var rand = Random(), stringResult;

  String genPassword({int passwordSize}) {
    for (int i = 0; i < passwordSize; i++) {
      int parentRandIndex = rand.nextInt(parent.length);
      int indexOfChild = rand.nextInt(parent[parentRandIndex].length);
      var value = parent[parentRandIndex][indexOfChild];
      result.add(value);
    }
    stringResult = result.join();
    result.clear();
    return stringResult;
  }
}
