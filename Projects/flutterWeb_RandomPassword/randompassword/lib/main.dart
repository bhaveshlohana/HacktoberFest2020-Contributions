import 'package:flutter/material.dart';

import 'homePage.dart';

void main() {
  runApp(
    MyApp(),
  );
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: "Random Password Generator",
      home: Homepage(),
    );
  }
}
