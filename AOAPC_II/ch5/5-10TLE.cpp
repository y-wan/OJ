#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>
//#include <ctime>

using namespace std;
//typedef map<string, set<pair<int, int> > > WORDMAP;

vector<string> raw_para[100], query;
vector<set<string> > set_para[100];
//WORDMAP wordmap;
typedef map<string, int> WORD_ID;
typedef vector<pair<int, int> > WORD_DOC;
WORD_ID word_id;
WORD_DOC word_doc[100000];
//set<pair<int, int> > init_set;

void to_set(vector<string> &raw_para, vector<set<string> > &set_para) {
	for (vector<string>::iterator it = raw_para.begin(); it != raw_para.end(); it++) {
		string line = *it, buf;
		set<string> tmp_set;
		int len = line.size();
		for (int i = 0; i < len; i++)
			line[i] = isalpha(line[i]) ? tolower(line[i]) : ' ';
		stringstream ss(line);
		while (ss >> buf)
			tmp_set.insert(buf);
		set_para.push_back(tmp_set);
	}
}

void my_set_union(WORD_DOC::iterator begin1, WORD_DOC::iterator end1, WORD_DOC::iterator begin2, WORD_DOC::iterator end2, WORD_DOC &new_set) {
	while (begin1 != end1 && begin2 != end2) {
		if (*begin1 < *begin2) {
			new_set.push_back(*begin1);
			begin1++;
		}
		else if (*begin1 > *begin2) {
			new_set.push_back(*begin2);
			begin2++;
		}
		else {
			new_set.push_back(*begin1);
			begin1++;
			begin2++;
		}
	}
	while (begin1 != end1) {
		new_set.push_back(*begin1);
		begin1++;
	}
	while (begin2 != end2) {
		new_set.push_back(*begin2);
		begin2++;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n_para, cnt = 0;
	string line;
	getline(cin, line);
	stringstream ss0(line);
	ss0 >> n_para;
	while (getline(cin, line)) {
		if (line[0] == '*') {
			cnt++;
			if (cnt == n_para)
				break;
			else
				continue;
		}
		raw_para[cnt].push_back(line);
	}
	//cout << "Got raw_para: " << (double)clock() / CLOCKS_PER_SEC << "\n";
	for (int i = 0; i < n_para; i++)
		to_set(raw_para[i], set_para[i]);
	//cout << "Converted raw_para to set_para: " << (double)clock() / CLOCKS_PER_SEC << "\n";
	int n_query;
	getline(cin, line);
	stringstream ss(line);
	ss >> n_query;
	string tmp_str;
	int curr_word_id = 0;
	while (getline(cin, line)) {
		query.push_back(line);
		stringstream ss1(line);
		while (ss1 >> tmp_str)
			if (strchr("AON", tmp_str[0]) == nullptr && !word_id.count(tmp_str)) {
				//wordmap.insert(pair<string, set<pair<int, int> > >(tmp_str, init_set));
				word_id[tmp_str] = curr_word_id++;
			}
	}
	//cout << "Constructed vocabulary: " << (double)clock() / CLOCKS_PER_SEC << "\n";
	int n_word = word_id.size();
	for (int i = 0; i < n_para; i++) {
		int len = set_para[i].size();
		for (int j = 0; j < len; j++)
			for (WORD_ID::iterator it = word_id.begin(); it != word_id.end(); it++)
				if (set_para[i][j].count(it->first))
					word_doc[it->second].push_back(pair<int, int>(i, j));
	}
	//cout << "Constructed vocab buckets: " << (double)clock() / CLOCKS_PER_SEC << "\n";
	for (vector<string>::iterator it = query.begin(); it != query.end(); it++) {
		string a, b, cmd;
		stringstream ss(*it);
		if (it->find(' ') == string::npos) {	// A
												//continue;
			ss >> a;
			int ida = word_id[a];
			WORD_DOC &ref_map = word_doc[ida];
			//set<pair<int, int> > &ref_set = wordmap[a];
			if (!ref_map.empty()) {
				WORD_DOC::iterator iw = ref_map.begin();
				int first_article = iw->first;
				int id_article = iw->first;
				for (; iw != ref_map.end(); iw++) {
					if (iw->first != id_article && iw->first != first_article) {
						cout << "----------\n";
						id_article = iw->first;
					}
					cout << raw_para[iw->first][iw->second] << "\n";
				}
			}
			else
				cout << "Sorry, I found nothing.\n";
		}
		else if ((*it)[0] != 'N') {
			ss >> a >> cmd >> b;
			if (cmd[0] == 'A') {	// A AND B
									//continue;
				int first_article = -1;
				bool printed = false;
				int ida = word_id[a], idb = word_id[b];
				WORD_DOC &ref_a = word_doc[ida], &ref_b = word_doc[idb];
				WORD_DOC::iterator ia = ref_a.begin(), ib = ref_b.begin();
				//set<pair<int, int> > &ref_a = wordmap[a], &ref_b = wordmap[b];
				//set<pair<int, int> >::iterator ia = ref_a.begin(), ib = ref_b.begin();
				while (ia != ref_a.end() && ib != ref_b.end()) {
					if (ia->first < ib->first) ia++;
					else if (ia->first > ib->first) ib++;
					else {
						int first = ia->first;
						if (first_article < 0)
							first_article = first;
						else
							cout << "----------\n";
						WORD_DOC unn;
						WORD_DOC::iterator enda = upper_bound(ref_a.begin(), ref_a.end(), pair<int, int>(first, 1500)),
							endb = upper_bound(ref_b.begin(), ref_b.end(), pair<int, int>(first, 1500));
						my_set_union(ia, enda, ib, endb, unn);
						if (!unn.empty()) {
							printed = true;
							for (WORD_DOC::iterator itmp = unn.begin(); itmp != unn.end(); itmp++)
								cout << raw_para[itmp->first][itmp->second] << "\n";
						}
						ia = enda, ib = endb;
					}
				}
				if (!printed)
					cout << "Sorry, I found nothing.\n";
			}
			else {	// A OR B
					//continue;
				int ida = word_id[a], idb = word_id[b];
				WORD_DOC &ref_a = word_doc[ida], &ref_b = word_doc[idb];
				WORD_DOC print_map;
				my_set_union(ref_a.begin(), ref_a.end(), ref_b.begin(), ref_b.end(), print_map);
				if (!print_map.empty()) {
					WORD_DOC::iterator ip = print_map.begin();
					int first_article = ip->first;
					int id_article = ip->first;
					for (; ip != print_map.end(); ip++) {
						if (ip->first != id_article && ip->first != first_article) {
							cout << "----------\n";
							id_article = ip->first;
						}
						cout << raw_para[ip->first][ip->second] << "\n";
					}
				}
				else
					cout << "Sorry, I found nothing.\n";
			}
		}
		else {	// NOT A
				//continue;
			ss >> cmd >> a;
			int ida = word_id[a];
			WORD_DOC &ref_set = word_doc[ida];
			set<int> print_set;
			for (int i = 0; i < n_para; i++)
				print_set.insert(i);
			for (WORD_DOC::iterator it = ref_set.begin(); it != ref_set.end(); it++)
				if (print_set.count(it->first))
					print_set.erase(it->first);
			if (!print_set.empty()) {
				set<int>::iterator iw = print_set.begin();
				const int first_article = *iw;
				for (; iw != print_set.end(); iw++) {
					if (*iw != first_article)
						cout << "----------\n";
					for (vector<string>::iterator iv = raw_para[*iw].begin(); iv != raw_para[*iw].end(); iv++)
						cout << *iv << "\n";
				}
			}
			else
				cout << "Sorry, I found nothing.\n";
		}
		cout << "==========\n";
	}
	//cout << "End: " << (double)clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}