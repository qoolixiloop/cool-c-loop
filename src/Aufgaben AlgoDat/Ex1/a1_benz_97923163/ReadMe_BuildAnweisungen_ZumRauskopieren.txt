Das Projekt lässt sich auf meinem Ubuntu Rechner mit den
untenstehenden Anweisungen compilieren und linken.
----------------------------------------------------------------------
Bemerkung zur letzten Zeile:
Ich bin fürs Linken auf auf g++ ausgewichen.
Das Linken mit gcc erzeugt auf meinem Rechner die Fehlermeldung:
undefined reference to symbol 'pow@@GLIBC_2.0'
/lib/i386-linux-gnu/libm.so.6: error adding symbols: DSO missing from command line
collect2: error: ld returned 1 exit status
----------------------------------------------------------------------
Im Ordner befindet sich auch das QT Projektfile und
und im Ordner build die object und executable files
Gruss Roland Benz
----------------------------------------------------------------------



gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o main.o ../a1_benz_97923163/main.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task1.o ../a1_benz_97923163/task1.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task3.o ../a1_benz_97923163/task3.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task2.o ../a1_benz_97923163/task2.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task5.o ../a1_benz_97923163/task5.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task6.o ../a1_benz_97923163/task6.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task4.o ../a1_benz_97923163/task4.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task7b.o ../a1_benz_97923163/task7b.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task7a.o ../a1_benz_97923163/task7a.c
g++  -o a1_benz_97923163 main.o task1.o task3.o task2.o task5.o task6.o task4.o task7b.o task7a.o   -lGLU -lGL -lglut 
