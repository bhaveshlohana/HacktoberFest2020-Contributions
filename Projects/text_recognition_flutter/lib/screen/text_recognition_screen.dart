import 'dart:io';

import 'package:firebase_ml_vision/firebase_ml_vision.dart';
import 'package:flutter/material.dart';
import 'package:image_picker/image_picker.dart';
import 'package:provider/provider.dart';
import 'package:text_recognition_flutter/helper/camera_helper.dart';
import 'package:text_recognition_flutter/povider/text_provider.dart';

class TextRecognitionScreen extends StatelessWidget {
  final _camHelper = CameraHelper();

  _retrieveText({PickedFile awaitImage, TextProvider textProvider}) async {
    File pickedImage;

    pickedImage = File(awaitImage.path);
    textProvider.setImage(pickedImage);
    textProvider.uploadImage(true);

    FirebaseVisionImage _visionImage =
        FirebaseVisionImage.fromFile(pickedImage);
    final _textRecognizer = FirebaseVision.instance.textRecognizer();

    VisionText visionText = await _textRecognizer.processImage(_visionImage);
    textProvider.decodeText(visionText.blocks);
    _textRecognizer.close();
  }

  @override
  Widget build(BuildContext context) {
    final _textProvider = Provider.of<TextProvider>(context);
    return Scaffold(
      appBar: AppBar(
        title: Text('Text Recognition'),
      ),
      body: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          Center(
            child: Container(
              decoration: BoxDecoration(
                color: Colors.white,
                boxShadow: const [
                  BoxShadow(blurRadius: 20),
                ],
              ),
              margin: const EdgeInsets.symmetric(vertical: 16),
              height: 250,
              child: _textProvider.imgStatus
                  ? Image.file(
                      _textProvider.image,
                      fit: BoxFit.cover,
                    )
                  : Image.asset(
                      'assets/images/unnamed.jpg',
                      fit: BoxFit.cover,
                    ),
            ),
          ),
          Expanded(
            child: CustomScrollView(
              physics: BouncingScrollPhysics(),
              slivers: [
                SliverList(
                  delegate: SliverChildListDelegate(
                    [
                      SizedBox(height: 10.0),
                      SizedBox(height: 10.0),
                      Container(
                        padding: const EdgeInsets.all(16),
                        child: Text(
                          _textProvider.text.trim().isEmpty
                              ? 'No Images selected'
                              : _textProvider.text.trim(),
                        ),
                      )
                    ],
                  ),
                )
              ],
            ),
          ),
        ],
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => _selectImageDialog(
          context: context,
          textProvider: _textProvider,
        ),
        child: Icon(Icons.search),
      ),
    );
  }

  _buttonContainer({
    BuildContext context,
    IconData icon,
    Function function,
    String title,
  }) {
    var _height = MediaQuery.of(context).size.height;
    var _width = MediaQuery.of(context).size.width;
    return Container(
      height: _height * 0.12,
      width: _width * 0.24,
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(15),
        border: Border.all(
          color: Theme.of(context).primaryColorDark,
          width: 2,
        ),
      ),
      child: InkWell(
        borderRadius: BorderRadius.circular(15),
        splashColor: Colors.red.shade100,
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              Icon(
                icon,
                size: _width * 0.12,
                color: Theme.of(context).primaryColor,
              ),
              Text(
                title,
                style: TextStyle(
                  color: Theme.of(context).primaryColor,
                ),
              ),
            ],
          ),
        ),
        onTap: function,
      ),
    );
  }

  _selectImageDialog(
      {@required BuildContext context, @required TextProvider textProvider}) {
    showDialog(
        context: context,
        builder: (BuildContext ctx) {
          //Here we will build the content of the dialog
          return AlertDialog(
            title: Text("Alert Dialog"),
            shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(20.0),
            ),
            content: Row(
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              children: [
                _buttonContainer(
                  context: context,
                  icon: Icons.image,
                  title: 'Gallery',
                  function: () async {
                    print('Gallery Clicked');
                    var awaitImage = await _camHelper.getImagefromGallery();
                    _retrieveText(
                        awaitImage: awaitImage, textProvider: textProvider);
                    Navigator.pop(context);
                  },
                ),
                SizedBox(
                  width: 20,
                ),
                _buttonContainer(
                  context: context,
                  icon: Icons.camera_alt,
                  title: 'Camera',
                  function: () async {
                    print('Camera Clicked');
                    var awaitImage = await _camHelper.getImagefromCamera();
                    _retrieveText(
                        awaitImage: awaitImage, textProvider: textProvider);
                    Navigator.pop(context);
                  },
                ),
              ],
            ),
          );
        });
  }
}
