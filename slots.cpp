#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string, vector<string>> slots;


    //MORNING SLOTS

    //THEORY

    slots["A1"] = {"L1", "L2", "L13", "L14"};
    slots["B1"] = {"L7", "L8", "L19", "L20"};
    slots["C1"] = {"L13", "L14", "L25", "L26"};
    slots["D1"] = {"L3", "L4", "L19", "L20"};
    slots["E1"] = {"L9", "L10", "L25", "L26"};
    slots["F1"] = {"L1", "L2", "L15", "L16"};
    slots["G1"] = {"L7", "L8", "L21", "L22"};
    slots["TA1"] = {"L27", "L28"};
    slots["TB1"] = {"L3", "L4"};
    slots["TC1"] = {"L9", "L10"};
    slots["TD1"] = {"L29", "L30"};
    slots["TE1"] = {"L21", "L22"};
    slots["TF1"] = {"L27", "L28"};
    slots["TG1"] = {"L5", "L6"};
    slots["TAA1"] = {"L11", "L12"};
    slots["TCC1"] = {"L23", "L24"};

    //LAB

    slots["L1+L2"] = {"A1", "F1"};
    slots["L3+L4"] = {"D1", "TB1"};
    slots["L5+L6"] = {"TG1"};
    slots["L7+L8"] = {"B1", "G1"};
    slots["L9+L10"] = {"E1", "TC1"};
    slots["L11+L12"] = {"TAA1"};
    slots["L13+L14"] = {"C1", "A1"};
    slots["L15+L16"] = {"F1"};
    slots["L19+L20"] = {"D1", "B1"};
    slots["L21+L22"] = {"G1", "TE1"};
    slots["L23+L24"] = {"TCC1"};
    slots["L25+L26"] = {"E1", "C1"};
    slots["L27+L28"] = {"TA1", "TF1"};
    slots["L29+L30"] = {"TD1"};


    // AFTER NOON SLOTS

    // THEORY

    slots["A2"] = {"L31", "L44", "L32", "L43" };
    slots["F2"] = {"L32", "L45", "L31", "L44" };
    slots["D2"] = {"L33", "L34", "L49", "L50"};
    slots["B2"] = {"L37", "L38", "L50", "L51"};
    slots["C2"] = {"L43", "L44", "L55", "L56"};
    slots["E2"] = {"L39", "L40", "L55", "L56"};
    slots["G2"] = {"L37", "L38", "L51", "L52"};
    slots["TA2"] = {"L57", "L58"};
    slots["TB2"] = {"L33", "L34"};
    slots["TC2"] = {"L39", "L40"};
    slots["TD2"] = {"L45", "L46"};
    slots["TE2"] = {"L51", "L52"};
    slots["TF2"] = {"L57", "L58"};
    slots["TG2"] = {"L35", "L36"};
    slots["TAA2"] = {"L41", "L42"};
    slots["TBB2"] = {"L47", "L48"};
    slots["TCC2"] = {"L53", "L54"};
    slots["TDD2"] = {"L59", "L60"};

    //LAB

    slots["L31+L32"] = {"A2", "F2"};
    slots["L33+L34"] = {"D2", "TB2"};
    slots["L35+L36"] = {"TG2"};
    slots["L37+L38"] = {"B2", "G2"};
    slots["l39+L40"] = {"E2", "TC2"};
    slots["L41+L42"] = {"TAA2"};
    slots["L43+L44"] = {"C2", "A2"};
    slots["L45+L46"] = {"F2", "TD2"};
    slots["l47+L48"] = {"TBB2"};
    slots["L49+L50"] = {"D2", "B2" };
    slots["L51+L52"] = {"G2", "TE2"};
    slots["L53+L54"] = {"TCC2"};
    slots["L55+L56"] = {"E2", "C2"};
    slots["L57+L58"] = {"TA2", "TF2"};
    slots["L59+L60"] = {"TDD2"};

}

