// UCTP.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "UCTP_instance.h"

int main()
{
    UCTP_instance instance;
    string filename;

    cout << "Podaj nazwe pliku\n";
    cin >> filename;

    instance.readFromTimFile("instances/" + filename);

    cout << "Wczytane parametry:\n";
    cout << "l. zajec:     " << instance.events_num << endl;
    cout << "l. sal:       " << instance.rooms_num << endl;
    cout << "l. zasobow:   " << instance.features_num << endl;
    cout << "l. studentow: " << instance.students_num << endl;

    cout << "Kolejne rozmiary sal:\n";
    for (int i = 0; i < instance.rooms_num; i++) {
        cout <<i <<")" << instance.room_sizes[i] << endl;
    }

    
    cout << "\n\n\n";
    cout << "Macierz zajec przypisanych do studentow\nkol -> zajecia  wier -> studenci\n";
    for (int i = 0; i < instance.students_num; i++) {
        for (int j = 0; j < instance.events_num; j++) {
            cout << instance.evenets_of_students[i][j];
        }
        cout << endl;
    }

    cout << "\n\n\n";
    cout << "Macierz zasobow przypisanych do sal\nkol -> zasoby  wier -> sale\n";
    for (int i = 0; i < instance.rooms_num; i++) {
        for (int j = 0; j < instance.features_num; j++) {
            cout << instance.features_of_rooms[i][j];
        }
        cout << endl;
    }

    cout << "\n\n\n";
    cout << "Macierz zasobow przypisanych do zajec\nkol -> zasoby  wier -> zajecia\n";
    for (int i = 0; i < instance.events_num; i++) {
        for (int j = 0; j < instance.features_num; j++) {
            cout << instance.features_of_events[i][j];
        }
        cout << endl;
    }
    

    cout << "Number of students for each event:\n";
    for (int j = 0; j < instance.studens_num_for_event.size(); j++) {
        cout << instance.studens_num_for_event[j] <<endl;
    }
    cout << endl;
    

    cout << "Macierz zajec o wspolnych studentach\n";
    cout << "wiersze -> zajecia / kolumny -> zajecia\n";
    for (int i = 0; i < instance.events_num; i++) {
        for (int j = 0; j < instance.events_num; j++) {
            cout << instance.same_student_events[i][j];
        }
        cout << endl;
    }
    cout << endl;

    cout << "Macierz sal spelniajacych wymagania zajec\n";
    cout << "wiersze -> zajecia / kolumny -> sale\n";
    for (int i = 0; i < instance.events_num; i++) {
        for (int j = 0; j < instance.rooms_num; j++) {
            cout << instance.rooms_sutable_for_events[i][j];
        }
        cout << endl;
    }


    cout << "\n\nKONIEC";
    
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
