#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n = 0;

//white paper and blue paper
int wPaper = 0;
int bPaper = 0;


void getPaperNum(vector < vector<bool>> paper) {


	if (paper.size() == 1) {
		if (paper[0][0] == true) bPaper++;
		if (paper[0][0] == false) wPaper++;
	}
	else {
		bool isOneColor = true;
		bool firstColor = paper[0][0];

		//paper이 한 색인지 판단
		for (vector<bool> bs : paper) {
			for (bool b : bs) {
				if (firstColor != b) {
					isOneColor = false;
					break;
				}
			}
		}
		//한 색일 경우
		if (isOneColor) {
			if (paper[0][0] == true) bPaper++;
			if (paper[0][0] == false) wPaper++;
		}
		//다른 색 일 경우
		else {
			vector<vector<bool>> paperZero;
			//one해야하는데 오타 ㅎ
			vector<vector<bool>> paperTwo;
			vector<vector<bool>> paperThree;
			vector<vector<bool>> paperFour;
			//만약 나눠야하면 4개로 나눠서 재귀
			if (isOneColor == false) {
				for (int i = 0; i < paper.size() / 2; i++) {
					paperZero.push_back(vector<bool>());
					paperTwo.push_back(vector<bool>());
					paperThree.push_back(vector<bool>());
					paperFour.push_back(vector<bool>());
					for (int k = 0; k < paper.size() / 2; k++) {
						paperZero[i].push_back(paper[i][k]);
						paperTwo[i].push_back(paper[i][k + paper.size() / 2]);
						paperThree[i].push_back(paper[i + paper.size() / 2][k]);
						paperFour[i].push_back(paper[i + paper.size() / 2][k + paper.size() / 2]);
					}
				}

				getPaperNum(paperZero);
				getPaperNum(paperFour);
				getPaperNum(paperThree);
				getPaperNum(paperTwo);
			}
		}
	}

}


int main() {

	//입출력 향상
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	//n을 입력
	cin >> n;

	vector<vector<bool>> paper;

	for (int i = 0; i < n; i++) {
		paper.push_back(vector<bool>());
		for (int k = 0; k < n; k++) {
			bool a;
			cin >> a;
			paper[i].push_back(a);
		}
	}

	//nxn paper 완성
	getPaperNum(paper);
		//출력
	cout << wPaper << "\n" << bPaper;
}

