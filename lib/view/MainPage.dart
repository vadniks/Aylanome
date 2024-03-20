
import 'package:aylanome/presenter/MainPagePresenter.dart';
import 'package:flutter/material.dart';
import 'package:meta/meta.dart';

@sealed
class MainPage extends StatefulWidget {
  const MainPage({super.key});

  @override
  State<StatefulWidget> createState() => MainPagePresenter();
}
