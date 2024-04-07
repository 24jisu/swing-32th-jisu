#include <iostream>
#include <typeinfo>
using namespace std;

int total(int *total_add, int cost) { 
	*total_add = *total_add + cost;
	return *total_add;
}

int main() {
	string menu[] = { "일반 라면", "김치 라면", "치즈 라면", "떡 라면", "떡 만두 라면" };
	int prices[] = { 3500, 4000, 4200, 4300, 4500 };
	int total_cost = 0;

	while (true) {
		int nudle;
		cout << "***** 슈니의 라면 가게에 오신 것을 환영합니다. *****" << endl;
		for (int i=0; i < sizeof(menu) / sizeof(string) ; i++) {
			cout << i + 1 << ". " << menu[i] << "(" << prices[i] << ")" << endl;
		}
		cout << "구매하실 라면 번호를 입력해주세요(종료는 0): ";
		cin >> nudle;

		if (cin.fail()) {
			cout << "숫자로 입력하세요.\n\n";
			cin.clear();
			cin.ignore();
			continue;
		}

		if (nudle == 0) {
			cout << "총 가격은 " << total_cost << "원 입니다.\n";
			cout << "주문을 종료합니다.\n\n";
			break;
		}
		else if (nudle > 5) {
			cout << "제대로 된 숫자를 입력해 주세요.";
			continue;
		}

		string flag;
		string flag_array[] = { "Y", "N" };
		int index = nudle - 1;
		cout << menu[index] << "을(를) 구매하시겠습니까?(Y/N) ";
		cin >> flag;
		auto it = find(begin(flag_array), end(flag_array), flag);
		if (it == end(flag_array)) {
			cout << "Y/N 중에 입력해주세요.\n\n";
			continue;
		}
		if (flag == "N") {
			continue;
		}

		int count = 0;
		cout << "구매하실 라면 개수를 입력해 주세요 : ";
		cin >> count;

		if (cin.fail()) {
			cout << "숫자로 입력해주세요. 초기화면으로 돌아갑니다.\n\n";
			cin.clear();
			cin.ignore();
			continue;
		}

		cout << menu[index] << " " << count << "개를 구매하셨습니다.";
		int price = prices[index] * count;
		cout << "가격은 " << price << "원 입니다.\n\n";

		total(&total_cost, price);

	}


}
	