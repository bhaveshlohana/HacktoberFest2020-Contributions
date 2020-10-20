import 'package:image_picker/image_picker.dart';

class CameraHelper {
  final _picker = ImagePicker();

  Future<PickedFile> getImagefromCamera() async {
    PickedFile awaitImage = await _picker.getImage(
      source: ImageSource.camera,
    );
    return awaitImage;
  }

  Future<PickedFile> getImagefromGallery() async {
    PickedFile awaitImage = await _picker.getImage(
      source: ImageSource.gallery,
    );
    return awaitImage;
  }
}
