import 'package:flutter/material.dart';
import 'package:randomPassword/passwordGen.dart';

class Homepage extends StatefulWidget {
  @override
  _HomepageState createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  int size, _groupValue;
  String pasResult;

  handelRadio(int val) {
    setState(() {
      switch (val) {
        case 0:
          _groupValue = 0;
          size = 8;
          break;
        case 1:
          _groupValue = 1;
          size = 12;
          break;
        case 2:
          _groupValue = 2;
          size = 16;
          break;
        case 3:
          _groupValue = 3;
          size = 18;
          break;
        default:
          _groupValue = 0;
          size = 8;
          break;
      }
    });
  }

  Password _password = Password();
  generatePass() {
    setState(() {
      pasResult = _password.genPassword(passwordSize: size);
    });
  }

  @override
  void initState() {
    super.initState();
    _groupValue = 0;
    size = 8;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Generate Random Password"),
      ),
      body: Container(
        alignment: Alignment.center,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Container(
                  width: 200,
                  child: ListTile(
                    leading: Radio(
                        value: 0,
                        groupValue: _groupValue,
                        onChanged: (val) => handelRadio(val)),
                    title: Text("8 Character"),
                  ),
                ),
                Container(
                  width: 200,
                  child: ListTile(
                    leading: Radio(
                        value: 1,
                        groupValue: _groupValue,
                        onChanged: (val) => handelRadio(val)),
                    title: Text("12 Character"),
                  ),
                ),
                Container(
                  width: 200,
                  child: ListTile(
                    leading: Radio(
                        value: 2,
                        groupValue: _groupValue,
                        onChanged: (val) => handelRadio(val)),
                    title: Text("16 Character"),
                  ),
                ),
                Container(
                  width: 200,
                  child: ListTile(
                    leading: Radio(
                        value: 3,
                        groupValue: _groupValue,
                        onChanged: (val) => handelRadio(val)),
                    title: Text("18 Character"),
                  ),
                ),
              ],
            ),
            SelectableText(
              pasResult == null ? "Generate First" : pasResult,
              style: selectableTextStyle,
            ),
            MaterialButton(
              child: Text("Generate Password"),
              onPressed: generatePass,
              color: Colors.blue,
            ),
          ],
        ),
      ),
    );
  }
}

const selectableTextStyle = TextStyle(
  fontSize: 20,
  fontWeight: FontWeight.bold,
);
