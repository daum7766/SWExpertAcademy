#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
//set을 이용한 풀이
vector<int> solution(vector<string> operations) {
	multiset<int> mset;
	for (auto o : operations) {
		string a = o.substr(0, 1);//앞의 문자 확인
		int num = atoi(o.substr(2).c_str());//뒤의 숫자 확인
		//앞문자가 I(대문자 i) 라면 데이터 넣기
		if (a == "I") {
			mset.insert(num);
		}
		//I가 아니고 덱이 비어있지 않다면 최댓값 혹은 최솟값 제거
		else if (!mset.empty()) {
			if (num == 1)
				mset.erase(--mset.end());
			else
				mset.erase(mset.begin());
		}
	}
	//멀티셋이 비어있다면 0,0 반환
	if (mset.empty())
		return { 0 , 0 };
	else		//비어있지 않다면 최댓값 최솟값 반환
		return { *--mset.end() , *mset.begin() };
}
//deque을 이용한 풀이
vector<int> solution2(vector<string> operations) {
	vector<int> answer;
	deque<int> deq;//앞으로 데이터 꺼내기용
	for (auto o : operations)
	{
		string a = o.substr(0, 1);//앞의 문자 확인
		int num = atoi(o.substr(2).c_str());//뒤의 숫자 확인
		//앞문자가 I(대문자 i) 라면
		if (a == "I") {
			//데이터 넣기
			deq.push_back(num);
		}
		//I가 아니고 덱이 비어있지 않다면
		else if (!deq.empty())
		{
			//정렬 한번하기
			sort(deq.begin(), deq.end());
			if (num == 1)
				deq.pop_back();			//오름차순 정렬이므로 뒤에것을 제거
			else
				deq.pop_front();		//최소값을 빼야하므로 앞에서 제거
		}
	}
	if (deq.empty())
	{
		//큐가 비어있다면 0,0 넣기
		answer.push_back(0);
		answer.push_back(0);
	}
	else
	{
		//큐가 비어있지 않다면 정렬후 값넣기
		sort(deq.begin(), deq.end());
		answer.push_back(deq.back());
		answer.push_back(deq.front());
	}

	return answer;
}

int main()
{
	//vector<string> oper = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
	vector<string> oper = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
	vector<int> result = solution(oper);
	for (auto r : result)
	{
		cout << r << endl;
	}
	return 0;
}
