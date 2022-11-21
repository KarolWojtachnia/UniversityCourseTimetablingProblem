#include "UCTP_instance.h"

#include <fstream>
#include <iostream>

int** initialise(int rows, int columns) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[columns];

    return matrix;
}

void UCTP_instance::readFromTimFile(string filepath) {

    //otworzenie pliku
    fstream file;
    file.open(filepath, ios::in);
    if (!file.good()) {
        cout << "nie mozna otworzyc pliku!" << endl;
        exit(1);
    }

    //wczytanie kolejno 
    file >> events_num; //liczby zajec
    file >> rooms_num;  //, sal, zasobow, studentow
    file >> features_num;
    file >> students_num;

    //wczytywanie pojemnosci sal
    int temp_size;
    for (int i = 0; i < rooms_num; i++) {
        file >> temp_size;
        room_sizes.push_back(temp_size);
    }

    //wczytywanie macierzy przypisania studentów do zajec
    evenets_of_students = initialise(students_num, events_num);
    for (int i = 0; i < students_num; i++) {
        for (int j = 0; j < events_num; j++) {
            file >> evenets_of_students[i][j];
        }
    }

    //wczytywanie macierzy zasobow posiadanych przez sale
    features_of_rooms = initialise(rooms_num, features_num);
    for (int i = 0; i < rooms_num; i++) {
        for (int j = 0; j < features_num; j++) {
            file >> features_of_rooms[i][j];
        }
    }

    //wczytywanie liczby zasobow wymaganych dla zajec
    features_of_events = initialise(events_num, features_num);
    for (int i = 0; i < events_num; i++) {
        for (int j = 0; j < features_num; j++) {
            file >> features_of_events[i][j];
        }
    }

    file.close();

    //wyliczenie liczby studentow dla kazdych zajêæ
    for (int i = 0; i < events_num; i++) {
        int sum=0;
        for (int j = 0; j < students_num; j++) {
            sum += evenets_of_students[j][i];
        }
        studens_num_for_event.push_back(sum);
    }

    //wyliczenie zajêæ, które wymagaj¹ tych samych studentów
    same_student_events = initialise(events_num, events_num);
    //wypelnienie zerami
    for (int i = 0; i < events_num; i++) {
        for (int j = 0; j < events_num; j++) {
            same_student_events[i][j] = 0;
        }
    }

    for (int i = 0; i < events_num; i++) {
        for (int j = 0; j < events_num; j++) {
            for (int k = 0; k < students_num; k++) {
                if ((evenets_of_students[k][i] == 1) && (evenets_of_students[k][j] == 1)) {
                    same_student_events[i][j] = 1;
                    break;
                }
            }
        }
    }

    //wyliczenie sal mieszcz¹cych liczbe studentow i spelniajacych wymagania zasobów
    rooms_sutable_for_events = initialise(events_num, rooms_num);
    for (int i = 0; i < events_num; i++) {
        for (int j = 0; j < rooms_num; j++) {
            rooms_sutable_for_events[i][j] = 0;
        }
    }
    int k = 0;
    for (int i = 0; i < events_num; i++) {
        for (int j = 0; j < rooms_num; j++) {
            if ((room_sizes[j] >= studens_num_for_event[i])) {
                for (k = 0; k < features_num; k++) {
                    if (features_of_events[i][k] == 1 && features_of_rooms[j][k] == 0)
                        break;
                }
                if (k == features_num)
                    rooms_sutable_for_events[i][j] = 1;
            }
        }
    }
}


