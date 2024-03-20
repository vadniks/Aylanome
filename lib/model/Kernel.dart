
import 'package:aylanome/presenter/ScreenPresenter.dart';
import 'package:meta/meta.dart';

@sealed
class Kernel {

  Kernel() {
    ScreenPresenter.init();
  }
}
