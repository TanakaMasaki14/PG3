#include <list>
#include <vector>
#include <iostream>

void Print(std::list<std::vector<char>> list)
{
	for (auto itr = list.begin(); itr != list.end(); itr++)
	{
		for (auto itr2 = itr->begin(); itr2 != itr->end(); itr2++)
		{
			std::cout << *itr2;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<char> VectorPushBackChar(const char* str) {
	std::vector<char> anser;
	for (int i = 0; str[i] != '\0'; i++) {
		anser.push_back(str[i]);
	};

	return anser;
}

using namespace std;

void main()
{
	list<vector<char>>stations;
	stations.push_back(VectorPushBackChar("Tokyo"));
	stations.push_back(VectorPushBackChar("Kanda"));
	stations.push_back(VectorPushBackChar("Akihabara"));
	stations.push_back(VectorPushBackChar("Okachimachi"));
	stations.push_back(VectorPushBackChar("Ueno"));
	stations.push_back(VectorPushBackChar("Uguisudani"));
	stations.push_back(VectorPushBackChar("Nippori"));
	stations.push_back(VectorPushBackChar("Tabata"));
	stations.push_back(VectorPushBackChar("Komagome"));
	stations.push_back(VectorPushBackChar("Sugamo"));
	stations.push_back(VectorPushBackChar("Otsuka"));
	stations.push_back(VectorPushBackChar("Ikebukuro"));
	stations.push_back(VectorPushBackChar("Mejiro"));
	stations.push_back(VectorPushBackChar("Takadanobaba"));
	stations.push_back(VectorPushBackChar("Shin-Okubo"));
	stations.push_back(VectorPushBackChar("Shinjuku"));
	stations.push_back(VectorPushBackChar("Yoyogi"));
	stations.push_back(VectorPushBackChar("Harajuku"));
	stations.push_back(VectorPushBackChar("Shibuya"));
	stations.push_back(VectorPushBackChar("Ebisu"));
	stations.push_back(VectorPushBackChar("Meguro"));
	stations.push_back(VectorPushBackChar("Gotanda"));
	stations.push_back(VectorPushBackChar("Osaki"));
	stations.push_back(VectorPushBackChar("Shinagawa"));
	stations.push_back(VectorPushBackChar("Tamachi"));
	stations.push_back(VectorPushBackChar("Hamamatsucho"));
	stations.push_back(VectorPushBackChar("Shimbashi"));
	stations.push_back(VectorPushBackChar("Yurakucho"));

	cout << "1970" << endl;
	cout << endl;

	Print(stations);

	auto itr = stations.begin();
	while (VectorPushBackChar("Tabata") != *itr)itr++;
	itr = stations.insert(itr, VectorPushBackChar("Nishi-Nippori"));

	cout << "1971" << endl;
	cout << endl;

	Print(stations);

	itr = stations.begin();
	while (VectorPushBackChar("Tamachi") != *itr)itr++;
	itr = stations.insert(itr, VectorPushBackChar("Takanawa Gateway"));

	cout << "2020" << endl;
	cout << endl;

	Print(stations);
}