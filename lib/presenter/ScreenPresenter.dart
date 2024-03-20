
import 'package:aylanome/view/MainPage.dart';
import 'package:aylanome/view/Screen.dart';
import 'package:flutter/material.dart';
import 'package:meta/meta.dart';

@sealed
class ScreenPresenter extends State<Screen> {

  @override
  Widget build(BuildContext context) => MaterialApp(
    title: 'todo',
    debugShowCheckedModeBanner: false,
    theme: ThemeData.light(useMaterial3: true),
    darkTheme: ThemeData.dark(useMaterial3: true),
    initialRoute: '/',
    routes: {
      '/' : (context) => const MainPage()
    },
  );

  static void init() => runApp(const Screen());
}
