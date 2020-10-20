import 'dart:io';

import 'package:firebase_ml_vision/firebase_ml_vision.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';

class TextProvider with ChangeNotifier {
  String _displayText = '';
  bool _imgUploaded = false;
  File _pickedImage;

  File get image => _pickedImage;
  String get text => _displayText;
  bool get imgStatus => _imgUploaded;

  void uploadImage(bool isUploded) {
    _imgUploaded = isUploded;
    notifyListeners();
  }

  void setImage(File imgFile) {
    _pickedImage = imgFile;
    notifyListeners();
  }

  void decodeText(List<TextBlock> mlText) {
    var tmp = '';
    mlText.forEach((block) {
      block.lines.forEach((line) {
        line.elements.forEach((word) {
          tmp = tmp + word.text + ' ';
        });
        tmp = tmp + '\n';
      });
    });
    _displayText = tmp;
    notifyListeners();
  }
}
