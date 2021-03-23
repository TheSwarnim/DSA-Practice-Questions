import 'dart:io';

main() {
  int n = int.parse(stdin.readLineSync()!);

  int sp = n ~/ 2;
  int st = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sp; j++) {
      stdout.write("\t");
    }

    for (int j = 1; j <= st; j++) {
      stdout.write("*\t");
    }

    if (i <= n / 2) {
      sp--;
      st += 2;
    } else {
      sp++;
      st -= 2;
    }

    print("\n");
  }
}
