#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>



using namespace std;

void countWordsAndNumbersInTextFile(const string& filename, int& wordCount, int& numberCount, string& numbers, string& words, vector<string>& lines) {
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return;
	}

	string line;
	wordCount = 0;
	numberCount = 0;

	while (getline(inputFile, line)) {
		cout << line << endl;
		stringstream ss(line);
		string token;
		lines.push_back(line);
		while (ss >> token) {
			// Remove punctuations from the token (optional)
			// token.erase(remove_if(token.begin(), token.end(), ::ispunct), token.end());


			bool hasDigits = false;

			for (char c : token) {
				if (isdigit(c)) {
					hasDigits = true;
				}

			}

			if (!token.empty()) {
				if (hasDigits) {
					numberCount++;
					numbers += token + " ";
				}
				else {
					wordCount++;
					words += token + " ";
				}
			}
		}
	}

	inputFile.close();
}

//출력
void PirntLines(const vector<string>& lines)
{
	/*for (int i = 0; i < lines.size(); ++i) {
	   for (int j = 0; j < lines[i].size(); ++j) {
		  cout << lines[i][j];
	   }
	   cout << endl;
	}*/

	for (const string& line : lines) {   //auto도 가능
		for (const char& characters : line) { //auto도 가능
			cout << characters;
		}
		cout << endl;
	}
}   //출력

//동일한 간격으로 특정 문자를 일정 개수 삽입하기
void PirntLines_Press_E(vector<string>& lines) {
	for (string& line : lines) {
		int i = 0;
		int length = line.length(); // 문자열의 길이를 미리 저장
		while (i < length) {
			if (i == 3) {
				line.insert(i, "@@"); // 3번째 문자 뒤에 "@@" 삽입
				//i += 2; // "@@"을 추가했으므로 2를 더해줌
				length = line.length(); // 문자열의 길이가 변했으므로 업데이트
			}
			else if (i > 3 && i % 5 == 3) {
				line.insert(i, "@@"); // 3번째 문자 뒤에 "@@" 삽입
				//i += 2; // "@@"을 추가했으므로 2를 더해줌
				length = line.length(); // 문자열의 길이가 변했으므로 업데이트
			}

			cout << line[i];
			++i;
		}
		cout << endl;
	}
}

// @@를 삭제하는 함수
void RemoveAtMarks(vector<string>& lines) {
	for (string& line : lines) {
		int i = 0;
		while (i < line.length()) {
			if (line[i] == '@' && i + 1 < line.length() && line[i + 1] == '@') {
				line.erase(i, 2); // '@@'를 삭제
			}
			else {
				cout << line[i];
				++i;
			}
		}
		cout << endl;
	}
}

//문자 내부의 특정 문자를 다른 문자로 바꾸기
void PirntLines_Press_G(vector<string>& lines)
{
	char a, b;
	cout << "바뀔 문자를 넣어주세요 :";
	cin >> a;

	cout << "바꿀 문자를 넣어주세요 :";
	cin >> b;

	// for (int i = 0; i < lines.size(); ++i) {
	//     for (int j = 0; j < lines[i].size(); ++j) {
	//         if (lines[i][j] == a) {
	//             lines[i][j] = b;
	//         }
	//         cout << lines[i][j];
	//     }
	//     cout << endl;
	// }

	for (string& line : lines) {   //auto도 가능
		for (char& characters : line) { //auto도 가능
			if (characters == a) {
				characters = b;


			}
			cout << characters;
		}
		cout << endl;
	}
}

void swap(char& a, char& b) {
	char temp;
	temp = a;
	a = b;
	b = temp;
}
void PirntLines_Press_PLUS(vector<string>& lines)
{
	for (int i = 0; i < lines.size(); ++i) {
		string tempString;
		for (int j = 0; j < lines[i].size(); ++j) {
			if (isdigit(lines[i][j])) {
				int num = atoi(&lines[i][j]);
				char temp[20];
				itoa(num, temp, 10);
				for (int k = 0; temp[k] != NULL; ++k)
				{
					j++;
					//lines[i][j]  = temp[k];
				}
				j--;
				++num;
				itoa(num, temp, 10);
				for (int k = 0; temp[k] != NULL; ++k)
					tempString.push_back(temp[k]);
			}
			else
			{
				tempString.push_back(lines[i][j]);
			}
		}
		lines[i] = tempString;
	}
}

void PirntLines_Press_Minus(vector<string>& lines)
{
	for (int i = 0; i < lines.size(); ++i) {
		string tempString;
		for (int j = 0; j < lines[i].size(); ++j) {
			if (isdigit(lines[i][j])) {
				int num = atoi(&lines[i][j]);
				char temp[20];
				itoa(num, temp, 10);
				for (int k = 0; temp[k] != NULL; ++k)
				{
					j++;
					//lines[i][j]  = temp[k];
				}
				j--;
				if (num > 0)
				{
					--num;
				}
				itoa(num, temp, 10);
				for (int k = 0; temp[k] != NULL; ++k)
					tempString.push_back(temp[k]);
			}
			else
			{
				tempString.push_back(lines[i][j]);
			}
		}
		lines[i] = tempString;
	}
}



void PirntLines_Press_F(vector<string>& lines)
{

	for (int i = 0; i < lines.size(); ++i) {
		for (int j = 0; j < lines[i].size(); j += 3) {
			if (j + 2 < lines[i].size()) {
				swap(lines[i][j], lines[i][j + 2]);
			}
			else if (j + 2 > lines[i].size()) {
				swap(lines[i][j], lines[i][j + 1]);
			}

		}

	}


}

vector<string> DivideIntoSegments(const string& lines, size_t segmentLength) {
	vector<string> segments;
	size_t startPos = 0;

	while (startPos < lines.size()) {
		string segment = lines.substr(startPos, segmentLength);
		reverse(segment.begin(), segment.end()); // Reverse the segments
		segments.push_back(segment);
		startPos += segmentLength;
	}
	return segments;
}



int main() {
	string filename = "test.txt"; // 텍스트 파일의 경로와 이름을 지정해주세요.
	int wordCount, numberCount;
	string numbers, words;
	vector <string> lines;
	bool toggle_E = false;
	countWordsAndNumbersInTextFile(filename, wordCount, numberCount, numbers, words, lines);
	char order;
	while (true) {
		cout << "키보드를 입력하세요: ";
		cin >> order;

		switch (order)
		{
		case 'a':
			cout << "2번 문제 출력!!" << endl;
			cout << "Total number of words in the file: " << wordCount << endl;
			cout << "Total number of numbers in the file: " << numberCount << endl;

			cout << "Numbers: " << numbers << endl;
			cout << "Words: " << words << endl;
			break;
		case 'd':
			for (auto& line : lines) {
				reverse(line.begin(), line.end());
			}
			PirntLines(lines);
			break;
		case 'e':
			toggle_E = !toggle_E;
			if (toggle_E) {
				PirntLines_Press_E(lines);
			}
			else
				RemoveAtMarks(lines);
			break;
		case 'g':
			PirntLines_Press_G(lines);
			break;
		case 'f':
		{
			vector<vector<string>> vecvecs;

			for (const string& originalStr : lines) {
				vector<string> segments = DivideIntoSegments(originalStr, 3);
				vecvecs.push_back(segments);

			}
			for (const vector<string>& segments : vecvecs) {
				size_t strSize = segments.size();
				int cnt = 0;
				for (const string& segment : segments) {
					cout << segment;
					cnt++;
					if (strSize != cnt) cout << "@@";
				}
				cout << endl;
			}


			//PirntLines_Press_F(lines); 이거 두개도 사용 가능~
			//PirntLines_Press_E(lines);
			break;
		}
		case 'h':
			for (auto& line : lines) {
				int startPos = 0;
				int endPos = line.size() - 1;
				int prevStartPos = 0;
				string same_word;
				while (true) {
					if (line[startPos] == line[endPos]) {
						if (!same_word.empty()) {
							if (startPos != prevStartPos + 1) {
								same_word.clear();
							}
						}
						same_word += line[startPos];
						prevStartPos = startPos;
					}
					startPos++;
					endPos--;
					if (startPos >= endPos) {
						break;
					}

				}
				if (same_word.size() > 1) {
					cout << line << ": " << same_word << endl;
				}
				else
					cout << line << ":  " << "0" << endl;
			}
			break;
		case '+':
			PirntLines_Press_PLUS(lines);
			PirntLines(lines);
			break;

		case '-':
			PirntLines_Press_Minus(lines);
			PirntLines(lines);
			break;
		}


	}



	return 0;
}