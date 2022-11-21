#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;
class UCTP_instance
{
public:
	UCTP_instance() {}
	~UCTP_instance() {}

	int events_num;
	int rooms_num;
	int features_num;
	int students_num;

	vector<int> studens_num_for_event;
	vector<int> room_sizes;

	int** evenets_of_students; //przypisanie studentów do zajec
	int** same_student_events; //zaejcia z tymi samymi studentami
	int** features_of_rooms; //zasoby sal
	int** features_of_events; //wymagane zasoby dla zajec
	int** rooms_sutable_for_events; //pokoje spelniajace wymagania zajec

	void readFromTimFile(string filepath);




};

