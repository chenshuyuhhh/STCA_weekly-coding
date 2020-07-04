#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string tolower(string S) {
    string s;
    for (char c:S) {
        if ('A' <= c && c <= 'Z') s += (c + 32);
        else s += c;
    }
    return s;
}

string tovowel(string s) {
    string vowel;
    set<char> vs{'a', 'e', 'i', 'o', 'u'};
    for (char c: s) {
        if (vs.find(c) != vs.end()) {
            vowel += '*';
        } else vowel += c;
    }
    return vowel;
}

vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
    map<string, int> slow;
    map<string, int> vowels;
    set<string> original;

    for (int i = 0; i < wordlist.size(); ++i) {
        original.insert(wordlist[i]);
        string temp = tolower(wordlist[i]);
        slow.insert(pair<string, int>(temp, i));

        // 'a', 'e', 'i', 'o', 'u'
        string vowel = tovowel(temp);
        if (vowel == temp) continue; // same as lower case
        vowels.insert(pair<string, int>(vowel, i));
    }

    vector<string> v;
    for (const string &query:queries) {
        // has same or case-insensitive
        if (original.find(query) != original.end()) {
            v.push_back(query);
            continue;
        }
        string temp = tolower(query);
        if (slow.find(temp) != slow.end()) {
            v.push_back(wordlist[slow[temp]]);
            continue;
        }

        // 'a', 'e', 'i', 'o', 'u'
        string vowel = tovowel(query);
        if (vowels.find(vowel) != vowels.end()) {
            v.push_back(wordlist[vowels[vowel]]);
            continue;
        }

        v.emplace_back("");
    }
    return v;
}

//int main() {
//    vector<string> wordlist = {"wg", "uo", "as", "kv", "ra", "mw", "gi", "we", "og", "zu"};
//    vector<string> query = {"AS", "in", "yc", "kv", "mw", "ov", "lc", "os", "wm", "Mw"};
//    spellchecker(wordlist, query);
//    cout << " ";
//}
