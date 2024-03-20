
import 'package:aylanome/view/MainPage.dart';
import 'package:flutter/material.dart';
import 'package:meta/meta.dart';

@sealed
class MainPagePresenter extends State<MainPage> {

  @override
  Widget build(BuildContext context) => Scaffold(
    appBar: AppBar(
      backgroundColor: Theme.of(context).colorScheme.inversePrimary,
      title: const Text('Title'),
    ),
    body: const Column(
      mainAxisAlignment: MainAxisAlignment.center,
      crossAxisAlignment: CrossAxisAlignment.center,
      children: [
        Center(child: Text('Body'))
      ],
    ),
    floatingActionButton: FloatingActionButton(
      tooltip: 'todo',
      onPressed: () {  },
      child: const Icon(Icons.add),
    ),
  );
}
