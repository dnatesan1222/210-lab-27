// COMSC-210 | Lab 27 | Diksha Tara Natesan
// IDE used: Vim/Terminal

#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    map<string, tuple<int, string, string>> villagerInfo;

    villagerInfo["Audie"] = make_tuple(9, "Cow", "Legendary");
    villagerInfo["Raymond"] = make_tuple(7, "Elephant", "I only have one rule");
    villagerInfo.insert({"Marshal", make_tuple(8, "Dog", "True story")});

    cout << "Villagers and their info (range-based for loop):" << endl;
    for (auto pair : villagerInfo) {
        cout << pair.first << ": "
             << "Friendship Level=" << get<0>(pair.second) << ", "
             << "Species=" << get<1>(pair.second) << ", "
             << "Catchphrase=" << get<2>(pair.second) << endl;
    }

    cout << "\nVillagers and their info (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerInfo.begin(); 
                                                         it != villagerInfo.end(); ++it) {
        cout << it->first << ": "
             << "Friendship Level=" << get<0>(it->second) << ", "
             << "Species=" << get<1>(it->second) << ", "
             << "Catchphrase=" << get<2>(it->second) << endl;
    }

    villagerInfo.erase("Raymond");

    string searchKey = "Audie";
    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {
        cout << "\nFound " << searchKey << "'s info: "
             << "Friendship Level=" << get<0>(it->second) << ", "
             << "Species=" << get<1>(it->second) << ", "
             << "Catchphrase=" << get<2>(it->second) << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    cout << "\nSize before clear: " << villagerInfo.size() << endl;
    villagerInfo.clear();
    cout << "Size after clear: " << villagerInfo.size() << endl;

    return 0;
}
