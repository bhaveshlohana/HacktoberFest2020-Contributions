import 'package:flutter/material.dart';
import 'location_screen.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';
import 'package:clima/services/weather.dart';



class LoadingScreen extends StatefulWidget {
  @override
  _LoadingScreenState createState() => _LoadingScreenState();
}

class _LoadingScreenState extends State<LoadingScreen> {

  void initState(){
    super.initState();

    getLocationdata();

  }

 void getLocationdata() async{
   WeatherModel weathermodel = WeatherModel();
   var weatherData = await weathermodel.locationWeatherData();
   Navigator.push(context, MaterialPageRoute(builder: (context) {
     return LocationScreen(weatherData);
   }));
 }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: SpinKitDoubleBounce(
          color: Colors.grey,
          size: 100,
        ),
      ),
    );
  }
}
