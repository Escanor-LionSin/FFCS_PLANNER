#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;


class Subject{
	private:
		string name;
		int no_of_credits;
		string Course_code;
		string type;
		vector<string> available_slots;
		map<string,vector<string>>teachers;
	public:
    	Subject(string n, int credits, string code) {
    		name = n;
    		no_of_credits = credits;
    		Course_code = code;
		}
    	void addSlot(string slot) {
        	available_slots.push_back(slot);
    	}
    	void addTeacher(string slot, string teacher) {
        	teachers[slot].push_back(teacher);
    	}
    	void setType(string t) {
        	type = t;
    	}
    	string getName() const {
        	return name;
    	}
    	int getCredits() const {
        	return no_of_credits;
    	}
    	string getCourseCode() const {
        	return Course_code;
    	}
    	string getType() const {
        	return type;
    	}
    	const vector<string>& getAvailableSlots() const {
        	return available_slots;
    	}
    	const map<string, vector<string>>& getTeachers() const {
        	return teachers;
    	}
};

map<string,pair<int,string>> mp;

int main(){
	vector<Subject>subjects;
	ifstream file("subject_data/subject_name_list.csv");
	list<string> filenames;
	if(file.is_open()){
		string line1;
		while(getline(file,line1)){
			istringstream linestream(line1);
			string name1,credit1,code1;
			getline(linestream,name1,',');
			getline(linestream,credit1,',');
			getline(linestream,code1,',');
			filenames.push_back(name1);
			mp[name1]={stoi(credit1),code1};
		}
}
	for (string subjectname:filenames){
		string filename="subject_data/"+subjectname+".csv";
		ifstream file(filename.c_str());
		string dummy;
		if(file.is_open()){
			set<string> uniqueslots;
			string line;
			Subject mySub(subjectname,mp[subjectname].first,mp[subjectname].second);
			while(getline(file,line)){
				istringstream linestream(line);
				string slot,teacher,type;
				getline(linestream,slot,',');
				getline(linestream,dummy,',');
				getline(linestream,teacher,',');
				getline(linestream,type,',');
				uniqueslots.insert(slot);
				mySub.addTeacher(slot,teacher);
				mySub.setType(type);
			}
			for(string slot : uniqueslots){
				mySub.addSlot(slot);
			}
			subjects.push_back(mySub);
		}
		file.close();	
		}
		for (const auto &subject : subjects) {
        cout << "Subject Name: " << subject.getName() << endl;
        cout << "Credits: " << subject.getCredits() << endl;
        cout << "Course Code: " << subject.getCourseCode() << endl;
        cout << "Type: " << subject.getType() << endl;

        cout << "Available Slots: ";
        for (const auto &slot : subject.getAvailableSlots()) {
            cout << slot << " ";
        }
        cout << endl;

        cout << "Teachers: " << endl;
        for (const auto &entry : subject.getTeachers()) {
            const string &slot = entry.first;
            const vector<string> &teacherList = entry.second;

            cout << "Slot: " << slot << ", Teachers: ";
            for (const auto &teacher : teacherList) {
                cout << teacher << " ";
            }
            cout << endl;
        }
		cout<<"-------------------------------"<<endl;
	}
}
