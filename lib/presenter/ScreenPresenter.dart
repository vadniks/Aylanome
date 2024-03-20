
import 'package:aylanome/presenter/Consts.dart';
import 'package:aylanome/view/MainPage.dart';
import 'package:aylanome/view/Screen.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:meta/meta.dart';

@sealed
class ScreenPresenter extends State<Screen> {
  static const _DARK_SECONDARY_COLOR = Color(0xFF0F0F0F);

  @override
  Widget build(BuildContext context) => MaterialApp(
    title: Consts.appName,
    debugShowCheckedModeBanner: false,
    theme: ThemeData.light(useMaterial3: true),
    darkTheme: ThemeData.dark(useMaterial3: true).copyWith(
      primaryColor: Colors.cyan,
      brightness: Brightness.dark,
      scaffoldBackgroundColor: Colors.black,
      canvasColor: Colors.black,
      dialogBackgroundColor: _DARK_SECONDARY_COLOR,
      snackBarTheme: const SnackBarThemeData(backgroundColor: _DARK_SECONDARY_COLOR),
      listTileTheme: const ListTileThemeData(tileColor: Colors.transparent),
      cardColor: Colors.black,
      colorScheme: const ColorScheme.dark(
        background: Colors.black,
        primary: Colors.cyan,
        surface: _DARK_SECONDARY_COLOR,
        onSecondary: _DARK_SECONDARY_COLOR,
        onSurface: Colors.white70,
      ),
      appBarTheme: const AppBarTheme(
        backgroundColor: _DARK_SECONDARY_COLOR,
        systemOverlayStyle: SystemUiOverlayStyle(
          statusBarColor: Colors.black,
          statusBarBrightness: Brightness.dark,
          statusBarIconBrightness: Brightness.light,
          systemNavigationBarColor: Colors.black,
          systemNavigationBarIconBrightness: Brightness.light,
        )
      )
    ),
    initialRoute: Consts.routeMain,
    routes: {
      Consts.routeMain : (context) => const MainPage()
    },
  );

  static void init() => runApp(const Screen());
}
