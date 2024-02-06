#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
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
	string filenames[]={"computer_architecture","daa","microprocessors",
	"probability_and_statistics","sts",
	"theory_of_computation","web_programing","daa_lab","microprocessors_lab","probability_and_statistics_lab","web_programing_lab"};
	mp["computer_architecture"]={3,"BCSE205L"};
	mp["daa"]={3,"BCSE204L"};
	mp["microprocessors"]={3,"BECE204L"};
	mp["probability_and_statistics"]={3,"BMAT202L"};
	mp["sts"]={1.5,"BSTS102P"};
	mp["theory_of_computation"]={3,"BCSE304L"};
	mp["web_programing"]={1,"BCSE203E"};
	mp["daa_lab"]={1,"BCSE204P"};
	mp["microprocessors_lab"]={1,"BECE204P"};
	mp["probability_and_statistics_lab"]={1,"BMAT202P"};
	mp["web_programing_lab"]={2,"BCSE203E"};
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
