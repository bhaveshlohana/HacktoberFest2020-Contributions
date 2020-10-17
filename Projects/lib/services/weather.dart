import 'package:clima/services/location.dart';
import 'package:clima/services/networking.dart';


String apiKey = '017cfcfb7a210b7df3f362a1bd5c269e';
class WeatherModel {
  Future<dynamic> cityWeather(String city)async  {
    Network net =  Network(url: 'https://api.openweathermap.org/data/2.5/weather?q=$city&appid=$apiKey&units=metric');
    return await net.getData();
  }
  Future<dynamic> locationWeatherData()async{
    Location getLocation = Location();
    await getLocation.getCurrentLocation();
    double latitude = getLocation.latitude;
    double longitude = getLocation.longitude;
    Network net = Network(url: 'https://api.openweathermap.org/data/2.5/weather?lat=$latitude&lon=$longitude&appid=$apiKey&units=metric');
    return net.getData();
  }
  String getWeatherIcon(int condition) {

    if (condition < 300) {
      return '🌩';
    } else if (condition < 400) {
      return '🌧';
    } else if (condition < 600) {
      return '☔';
    } else if (condition < 700) {
      return '☃';
    } else if (condition < 800) {
      return '🌫';
    } else if (condition == 800) {
      return '☀';
    } else if (condition <= 804) {
      return '☁';
    } else {
      return '🤷‍';
    }
  }

  String getMessage(int temp) {
    if (temp > 25) {
      return 'It\'s 🍦 time';
    } else if (temp > 20) {
      return 'Time for shorts and 👕';
    } else if (temp < 10) {
      return 'You\'ll need 🧣 and 🧤';
    } else {
      return 'Bring a 🧥 just in case';
    }
  }
}
