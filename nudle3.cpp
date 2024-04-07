#include <iostream>
#include <typeinfo>
using namespace std;

int total(int *total_add, int cost) { 
	*total_add = *total_add + cost;
	return *total_add;
}

int main() {
	string menu[] = { "�Ϲ� ���", "��ġ ���", "ġ�� ���", "�� ���", "�� ���� ���" };
	int prices[] = { 3500, 4000, 4200, 4300, 4500 };
	int total_cost = 0;

	while (true) {
		int nudle;
		cout << "***** ������ ��� ���Կ� ���� ���� ȯ���մϴ�. *****" << endl;
		for (int i=0; i < sizeof(menu) / sizeof(string) ; i++) {
			cout << i + 1 << ". " << menu[i] << "(" << prices[i] << ")" << endl;
		}
		cout << "�����Ͻ� ��� ��ȣ�� �Է����ּ���(����� 0): ";
		cin >> nudle;

		if (cin.fail()) {
			cout << "���ڷ� �Է��ϼ���.\n\n";
			cin.clear();
			cin.ignore();
			continue;
		}

		if (nudle == 0) {
			cout << "�� ������ " << total_cost << "�� �Դϴ�.\n";
			cout << "�ֹ��� �����մϴ�.\n\n";
			break;
		}
		else if (nudle > 5) {
			cout << "����� �� ���ڸ� �Է��� �ּ���.";
			continue;
		}

		string flag;
		string flag_array[] = { "Y", "N" };
		int index = nudle - 1;
		cout << menu[index] << "��(��) �����Ͻðڽ��ϱ�?(Y/N) ";
		cin >> flag;
		auto it = find(begin(flag_array), end(flag_array), flag);
		if (it == end(flag_array)) {
			cout << "Y/N �߿� �Է����ּ���.\n\n";
			continue;
		}
		if (flag == "N") {
			continue;
		}

		int count = 0;
		cout << "�����Ͻ� ��� ������ �Է��� �ּ��� : ";
		cin >> count;

		if (cin.fail()) {
			cout << "���ڷ� �Է����ּ���. �ʱ�ȭ������ ���ư��ϴ�.\n\n";
			cin.clear();
			cin.ignore();
			continue;
		}

		cout << menu[index] << " " << count << "���� �����ϼ̽��ϴ�.";
		int price = prices[index] * count;
		cout << "������ " << price << "�� �Դϴ�.\n\n";

		total(&total_cost, price);

	}


}
	