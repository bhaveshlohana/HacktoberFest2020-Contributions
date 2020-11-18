import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:audioplayers/audio_cache.dart';
void main() {
  runApp(AlphabetApp());
}
class AlphabetApp extends StatelessWidget {
  void playsound(String ab){
    final player = AudioCache();
    player.play('$ab.mp3');
  }
    FlatButton buildkey(String s){
   return FlatButton(
      onPressed: (){

        playsound(s);
      },

      child:Image.asset('images/icons8-$s-64.png'),
    );
  }
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
         home: SafeArea(
           child: Scaffold(
             appBar: AppBar(
               backgroundColor: Colors.white,
               title: Center(
                 child: Text(
                     'Alphabets',
                 style: TextStyle(
                     color: Colors.black
                 ),),
               ),


             ),
           body: Container(
             padding: EdgeInsets.only(top: 10),
             margin: EdgeInsets.only(top: 10),
             color: Colors.black,
             child: Column(

               children: [
                 Row(

                   children: [
                    buildkey('a'),
                     buildkey('b'),
                     buildkey('c'),
                     buildkey('d'),

                   ],
                 ),
                SizedBox(
                  height: 30,
                ),
                Row(
                  children: [

                    buildkey('e'),
                    buildkey('f'),
                    buildkey('g'),
                    buildkey('h'),
                  ],
                ),
                 SizedBox(
                   height: 40,
                 ),
                 Row(
                   children: [

                     buildkey('i'),
                     buildkey('j'),
                     buildkey('k'),
                     buildkey('l'),
                   ],
                 ),
                 SizedBox(
                   height: 30,
                 ),
                 Row(
                   children: [

                     buildkey('m'),
                     buildkey('n'),
                     buildkey('o'),
                     buildkey('p'),
                   ],
                 ),
                 SizedBox(
                   height: 30,
                 ),
                 Row(
                   children: [

                     buildkey('q'),
                     buildkey('r'),
                     buildkey('s'),
                     buildkey('t'),
                   ],
                 ),
                 SizedBox(
                   height: 30,
                 ),
                 Row(
                   children: [

                     buildkey('u'),
                     buildkey('v'),
                     buildkey('w'),
                     buildkey('x'),
                   ],

                 ),
                 SizedBox(
                   height:30,
                 ),
                 Row(
                   children: [

                     buildkey('y'),
                     buildkey('z'),

                   ],
                 )

               ],
             ),
           ),
),
         ),
    );
  }
}


