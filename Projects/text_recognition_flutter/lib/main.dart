import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:text_recognition_flutter/povider/text_provider.dart';
import 'package:text_recognition_flutter/screen/text_recognition_screen.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider<TextProvider>(
      create: (context) => TextProvider(),
      child: MaterialApp(
        title: 'Text Reader',
        theme: ThemeData(
          appBarTheme: AppBarTheme(
            brightness: Brightness.dark,
            color: Colors.black87,
            textTheme: TextTheme(
              bodyText1: TextStyle(color: Colors.red),
              // bodyText2: TextStyle(color: Colors.white),
              headline6: TextStyle(
                  color: Colors.red, fontSize: 20, fontWeight: FontWeight.bold),
            ),
          ),
          brightness: Brightness.dark,
          accentColor: Colors.redAccent,
          primaryColorLight: Colors.red.shade400,
          primaryColorDark: Colors.red.shade900,
          primaryColor: Colors.red,
          textTheme: TextTheme(
            bodyText1: TextStyle(color: Colors.red),
            bodyText2: TextStyle(color: Colors.red),
            // bodyText2: TextStyle(color: Colors.white),
            headline4: TextStyle(color: Colors.red),
            headline3: TextStyle(color: Colors.red),
            //Alert Box Title
            headline6: TextStyle(color: Colors.red.shade900),
          ),
        ),
        home: TextRecognitionScreen(),
        debugShowCheckedModeBanner: false,
      ),
    );
  }
}
