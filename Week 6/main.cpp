// main.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고 
// 마지막 평균 결과 점수를 계산하는 프로그램
#include <algorithm>
#include <fstream> // 파일 읽기 위해
#include <iostream>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using namespace std;

int main(void) {
	ifstream student_file("grades.txt");

	Student_info std;
	string::size_type maxlen = 0;

	vector<Student_info> did, didnt;

	while (read(student_file, std)) {
		// cin을 사용하면 직접 사용자 입력만 받을 수 있다
		// student_file은 ifstream이기에 파일 입력 받기 가능
		maxlen = max(maxlen, std.name.size());
		if (did_all_hw(std))
			did.push_back(std);
		else
			didnt.push_back(std);

		// 두 집단의 데이터가 있는지 각각
		//확인하여 분석할 필요가 있는지 확인
		if (did.empty()) {
			cout << "No student did all homework!" << endl;
			return 1; // 오류코드 
		}
		if (didnt.empty()) {
			cout << "All student did all homework!" << endl;
		}
		return 0;
	}
}
