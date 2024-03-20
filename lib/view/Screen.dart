
import 'package:aylanome/presenter/ScreenPresenter.dart';
import 'package:flutter/material.dart';
import 'package:meta/meta.dart';

@sealed
class Screen extends StatefulWidget {
  const Screen({super.key});

  @override
  State<StatefulWidget> createState() => ScreenPresenter();
}
